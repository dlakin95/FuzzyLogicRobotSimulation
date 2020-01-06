#ifndef DATABASEOBJECT_HPP
#define DATABASEOBJECT_HPP
// _INCLUDES_ DataBaseObject.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"GeneralPurposeMacros/databasemenegmentmacros.hpp"
#include<QString>
#include"FileableObject/fileableobject.hpp"
#include"databaseobjecttype.hpp"
#include"databaseobjectparameters.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"
#include"setparamrules.hpp"
#include"getparamrules.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"databaseobjectsreadfilecontainer.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseObject.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObjectsReadFileContainer;

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseObject -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObject : public FileableObject{
public:
    // _CONSTRUCTORS_ DataBaseObject.hpp
    DataBaseObject(DatabaseObjectType, uint);// For Initilazation (get numbOfParams)
    DataBaseObject(const DataBaseObject &obj, uint param);
    DataBaseObject(const DataBaseObject &obj, DatabaseObjectType newType, uint param);
    // _DESTRUCTORS_ DataBaseObject.hpp
    virtual ~DataBaseObject() override;

protected:
    // _PRIVATE_MEMBERS_ DataBaseObject.hpp
    // Parameters
    QString objectName;
    uint objectType = NUMB_OF_DATABASE_OBJECT_TYPES;
    QString objectVersion;
    uint paramId = 0;

    // Object Control
    bool* initializedParameters = nullptr;
    bool* tailOfInitializedParamters = nullptr; // Only for Copy Constructor information

    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(DATABASE_OBJECT_NAME),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(DATABASE_OBJECT_VERSION),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(DATABASE_OBJECT_PARAM_OBJECT_ID),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(DATABASE_OBJECT_TYPE),
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(DATABASE_OBJECT_NAME),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(DATABASE_OBJECT_VERSION),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(DATABASE_OBJECT_PARAM_OBJECT_ID),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(DATABASE_OBJECT_TYPE)

    };

public:
    // _PUBLIC_MEMBERS_ DataBaseObject.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseObject.hpp
    void initialize(uint);

public:
    bool setParamId(uint param);
    virtual DataBaseObject* createObject(uint newType){return nullptr;}
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*);
    virtual void clearMemory();


    // _PUBLIC_METHODS_ DataBaseObject.hpp
    /*
    // Parameters Control
    static inline constexpr uint getRealParam(DatabaseObjectParameters param){return param;}
    virtual inline uint getNumbOfParameters(){return NUMB_OF_DATABASE_OBJECT_PARAMETERS;}
    virtual inline  uint getSuperClassNumbOfParameters(){return 0;}
    // Types Control
    static inline constexpr uint getRealType(DatabaseObjectType type){return type;}
    virtual inline uint getNumbOfTypes(){return NUMB_OF_DATABASE_OBJECT_TYPES;}
    virtual inline uint getSuperClassNumbOfTypes(){return 0;}
    // Parameter Additional Information Control
    virtual inline bool isParamOptional(uint param){if(param < DataBaseObject::getNumbOfParameters()) return (*(DataBaseObject::optionality + param)); return false;}
    virtual inline bool isParamObject(uint param){if(param < DataBaseObject::getNumbOfParameters()) return (*(DataBaseObject::paramIsObject + param)); return false;}
    inline bool isParameterInitilized(uint parameter){if(initializedParameters && parameter < getNumbOfParameters()) return (*(initializedParameters + parameter)); return false;}
    // Parameter Access Functions
    virtual QString getParam(GetParamRules&) override;
    virtual bool getParam(void*, GetParamRules&);
    virtual bool setParam(void*, SetParamRules&);
    virtual bool setParam(QString&, SetParamRules&);
    virtual bool compareParams(void*, GetParamRules&);*/
    DB_OBJECT_BASE_CLASS_STANDARD_METHODS(DataBaseObject, DatabaseObjectParameters, NUMB_OF_DATABASE_OBJECT_PARAMETERS, DatabaseObjectType, NUMB_OF_DATABASE_OBJECT_TYPES)
    // Object Memory Menegment

    //virtual const QString getParamName(uint param) override;

    inline uint getObjectType(){return objectType;}
    inline uint getParamId(){return paramId;}


    // _PH_

    //virtual uint getParamType(uint){}
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEOBJECT
