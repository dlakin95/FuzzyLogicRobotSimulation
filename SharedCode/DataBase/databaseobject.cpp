// _INCLUDES_ DataBaseObject.cpp -------------------------------------------------------------------------------------------------------------------
#include "databaseobject.hpp"
#include"databaseparams.hpp"
#include"databaseobjectsreadfilecontainer.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"getparamrules.hpp"
#include"setparamrules.hpp"
// -------------------------------------------------------------------------------------------------------------------------------
// Static Members
constexpr bool DataBaseObject::optionality[];
constexpr bool DataBaseObject::paramIsObject[];
// _CLASSIMP_ DataBaseObject -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseObject.cpp
DataBaseObject::DataBaseObject(DatabaseObjectType type, uint numbOfParams) : FileableObject (){
    initialize(numbOfParams);
    SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_VERSION), UINT_MAX, SET_PARAM_ACTION_ADD};
    QString cVer = QString("1.0");
    setParam(&cVer, spr);
    spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_TYPE), UINT_MAX, SET_PARAM_ACTION_ADD};
    setParam(&type, spr);
}

DataBaseObject::DataBaseObject(const DataBaseObject &obj, uint numbOfParam) : FileableObject (){
    objectName = obj.objectName;
    objectType = obj.objectType;
    objectVersion = obj.objectVersion;
    paramId = obj.paramId;
    initializedParameters = obj.initializedParameters;
    tailOfInitializedParamters = obj.tailOfInitializedParamters;
    initialize(numbOfParam);
}


DataBaseObject::DataBaseObject(const DataBaseObject &obj, DatabaseObjectType newType, uint numbOfParam) : FileableObject (){
    objectName = obj.objectName;
    objectType = newType;
    objectVersion = obj.objectVersion;
    paramId = obj.paramId;
    initializedParameters = obj.initializedParameters;
    tailOfInitializedParamters = obj.tailOfInitializedParamters;
    initialize(numbOfParam);
}

// _DESTRUCTORS_ DataBaseObject.cpp
DataBaseObject::~DataBaseObject(){
    clearMemory();
}

void DataBaseObject::clearMemory(){
    SET_PTR_DOA(initializedParameters, nullptr);
}

// _PRIVATE_METHODS_ DataBaseObject.cpp
void DataBaseObject::initialize(uint numbOfParams){
    numbOfParams += getNumbOfParameters();
    bool *tempParameters = nullptr;
    if(numbOfParams > 0){
        SET_PTR_NDO(tempParameters, new bool[numbOfParams]);
        uint i = 0;
        if(!tailOfInitializedParamters){
            for( ; i < numbOfParams; i++)
                (*(tempParameters + i)) = false;
        }else{
            for(bool* tempPtr = initializedParameters; tempPtr < tailOfInitializedParamters; tempPtr++, i++){
                (*(tempParameters + i)) = *tempPtr;
            }
            for( ; i < numbOfParams; i++)
                (*(tempParameters + i)) = false;
        }
        SET_PTR_NDO(initializedParameters, tempParameters);
        tailOfInitializedParamters = initializedParameters + numbOfParams;
    }
}


bool DataBaseObject::setParamId(uint param){
    paramId = param;
    (*(initializedParameters + DATABASE_OBJECT_PARAM_OBJECT_ID)) = true;
    return true;
}

// _PUBLIC_METHODS_ DataBaseObject.cpp

const QString DataBaseObject::getParamName(uint param){
    switch(static_cast<DatabaseObjectParameters>(param)){
    case DATABASE_OBJECT_NAME:
        return DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_NAME);
    case DATABASE_OBJECT_TYPE:
        return DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_TYPE);
    case DATABASE_OBJECT_VERSION:
        return DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_VERSION);
    case DATABASE_OBJECT_PARAM_OBJECT_ID:
        return DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_PARAM_OBJECT_ID);
    default:
        return QString();
    }
}

QString DataBaseObject::getParam(GetParamRules& paramRules){
    DB_OBJECT_IS_INITIALIZED_QSTRING(DataBaseObject);
    switch(static_cast<DatabaseObjectParameters>(paramRules.param)) {
        case DATABASE_OBJECT_NAME:
            return objectName;
        case DATABASE_OBJECT_VERSION:
            return objectVersion;
        case DATABASE_OBJECT_TYPE:
            return QString::number(objectType);
        case DATABASE_OBJECT_PARAM_OBJECT_ID:
            return QString::number(paramId);
        default:
            return QString();
    }
}

bool DataBaseObject::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_IS_INITIALIZED_BOOL(DataBaseObject);
    switch (static_cast<DatabaseObjectParameters>(paramRules.param)) {
        case DATABASE_OBJECT_NAME:
            DB_OBJECT_GET_PARAM_VOID_PTR(value, QString, objectName);
            break;
        case DATABASE_OBJECT_VERSION:
            DB_OBJECT_GET_PARAM_VOID_PTR(value, QString, objectVersion);
            break;
        case DATABASE_OBJECT_TYPE:
            DB_OBJECT_GET_PARAM_VOID_PTR(value, uint, objectType);
        break;
        case DATABASE_OBJECT_PARAM_OBJECT_ID:
            DB_OBJECT_GET_PARAM_VOID_PTR(value, uint , paramId);
        break;
        default:
            return false;
    }
    return true;
}


// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_GET_PARAM_
// -------------------------------------

bool DataBaseObject::setParam(void *value, SetParamRules& paramRules){    
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<DatabaseObjectParameters>(paramRules.param)) {
    case DATABASE_OBJECT_NAME:
        DB_OBJECT_SET_PARAM_VOID_PTR(value, QString, objectName);
        break;
    case DATABASE_OBJECT_VERSION:
        DB_OBJECT_SET_PARAM_VOID_PTR(value, QString, objectVersion);
        break;
    case DATABASE_OBJECT_TYPE:
        DB_OBJECT_SET_PARAM_VOID_PTR(value, uint, objectType);
        break;
    case DATABASE_OBJECT_PARAM_OBJECT_ID:
        DB_OBJECT_SET_PARAM_VOID_PTR(value, uint, paramId);
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBaseObject);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBaseObject);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(DataBaseObject);
    return true;
}

bool DataBaseObject::setParam(QString &value, SetParamRules& paramRules){
    bool ret = false;
    switch (static_cast<DatabaseObjectParameters>(paramRules.param)) {
        case DATABASE_OBJECT_NAME:
            objectName = value;
            ret = true;
            break;
        case DATABASE_OBJECT_VERSION:
            objectVersion = value;
            ret = true;
            break;
        case DATABASE_OBJECT_TYPE:
            objectType = value.toUInt();
            ret = true;
            break;
        case DATABASE_OBJECT_PARAM_OBJECT_ID:
            paramId = value.toUInt();
            ret = true;
            break;
        default:
            return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBaseObject);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBaseObject);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    return true;
}

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_SET_PARAM_
// -----------------------------------

bool DataBaseObject::compareParams(void *value, GetParamRules &rules){
    bool ret = false;
    switch (static_cast<DatabaseObjectParameters>(rules.param)) {
        case DATABASE_OBJECT_NAME:
            ret = objectName == *static_cast<QString*>(value);
            break;
        case DATABASE_OBJECT_VERSION:
            ret = objectVersion == *static_cast<QString*>(value);
            break;
        case DATABASE_OBJECT_TYPE:
            ret = (objectType == *static_cast<uint*>(value));
            break;
        case DATABASE_OBJECT_PARAM_OBJECT_ID:
            ret = (paramId == *static_cast<uint*>(value));
            break;
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}


DataBaseFileOperationStat DataBaseObject::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer *dbObjReadFileConatainer){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    case PARAM_LENGTH_2:
    {
        // DATABASE_CATEGORY
        CHECK_PARAM_DECISION_BLOCK(param, DATABASE_PARAM_NAME, PARAM_LENGTH_2){
            return DATABASE_FILE_OPERATION_DB_INIT;
        }
    }
        break;
    case PARAM_LENGTH_4:
    {
        // DATABASE_OBJECT_NAME
        tempStr.clear();
        tempStr = DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_NAME);
        for(i = 0; i < PARAM_LENGTH_4; i++)
            if(param.at(i) != tempStr.at(i))
            break;
        if(i == PARAM_LENGTH_4)
        {//CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_NAME), PARAM_LENGTH_4){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(DataBaseObject, DATABASE_OBJECT_NAME, value, dbObjReadFileConatainer);
        }
        // DATABASE_OBJECT_TYPE
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_TYPE), PARAM_LENGTH_4){
            // Set Readed Type
            return DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE;
            //DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN(DataBaseObject, DATABASE_OBJECT_NAME, value, dbObjReadFileConatainer, DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE);
            /*
            spr.param = DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_TYPE);
            if(!setParam(value, spr))
                return  NUMB_OF_DATABASE_FILE_OPERATIONS;
            return DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE;*/
        }
        // DATABASE_RECORD
        CHECK_PARAM_DECISION_BLOCK(param, DATABASE_RECORD_PARAM_NAME, PARAM_LENGTH_4){
            return DATABASE_FILE_OPERATION_DB_RECORD;
        }
        // DATABASE_CATEGORY
        CHECK_PARAM_DECISION_BLOCK(param, DATABASE_CATEGORY_PARAM_NAME, PARAM_LENGTH_4){
            return DATABASE_FILE_OPERATION_DB_CATEGORY;
        }
    }
        break;
    case PARAM_LENGTH_6:
        {
            // DATABASE_OBJECT_VERSION
            CHECK_PARAM_DECISION_BLOCK(param, DATABASE_OBJECT_VERSION_PARAM_NAME, PARAM_LENGTH_6){
                DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(DataBaseObject, DATABASE_OBJECT_VERSION, value, dbObjReadFileConatainer);
            }
            // DATABASE_END_OF_RECORD
            CHECK_PARAM_DECISION_BLOCK(param, DATABASE_END_OF_RECORD_PARAM_NAME, PARAM_LENGTH_6){
                return DATABASE_FILE_OPERATION_DB_END_RECORD;
            }
            // DATABASE_END_OF_CATEGORY
            CHECK_PARAM_DECISION_BLOCK(param, DATABASE_END_OF_CATEGORY_PARAM_NAME, PARAM_LENGTH_6){
                return DATABASE_FILE_OPERATION_DB_END_CATEGORY;
            }
            // DATABASE_END_OF_BASE
            CHECK_PARAM_DECISION_BLOCK(param, DATABASE_END_OF_BASE_PARAM_NAME, PARAM_LENGTH_6){
                return DATABASE_FILE_OPERATION_DB_END_BASE;
            }
            /*// DATABASE_END_OF_GENERAL
            CHECK_PARAM_DECISION_BLOCK(param, DATABASE_END_OF_GENERAL_PARAM_NAME, PARAM_LENGTH_6){
                return DATABASE_FILE_OPERATION_DB_END_GENERAL;
            }*/
        }
        break;
    case PARAM_LENGTH_7:
    {
        // DATABASE_OBJECT_PARAM_OBJECT_ID
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(DATABASE_OBJECT_PARAM_OBJECT_ID), PARAM_LENGTH_7){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(DataBaseObject, DATABASE_OBJECT_PARAM_OBJECT_ID, value, dbObjReadFileConatainer);
        }
    }
        break;

    /*case PARAM_LENGTH_9:
    {
        // DATABASE_GENERAL
        CHECK_PARAM_DECISION_BLOCK(param, DATABASE_GENERAL_PARAM_NAME, PARAM_LENGTH_9){
            return DATABASE_FILE_OPERATION_DB_GENERAL;
        }
    }
        break;*/
    default:
        break;
    }
    return NUMB_OF_DATABASE_FILE_OPERATIONS;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
