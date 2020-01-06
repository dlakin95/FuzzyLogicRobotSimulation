
// _INCLUDES_ DataBase.cpp -------------------------------------------------------------------------------------------------------------------
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"database.hpp"
#include"databasecategory.hpp"
#include"databaseobjectsreadfilecontainer.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"
#include"getparamrules.hpp"
#include"setparamrules.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBase -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool DataBase::optionality[];
constexpr bool DataBase::paramIsObject[];

// _CONSTRUCTORS_ DataBase.cpp
DataBase::DataBase() : DataBaseCategory(DATABASE_OBJECT_DATABASE, NUMB_OF_DATABASE_PARAMETERS){

}

// _DESTRUCTORS_ DataBase.cpp
DataBase::~DataBase(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);

}

// _PRIVATE_METHODS_ DataBase.cpp


// _PUBLIC_METHODS_ DataBase.cpp
const QString DataBase::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, DataBase, DataBaseCategory);
    switch(static_cast<DatabaseParameters>(param)){
    default:
        return QString();
    }
}

QString DataBase::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,DataBase, DataBaseCategory);
    DB_OBJECT_IS_INITIALIZED_QSTRING(DataBase);
    switch (static_cast<DatabaseParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool DataBase::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, DataBase, DataBaseCategory);
    DB_OBJECT_IS_INITIALIZED_BOOL(DataBase);
    switch (static_cast<DatabaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool DataBase::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,DataBase, DataBaseCategory);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<DatabaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBase);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBase);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(DataBase);
    return true;

}

bool DataBase::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,DataBase, DataBaseCategory);
    bool ret = false;
    switch (static_cast<DatabaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBase);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBase);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool DataBase::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, DataBase, DataBaseCategory);
    bool ret = false;
    switch (static_cast<DatabaseParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat DataBase::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // Objects
    /*
    case DATA_BASE_OBJECTS:
        */
    default:
        break;
    }
    return DataBaseCategory::checkParamAndProccess(param, value, dbObjectParamRules);
}


/*void DataBase::set_dataBaseGeneralInformation(DataBaseGeneralInformation* set){dataBaseGeneralInformation = set;}
DataBaseGeneralInformation* DataBase::get_dataBaseGeneralInformation(){return dataBaseGeneralInformation;}
//GET_SET_NDO_DEFINITION(DataBase, DataBaseGeneralInformation*, dataBaseGeneralInformation)
GET_DEFINITION(DataBase,DataBaseObject**, dataBaseObjects)
GET_DEFINITION(DataBase,uint, numbOfDataBaseObjects)*/
GET_DEFINITION(DataBase,DataBaseError, error)

void DataBase::readDataBaseFile(QFile& file){
    // Init
    DataBaseObject tempDataBaseObj(NUMB_OF_DATABASE_OBJECT_TYPES, 0); // Read DataBase Control Parameters purpose
    DataBaseObject* curDataBaseObj = &tempDataBaseObj;
    DataBaseObjectsReadFileContainer dbObjectReadFileContainer;

    QString tempParameterName;
    QString tempParameterValue;
    bool dataBaseReaded = false;

    //prepareToRead();
    // -------------------------------------------------------------------
    LOOP_VARIABLE_CONDITIONAL(!dataBaseReaded){
        // Clear tempParameterName and tempParameterValue
        tempParameterName = QString();
        tempParameterValue = QString();
        if((error = static_cast<DataBaseError>(curDataBaseObj->readParameter(tempParameterName, tempParameterValue, file))) != FILE_READ_NO_ERROR){    // Error Occurred
            DB_FILE_READ_ERROR(error);
        }
        // Check parameter name: First - Objects -> Then DataBase
        // Catch : Error, Last Category (Container empty to add to category), End of Base, End of General Information
        switch (curDataBaseObj->checkParamAndProccess(tempParameterName, tempParameterValue, &dbObjectReadFileContainer)){
        //case DATABASE_FILE_OPERATION_DB_GENERAL:
        case DATABASE_FILE_OPERATION_DB_INIT:
        {
            if(!dbObjectReadFileContainer.push(this)){  // NullPtr Catched
                DB_READ_ERROR(DATABASE_CREATE_OR_PUSH_TO_CONTAINER_ERROR);
            }
            SET_PTR_NDO(curDataBaseObj, dbObjectReadFileContainer.getLastObject()->dbObj);
        }
            break;
        case DATABASE_FILE_OPERATION_DB_CATEGORY:
        case DATABASE_FILE_OPERATION_DB_RECORD:
            if(!dbObjectReadFileContainer.push(new DataBaseObject(NUMB_OF_DATABASE_OBJECT_TYPES, 0))){  // NullPtr Catched
                DB_READ_ERROR(DATABASE_CREATE_OR_PUSH_TO_CONTAINER_ERROR);
            }
            SET_PTR_NDO(curDataBaseObj, dbObjectReadFileContainer.getLastObject()->dbObj);
            break;
         case DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE:
         {
            DataBaseObject* newObj = nullptr;
            uint newType = tempParameterValue.toUInt();
            if(!(newObj = curDataBaseObj->createObject(newType))){
                if(!(newObj = createObject(curDataBaseObj, newType))){
                    DB_READ_ERROR(DATABASE_CHANGE_OBJECT_TYPE_ERROR);
                }else{
                    if(newObj == this){
                        break;
                    }
                }
            }
             if(!dbObjectReadFileContainer.changeObjectType(newObj)){
                 DB_READ_ERROR(DATABASE_CHANGE_OBJECT_TYPE_ERROR);
             }
             SET_PTR_NDO(curDataBaseObj, dbObjectReadFileContainer.getLastObject()->dbObj);
         }
            break;
        /*case DATABASE_FILE_OPERATION_DB_END_GENERAL:
            if(!dbObjectReadFileContainer.checkLastObjectReadedProperly()){ // Fail Read
                DB_READ_ERROR(DATABASE_NOT_COMPLETE_OBJECT);
            }
            //if(!(dataBaseGeneralInformation = static_cast<DataBaseGeneralInformation*>(dbObjectReadFileContainer.pull()))){   // Error
              //  DB_READ_ERROR(DATABASE_PULL_FROM_CONTAINER_ERROR);
            //}
            SET_PTR_NDO(curDataBaseObj, &tempDataBaseObj);
            break;
            */
        case DATABASE_FILE_OPERATION_DB_END_CATEGORY:
        case DATABASE_FILE_OPERATION_DB_END_RECORD:
        {
            if(!dbObjectReadFileContainer.checkLastObjectReadedProperly()){ // Fail Read
                DB_READ_ERROR(DATABASE_NOT_COMPLETE_OBJECT);
            }
            SetParamRules paramRules;
            if(!dbObjectReadFileContainer.getSecondLastObject()){   // DataBase
                paramRules = {DB_GET_REAL_PARAM(DataBaseCategory, DATABASE_CATEGORY_OBJECTS), UINT_MAX, SET_PARAM_ACTION_ADD};
                DataBaseObject* tmpObject = nullptr;
                if(!(tmpObject = dbObjectReadFileContainer.pull()) || !setParam(&tmpObject, paramRules)){ // Fail while adding
                    DB_READ_ERROR(DATABASE_ADDING_NEW_OBJECT_ERROR);
                }
                SET_PTR_NDO(curDataBaseObj, &tempDataBaseObj);
            }else{
                DataBaseObjectsReadFileStat* tempDBObjStat = dbObjectReadFileContainer.getSecondLastObject();
                if(!(curDataBaseObj = dbObjectReadFileContainer.pull())){
                    DB_READ_ERROR(DATABASE_ADDING_NEW_OBJECT_ERROR);
                }
                GetParamRules getParamRules = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_PARAM_OBJECT_ID)};
                if(!curDataBaseObj->getParam(&tempDBObjStat->lastReadedParam, getParamRules) || !getParamRules.initialized){  // Fail
                    DB_READ_ERROR(DATABASE_ADDING_NEW_OBJECT_ERROR);
                }
                // _PH_
                paramRules = {tempDBObjStat->lastReadedParam, UINT_MAX, SET_PARAM_ACTION_ADD};
                // _BACK_ Dodać makra modyfikacji tablic bez zwracania wyniku
                if(!tempDBObjStat->dbObj->setParam(&curDataBaseObj, paramRules)){
                    DB_READ_ERROR(DATABASE_ADDING_NEW_OBJECT_ERROR);
                }
                SET_PTR_NDO(curDataBaseObj, tempDBObjStat->dbObj);
            }
        }
            break;
        case DATABASE_FILE_OPERATION_DB_PROCESSING:
            // Processing data
            break;
        case DATABASE_FILE_OPERATION_DB_END_BASE:
            dataBaseReaded = true;
            break;
        default:
            DB_READ_ERROR(DATABASE_UNKNOWN_PARAMETER_ERROR);
        }
    }
}

/*DataBaseObject* DataBase::createObject(){
    switch (obj->getObjectType()) {
    case DATABASE_OBJECT_GENERAL:
        return new DataBaseGeneralInformation(obj);
    case DATABASE_OBJECT_CATEGORY:
        return new DataBaseCategory(obj);
    default:
        return nullptr;
    }
}*/

/*void DataBase::prepareToRead(){

}*/


// ----------------------------------------------------------------------------------------------------------------------------------------------
