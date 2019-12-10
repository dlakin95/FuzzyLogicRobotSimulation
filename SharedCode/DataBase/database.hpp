#ifndef DATABASE_HPP
#define DATABASE_HPP
// _INCLUDES_ DataBase.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QObject>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"Enum/DataBaseFiles/databaseerror.hpp"
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"
#include"databaseobjecttype.hpp"
#include"databaseparams.hpp"
#include"databasecategory.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBase.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObjectParameterRulesReadFile;
class QFile;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBase -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBase : public DataBaseCategory{
public:
    // _CONSTRUCTORS_ DataBase.hpp
    DataBase();
    // _DESTRUCTORS_ DataBase.hpp
    virtual ~DataBase() override;

protected:

    // Optionality Table
    static constexpr bool optionality[]=
    {

    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {

    };

    // _PRIVATE_MEMBERS_ DataBase.hpp

    // DataBase Error
    DataBaseError error = DATABASE_NO_ERROR;    // Contains information about file read error (numbers from 0 to NUMB_OF_FILE_READ_ERRORS and Database parsing errors after FileReadErrors)

public:
    // _PUBLIC_MEMBERS_ DataBase.hpp

protected:
    // _PRIVATE_METHODS_ DataBase.hpp
    /*virtual inline uint getNumbOfDataBaseObjectTypes(){return NUMB_OF_DATABASE_OBJECT_TYPES;}
    virtual inline uint getSuperClassNumbOfTypes(){return 0;}
    virtual DataBaseObject* createObject(DataBaseObject*); // Copy Object to new Object, then delete old Object
    void prepareToRead();*/

public:
    // _PUBLIC_METHODS_ DataBase.hpp
    /*GET_SET_DECLARATION(DataBaseGeneralInformation*, dataBaseGeneralInformation)
    GET_DECLARATION(DataBaseObject**, dataBaseObjects)
    GET_DECLARATION(uint, numbOfDataBaseObjects)*/
    GET_DECLARATION(DataBaseError, error)
/*
    static inline constexpr uint getRealParam(DatabaseObjectParameters param){return param;}
    //virtual inline uint getRealParam(uint param){return param + DataBaseObject::getSuperClassNumbOfParameters();}
    virtual inline bool isParamOptional(uint param){if(param < DataBaseObject::getNumbOfParameters()) return (*(DataBaseObject::optionality + param)); return false;}
    virtual inline bool isParamObject(uint param){if(param < DataBaseObject::getNumbOfParameters()) return (*(DataBaseObject::paramIsObject + param)); return false;}
    virtual const QString getParamName(uint param) override;
    inline bool isParameterInitilized(uint parameter){if(initializedParameters && parameter < getNumbOfParameters()) return (*(initializedParameters + parameter)); return false;}
    inline uint getObjectType(){return objectType;}
    inline uint getParamId(){return paramId;}
    virtual inline uint getNumbOfParameters(){return NUMB_OF_DATABASE_OBJECT_PARAMETERS;}
    //virtual inline uint getNumbOfDataBaseObjectTypes(){return NUMB_OF_DATABASE_OBJECT_TYPES;}
    virtual inline  uint getSuperClassNumbOfParameters(){return 0;}
    //virtual inline uint getSuperClassNumbOfTypes(){return 0;}

    virtual QString getParam(GetParamRules&) override;

    virtual bool getParam(void*, GetParamRules&);

    virtual bool setParam(void*, SetParamRules&);

    virtual bool setParam(QString&, SetParamRules&);

    virtual bool compareParams(void*, GetParamRules&);
    */
    DB_OBJECT_STANDARD_METHODS(DataBase, DataBaseCategory, DatabaseParameters, NUMB_OF_DATABASE_PARAMETERS, NUMB_OF_DATABASE_CATEGORY_PARAMETERS, DataBaseCategoryType, 0, NUMB_OF_DATABASE_CATEGORY_TYPES)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint)override final{return nullptr;}
    virtual DataBaseObject* createObject(DataBaseObject* obj, uint newType){return nullptr;}

    void readDataBaseFile(QFile&);
    void writeDataBaseFile(QFile&);


};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASE
