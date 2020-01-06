#ifndef DATABASECATEGORY_HPP
#define DATABASECATEGORY_HPP
// _INCLUDES_ DataBaseCategory.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QString>
#include"databaseobject.hpp"
#include"databasecategoryparameters.hpp"
#include"databasecategorytype.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseCategory.hpp --------------------------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
struct DataBaseCategoryObjects{
    DataBaseObject** dataBaseObjects = nullptr;
    uint numbOfDataBaseObjects = 0;
};

// _CLASSDEF_ DataBaseCategory -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseCategory : public DataBaseObject{
public:
    // _CONSTRUCTORS_ DataBaseCategory.hpp
    DataBaseCategory();
    DataBaseCategory(DatabaseObjectType, uint);
    DataBaseCategory(DataBaseObject* obj);
    DataBaseCategory(DataBaseObject* obj, DatabaseObjectType type, uint numbOfParams);
    // _DESTRUCTORS_ DataBaseCategory.hpp
    ~DataBaseCategory() override;

protected:
    // _PRIVATE_MEMBERS_ DataBaseCategory.hpp
    // DataBaseObjects and Subcategories (Never as Category)
    DataBaseCategoryObjects dataBaseCategoryObjects;

    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(DATABASE_CATEGORY_OBJECTS)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(DATABASE_CATEGORY_OBJECTS)
    };

public:
    // _PUBLIC_MEMBERS_ DataBaseCategory.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseCategory.hpp
    void clearMemory() override;
    bool addDataBaseCategoryObject(DataBaseObject* newObj){ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseObject, dataBaseCategoryObjects.dataBaseObjects, dataBaseCategoryObjects.numbOfDataBaseObjects, newObj);}
    bool replaceDataBaseCategoryObject(DataBaseObject* oldObj,DataBaseObject* newObj){ARRAY_REPLACE_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseObject, dataBaseCategoryObjects.dataBaseObjects, dataBaseCategoryObjects.numbOfDataBaseObjects,oldObj, newObj);}

public:
    // _PUBLIC_METHODS_ DataBaseCategory.hpp

    /*
    static inline constexpr uint getRealParam(DataBaseCategoryParameters param){return  param + DataBaseObject::getRealParam(NUMB_OF_DATABASE_OBJECT_PARAMETERS);}
    //inline uint getRealParam(uint param) override{return param + DataBaseCategory::getSuperClassNumbOfParameters();}
    const QString getParamName(uint param) override;
    inline bool isParamOptional(uint param) override{DB_OBJECT_IS_PARAM_OPTIONAL_CALL_BASE(param, DataBaseCategory, DataBaseObject);}
    inline bool isParamObject(uint param) override{DB_OBJECT_IS_PARAM_OBJECT_CALL_BASE(param, DataBaseCategory, DataBaseObject);}
    virtual inline uint getNumbOfParameters()override{return NUMB_OF_DATABASE_CATEGORY_PARAMETERS + DB_GET_SUPER_CLASS_NUMB_OF_PARAMS(DataBaseCategory);}
    //inline uint getNumbOfDataBaseObjectTypes() override{return 0 + DB_GET_SUPER_CLASS_NUMB_OF_TYPES(DataBaseCategory);}
    virtual inline uint getSuperClassNumbOfParameters()override{return DataBaseObject::getNumbOfParameters();}
    //inline uint getSuperClassNumbOfTypes() override{return DataBaseObject::getNumbOfDataBaseObjectTypes();}

    QString getParam(GetParamRules&) override;
    bool getParam(void*, GetParamRules&) override;
    bool setParam(void*, SetParamRules&) override;
    bool setParam(QString&, SetParamRules&) override;
    bool compareParams(void*, GetParamRules&) override;*/

    DB_OBJECT_STANDARD_METHODS(DataBaseCategory, DataBaseObject, DataBaseCategoryParameters, NUMB_OF_DATABASE_CATEGORY_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS, DataBaseCategoryType, NUMB_OF_DATABASE_CATEGORY_TYPES, NUMB_OF_DATABASE_OBJECT_TYPES)

    DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*) override;
    DataBaseObject* createObject(uint newType) override{return nullptr;}
    //DataBaseObject* createObject(DataBaseObject* obj, uint type); // Copy Object to new Object, then delete old Object



};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASECATEGORY
