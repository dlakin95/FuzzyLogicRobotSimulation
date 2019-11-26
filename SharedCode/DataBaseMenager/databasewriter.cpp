#include "databasewriter.hpp"
#include<QFile>
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"DataBase/getparamrules.hpp"
#include"DataBase/databaseparams.hpp"
// _INCLUDES_ DataBaseWriter.cpp -------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseWriter -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseWriter.cpp
DataBaseWriter::DataBaseWriter(){

}

// _DESTRUCTORS_ DataBaseWriter.cpp
DataBaseWriter::~DataBaseWriter(){
    clearObjectStats();
}

// _PRIVATE_METHODS_ DataBaseWriter.cpp
bool DataBaseWriter::addObjectStat(DataBaseWriterObjectStat *newObjStat){
    ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseWriterObjectStat, currentObjectStats, numbOfCurrentObjectStats, newObjStat);
}

bool DataBaseWriter::removeObjectStat(){
    ARRAY_PULL_PTR_WITH_TEMP_PTR_VOID(DataBaseWriterObjectStat, currentObjectStats, numbOfCurrentObjectStats);
}

void DataBaseWriter::clearObjectStats(){
    ARRAY_CLEAR_PTR_WITH_TEMP_PTR(currentObjectStats, numbOfCurrentObjectStats);
}

bool DataBaseWriter::writeDataBase(DataBase *db, QFile& file){
    if(db)
        dataBase = db;
    else
        return false;
    if(!file.isOpen())
        return false;
    this->file = &file;
    // Start Processing
    initilize();    // Add DataBase as First Element
    if(error)
        return false;
    begin();    // Write DataBaseGeneralInformation
    if(error)
        return false;
    writeProcess();
    if(error)
        return false;
    end(); // End Base by EndOfBase marker + clear file variable pointer (set null, no delete)
    if(error)
        return false;
    return true;
}

void DataBaseWriter::initilize(){
    clearObjectStats();    
    if(!addObjectStat(new DataBaseWriterObjectStat(this, dataBase))){// Prepare first object (DataBase) to Read
        error = true;
        return;
    }
    //(*currentObjectStats)->maxParam = dataBase->get_numbOfDataBaseObjects();
}

bool DataBaseWriter::begin(){
    if(file->write((DATABASE_PARAM_NAME+"\n").toUtf8()) == -1)
        return false;
    return true;
}

void DataBaseWriter::writeProcess(){
    // Process Data
    bool stop = false;
    LOOP_VARIABLE_CONDITIONAL(!stop){
        switch(processData()){
        case DATABASE_FILE_OPERATION_DB_END_BASE:
            stop = true;
            break;
        case NUMB_OF_DATABASE_FILE_OPERATIONS:
            // Error
            error = true;
            stop = true;
        default:
            break;
        }
    }
}

DataBaseFileOperationStat DataBaseWriter::processData(){
    DataBaseWriterObjectStat* tempDbWriterObjStat = (*(currentObjectStats + numbOfCurrentObjectStats - 1));
    DataBaseFileOperationStat retStat = NUMB_OF_DATABASE_FILE_OPERATIONS;
    // If curParam is available
    if(tempDbWriterObjStat->curParam < tempDbWriterObjStat->maxParam){
        // Write Param (processParam function -  use FileableObject::writeParameterToFile function)
        if(!tempDbWriterObjStat->dbObj){ // Possible Next DataBase Object
            if(numbOfCurrentObjectStats == 1){  // Next DataBase Object
                retStat = DATABASE_FILE_OPERATION_DB_RECORD;
               // if(!addObjectStat(new DataBaseWriterObjectStat(this, (*(dataBase->get_dataBaseObjects() + tempDbWriterObjStat->curParam))))){
                //    return NUMB_OF_DATABASE_FILE_OPERATIONS;
               // }
                tempDbWriterObjStat->nextParam();
            }else{  // DataBase Error (More than one objects - NumbOfDBObjects informations are in first DataBaseWriterObjectStat)
                return NUMB_OF_DATABASE_FILE_OPERATIONS;
            }
        // ----------------------------------------------------------------------------------------
        }else{  // DataBase Object Next Param Proccessing ----------------------------------------
            retStat = DATABASE_FILE_OPERATION_DB_PROCESSING;
            if(!processParam(tempDbWriterObjStat)){ // False For Error
               return NUMB_OF_DATABASE_FILE_OPERATIONS;
            }
        } // ------------------------------------------------------------------------------

    }else{ // If Not Available (End Of Objects Processing) --------------------------------
        // DataBase End Proccessing  ------------------------------------------------------
        if(!tempDbWriterObjStat->dbObj){ // Possible DataBase End
            if(numbOfCurrentObjectStats == 1){  // DataBase End
                retStat = DATABASE_FILE_OPERATION_DB_END_BASE;
            }else{  // DataBase Error (More than one objects - NumbOfDBObjects informations are in first DataBaseWriterObjectStat)
                return NUMB_OF_DATABASE_FILE_OPERATIONS;
            }
        // ----------------------------------------------------------------------------------------
        }else{  // DataBase Object End Proccessing ----------------------------------------
            switch(static_cast<DatabaseObjectType>(tempDbWriterObjStat->dbObj->getObjectType())){
            //case DATABASE_OBJECT_GENERAL:
             //   retStat = endDataBaseGeneralInformation();
             //   break;
            case DATABASE_OBJECT_DATABASE:
                retStat = DATABASE_FILE_OPERATION_DB_END_BASE;
                break;
            case DATABASE_OBJECT_CATEGORY:
                retStat = endCategory();
                break;
            default:
                retStat = endRecord();
                break;
            }
            // Remove Last Object Stat
            if(!removeObjectStat()){
                return NUMB_OF_DATABASE_FILE_OPERATIONS;
            } // tempDbWriterObjStat is corrupted from now
        } // ------------------------------------------------------------------------------
    } //--------------------------------------------------------------------------------
    return retStat;
}

bool DataBaseWriter::processParam(DataBaseWriterObjectStat *dbObjStat){
    GetParamRules rules = {dbObjStat->curParam,dbObjStat->numbOfWriteForCurrentParam, false};
    if(!dbObjStat->dbObj->isParameterInitialized(dbObjStat->curParam)){
        if(!dbObjStat->dbObj->isParamOptional(dbObjStat->curParam)){
            // Error Occurred
            return false;
        }
    }else{
        // Write To File -----------------------------------
        if(!dbObjStat->dbObj->isParamObject(rules.param)){  // If Not An Object
            if(!dbObjStat->dbObj->writeParameterToFile(*file, rules)){  // Error Occured
                return false;
            }
        }else{  // If Param Is An Object, add and return true
            DataBaseObject* tempDbObj = nullptr;
            dbObjStat->dbObj->getParam(static_cast<void*>(&tempDbObj), rules);
            if(!addObjectStat(new DataBaseWriterObjectStat(this, tempDbObj))){
                return false;
            }
        }
    }
    // ---------------------------------------
    if(rules.nextAvailable){
        dbObjStat->addNextWriteForCurrentParam();    // Next Index (The same Param)
    }else{
        dbObjStat->nextParam();
        dbObjStat->numbOfWriteForCurrentParam = 0;  // Next Param + Reset Index
    }
    return true;
}

DataBaseFileOperationStat DataBaseWriter::endRecord(){
    if(file->write((DATABASE_END_OF_RECORD_PARAM_NAME+"\n").toUtf8()) == -1)
        return NUMB_OF_DATABASE_FILE_OPERATIONS;
    return DATABASE_FILE_OPERATION_DB_END_RECORD;
}

DataBaseFileOperationStat DataBaseWriter::endCategory(){
    if(file->write((DATABASE_END_OF_CATEGORY_PARAM_NAME+"\n").toUtf8()) == -1)
        return NUMB_OF_DATABASE_FILE_OPERATIONS;
    return DATABASE_FILE_OPERATION_DB_END_CATEGORY;
}


/*
DataBaseFileOperationStat DataBaseWriter::endDataBaseGeneralInformation(){
    if(file->write((DATABASE_END_OF_GENERAL_PARAM_NAME+"\n").toUtf8()) == -1)
        return NUMB_OF_DATABASE_FILE_OPERATIONS;
    return DATABASE_FILE_OPERATION_DB_END_GENERAL;
}
*/
bool DataBaseWriter::end(){
    if(file->write((DATABASE_END_OF_BASE_PARAM_NAME+"\n").toUtf8()) == -1)
        return false;
    return true;
}


// _PUBLIC_METHODS_ DataBaseWriter.cpp
GET_DEFINITION(DataBaseWriter, bool, error);

DataBaseFileOperationStat DataBaseWriter::beginRecord(){
    if(file->write((DATABASE_RECORD_PARAM_NAME+"\n").toUtf8()) == -1)
        return NUMB_OF_DATABASE_FILE_OPERATIONS;
    return DATABASE_FILE_OPERATION_DB_RECORD;
}

DataBaseFileOperationStat DataBaseWriter::beginCategory(){
    if(file->write((DATABASE_CATEGORY_PARAM_NAME+"\n").toUtf8()) == -1)
        return NUMB_OF_DATABASE_FILE_OPERATIONS;
    return DATABASE_FILE_OPERATION_DB_CATEGORY;
}
/*
DataBaseFileOperationStat DataBaseWriter::beginDataBaseGeneralInformation(){
    const QString str = DATABASE_GENERAL_PARAM_NAME + "\n";
    if(file->write((DATABASE_GENERAL_PARAM_NAME + "\n").toUtf8()) == -1)
        return NUMB_OF_DATABASE_FILE_OPERATIONS;
    return DATABASE_FILE_OPERATION_DB_GENERAL;
}
*/




// ----------------------------------------------------------------------------------------------------------------------------------------------
