#ifndef DATABASEWRITER_HPP
#define DATABASEWRITER_HPP
// _INCLUDES_ DataBaseWriter.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"GeneralPurposeMacros/filemenegmentmacros.hpp"
#include<QObject>
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"
#include"DataBase/databaseobjecttype.hpp"
#include"DataBase/databaseobject.hpp"
#include"DataBase/database.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseWriter.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBase;
class DataBaseObject;
class DataBaseGeneralInformation;
class DataBaseCategory;
class DataBaseWriter;
class QFile;
class DataBaseWriterObjectStat;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------


// _CLASSDEF_ DataBaseWriter -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseWriter{
public:
    // _CONSTRUCTORS_ DataBaseWriter.hpp
    DataBaseWriter();
    // _DESTRUCTORS_ DataBaseWriter.hpp
    ~DataBaseWriter();
private:
    // _PRIVATE_MEMBERS_ DataBaseWriter.hpp
    QFile *file = nullptr;
    DataBase* dataBase = nullptr;

    // Current Objects Array
    DataBaseWriterObjectStat** currentObjectStats = nullptr;
    uint numbOfCurrentObjectStats = 0;

    bool error = false;

public:
    // _PUBLIC_MEMBERS_ DataBaseWriter.hpp

private:
    // _PRIVATE_METHODS_ DataBaseWriter.hpp

    // DataBaseWriterObjectStat Functions ---------------------------------------------------
    // Add and Remove only Last Index
    bool addObjectStat(DataBaseWriterObjectStat*);
    bool removeObjectStat();
    void clearObjectStats();

    // ------------------------------------------------------------------------------------------

    // _DONT_MODIFY_ Write File Basic Functions ---------------------------------------------------
    bool begin();   // Start Writing
    void initilize();
    void writeProcess();
    DataBaseFileOperationStat processData();
    bool processParam(DataBaseWriterObjectStat*);
    DataBaseFileOperationStat endCategory();
    DataBaseFileOperationStat endRecord();
    bool end();     // End Writing
    // -------------------------------------------------------------------------------------------
public:
    // _PUBLIC_METHODS_ DataBaseWriter.hpp
    GET_DECLARATION(bool, error);

    bool writeDataBase(DataBase*, QFile&);
    DataBaseFileOperationStat beginDataBaseGeneralInformation();
    DataBaseFileOperationStat beginCategory();
    DataBaseFileOperationStat beginRecord();

};

class DataBaseWriterObjectStat{
public:
    DataBaseWriterObjectStat(DataBaseWriter* objForBegin, DataBaseObject* dbObj) : dbObj(dbObj){
        if(dbObj && objForBegin){
            switch(static_cast<DatabaseObjectType>(dbObj->getObjectType())){
            //case DATABASE_OBJECT_GENERAL:
                //objForBegin->beginDataBaseGeneralInformation();
               // break;
            case DATABASE_OBJECT_DATABASE:
                break;
            case DATABASE_OBJECT_CATEGORY:
                objForBegin->beginCategory();
                break;
            default:
                objForBegin->beginRecord();
                break;
            }
            maxParam = dbObj->getNumbOfParameters();
         }
    }

    ~DataBaseWriterObjectStat(){}

    DataBaseObject* dbObj = nullptr;
    uint curParam = 0;
    uint maxParam = 0;
    uint numbOfWriteForCurrentParam = 0;

    void nextParam(){curParam++; numbOfWriteForCurrentParam = 0;}
    void addNextWriteForCurrentParam(){numbOfWriteForCurrentParam++;}
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEWRITER
