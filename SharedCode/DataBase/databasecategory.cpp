
// _INCLUDES_ DataBaseCategory.cpp -------------------------------------------------------------------------------------------------------------------
#include "databasecategory.hpp"
#include"databasecategoryparameters.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"getparamrules.hpp"
#include"setparamrules.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseCategory -----------------------------------------------------------------------------------------------------------------------------------------------
// Static Members
constexpr bool DataBaseCategory::optionality[];
constexpr bool DataBaseCategory::paramIsObject[];
// _CONSTRUCTORS_ DataBaseCategory.cpp
DataBaseCategory::DataBaseCategory() : DataBaseObject (DATABASE_OBJECT_CATEGORY, NUMB_OF_DATABASE_CATEGORY_PARAMETERS){

}

DataBaseCategory::DataBaseCategory(DatabaseObjectType type, uint numbOfParams) : DataBaseObject (type, numbOfParams + NUMB_OF_DATABASE_CATEGORY_PARAMETERS){

}

DataBaseCategory::DataBaseCategory(DataBaseObject* obj) : DataBaseObject (*obj, DATABASE_OBJECT_CATEGORY, NUMB_OF_DATABASE_CATEGORY_PARAMETERS){

}

DataBaseCategory::DataBaseCategory(DataBaseObject* obj, DatabaseObjectType type, uint numbOfParams) : DataBaseObject (*obj, type, numbOfParams + NUMB_OF_DATABASE_CATEGORY_PARAMETERS){

}

// _DESTRUCTORS_ DataBaseCategory.cpp
DataBaseCategory::~DataBaseCategory(){
    clearMemory();
}

// _PRIVATE_METHODS_ DataBaseCategory.cpp
void DataBaseCategory::clearMemory(){
    ARRAY_CLEAR_PTR_WITH_TEMP_PTR(dataBaseCategoryObjects.dataBaseObjects, dataBaseCategoryObjects.numbOfDataBaseObjects);
}

// _PUBLIC_METHODS_ DataBaseCategory.cpp
const QString DataBaseCategory::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, DataBaseCategory, DataBaseObject);
    switch(static_cast<DataBaseCategoryParameters>(param)){
    case DATABASE_CATEGORY_OBJECTS:
        return DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_CATEGORY_OBJECTS);
    default:
        return QString();
    }
}

QString DataBaseCategory::getParam(GetParamRules& paramRules){
    // Move to base if other param
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,DataBaseCategory, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_QSTRING(DataBaseCategory);
    // If not, check is param initialized
    switch (static_cast<DataBaseCategoryParameters>(paramRules.param)) {
    case DATABASE_CATEGORY_OBJECTS:
        // Cant return QString (Object)
    default:
        return QString();
    }
}

bool DataBaseCategory::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,DataBaseCategory, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_BOOL(DataBaseCategory);
    switch (static_cast<DataBaseCategoryParameters>(paramRules.param)){
    case DATABASE_CATEGORY_OBJECTS:
        if(paramRules.index < dataBaseCategoryObjects.numbOfDataBaseObjects){
            if(paramRules.index + 1 < dataBaseCategoryObjects.numbOfDataBaseObjects)
                paramRules.nextAvailable = true;
            DB_OBJECT_GET_PARAM_VOID_PTR(value, DataBaseObject*, (*(dataBaseCategoryObjects.dataBaseObjects + paramRules.index)));
        break;
        }
    [[clang::fallthrough]];
    default:
        return false;
    }
    return true;
}

bool DataBaseCategory::setParam(void *value, SetParamRules& paramRules){
    uint tempParam = paramRules.param;
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,DataBaseCategory, DataBaseObject);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<DataBaseCategoryParameters>(paramRules.param)) {
    case DATABASE_CATEGORY_OBJECTS:
        switch(paramRules.action){
            case SET_PARAM_ACTION_ADD:
            {
                setParamId = true;
                ret = addDataBaseCategoryObject(*static_cast<DataBaseObject**>(value));
            }
            break;
        case SET_PARAM_ACTION_REPLACE:
            {
                setParamId = true;
                ret = replaceDataBaseCategoryObject(static_cast<DataBaseObject*>(paramRules.additionalPtr), *static_cast<DataBaseObject**>(value));
            }
            break;
        default:
            break;
        }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBaseCategory);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBaseCategory);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(DataBaseCategory);
    return ret;
}

bool DataBaseCategory::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str, DataBaseCategory, DataBaseObject);
    bool ret = false;
    switch (static_cast<DataBaseCategoryParameters>(paramRules.param)) {
    case DATABASE_CATEGORY_OBJECTS:
        // Cant get QString (Object)
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBaseCategory);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBaseCategory);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    return true;
}

bool DataBaseCategory::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, DataBaseCategory, DataBaseObject);
    bool ret = false;
    switch (static_cast<DataBaseCategoryParameters>(rules.param)) {
        case DATABASE_CATEGORY_OBJECTS:
        // Cant compare
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat DataBaseCategory::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    default:
        break;
    }
    return DataBaseObject::checkParamAndProccess(param, value, dbObjectParamRules);
}



// ----------------------------------------------------------------------------------------------------------------------------------------------
