#ifndef DATABASEMENAGER_HPP
#define DATABASEMENAGER_HPP

// _MACROS_ DataBaseMenager.hpp ------------------------------------------------------------------------------------------------------------------------------------
#ifndef DATABASE_MENAGER_READ_ONLY
#define DATABASE_MENAGER_READ_ONLY (false)
#endif
// DataBaseDirectoryInfo Macros

#define DATABASE_DIR_NUMB_OF_FILES (2)  // Only DataBase and DataBaseBU

// DataBaseFileGenerator Macros
#define DATABASE_FILE_NAME_GENERATOR(directory) (directory + ".gdb")
#define DATABASE_BU_FILE_NAME_GENERATOR(directory) (directory + "_bu.gdb")

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _INCLUDES_ DataBaseMenager.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"databasemenagerparameters.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"DataBase/database.hpp"
#include<QFile>
#include"databasereader.hpp"

#if DATABASE_MENAGER_READ_ONLY == false
#include"databasewriter.hpp"
#endif
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseMenager.hpp --------------------------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseMenager -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseMenager : public DataBaseObject{
public:
    // _CONSTRUCTORS_ DataBaseMenager.hpp
    DataBaseMenager();
    // _DESTRUCTORS_ DataBaseMenager.hpp
    virtual ~DataBaseMenager() override;

protected:
    // _PRIVATE_MEMBERS_ DataBaseMenager.hpp
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(DATABASE_MENAGER_OBJECTS),
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(DATABASE_MENAGER_OBJECTS),
    };


    struct DataBaseInfo{
        DataBase* dataBase = nullptr;
        QString dataBaseFile;
        QString dataBaseFileBU;
    }** dataBaseInfo = nullptr;
    uint numbOfDataBasesInfo = 0;

    QFile dataBaseFile;
    QFile dataBaseFileBU;

    bool ready = false;
    DataBaseReader dataBaseReader;
#if DATABASE_MENAGER_READ_ONLY == false
    DataBaseWriter dataBaseWriter;
    bool writeDataBase(DataBaseInfo&);
#endif
public:
    // _PUBLIC_MEMBERS_ DataBaseMenager.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseMenager.hpp

    uint8_t restoreDataBaseFile();
    bool createDataBaseFile();
    bool createDataBaseFileBackUp();

    bool addDataBase(DataBaseInfo* db){ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseInfo, dataBaseInfo, numbOfDataBasesInfo, db);}
    bool removeDataBase(DataBaseInfo* db);
    void clearDataBase(){ARRAY_CLEAR_PTR_WITH_TEMP_PTR(dataBaseInfo, numbOfDataBasesInfo);}

public:
    // _PUBLIC_METHODS_ DataBaseMenager.hpp
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(DataBaseMenager, DataBaseObject, DataBaseMenagerParameters, NUMB_OF_DATABASE_MENAGER_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS)

    static QString getCurrentDataBaseVersion();
    bool createDataBase(DataBase&);
    bool readDataBase(DataBaseInfo&);
#if DATABASE_MENAGER_READ_ONLY == false
    bool openDataBase(DataBase&);
    bool saveDataBase(DataBaseInfo& dbInfo);    
    bool saveAsDataBase(DataBaseInfo& db);
    bool saveAllDataBases();
    bool safeCloseDB(DataBaseInfo& dbInfo);
#endif
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEMENAGER
