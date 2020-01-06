
// _INCLUDES_ FuzzyLogicRobotSimulationDataBase.cpp -------------------------------------------------------------------------------------------------------------------
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"flrsdatabase.hpp"
#include"SimulationAreaTemplate/simulationareatemplate.hpp"
#include"SimulationAreaTemplate/Element/element.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"

// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ FuzzyLogicRobotSimulationDataBase -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool FuzzyLogicRobotSimulationDataBase::optionality[];
constexpr bool FuzzyLogicRobotSimulationDataBase::paramIsObject[];

// _CONSTRUCTORS_ FuzzyLogicRobotSimulationDataBase.cpp
FuzzyLogicRobotSimulationDataBase::FuzzyLogicRobotSimulationDataBase() : DataBase(){

}

// _DESTRUCTORS_ FuzzyLogicRobotSimulationDataBase.cpp
FuzzyLogicRobotSimulationDataBase::~FuzzyLogicRobotSimulationDataBase(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);

}

// _PRIVATE_METHODS_ FuzzyLogicRobotSimulationDataBase.cpp


// _PUBLIC_METHODS_ FuzzyLogicRobotSimulationDataBase.cpp
const QString FuzzyLogicRobotSimulationDataBase::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, FuzzyLogicRobotSimulationDataBase, DataBase);
    switch(static_cast<FuzzyLogicRobotSimulationDataBaseParameters>(param)){
    default:
        return QString();
    }
}

QString FuzzyLogicRobotSimulationDataBase::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,FuzzyLogicRobotSimulationDataBase, DataBase);
    DB_OBJECT_IS_INITIALIZED_QSTRING(FuzzyLogicRobotSimulationDataBase);
    switch (static_cast<FuzzyLogicRobotSimulationDataBaseParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool FuzzyLogicRobotSimulationDataBase::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, FuzzyLogicRobotSimulationDataBase, DataBase);
    DB_OBJECT_IS_INITIALIZED_BOOL(FuzzyLogicRobotSimulationDataBase);
    switch (static_cast<FuzzyLogicRobotSimulationDataBaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool FuzzyLogicRobotSimulationDataBase::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,FuzzyLogicRobotSimulationDataBase, DataBase);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<FuzzyLogicRobotSimulationDataBaseParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, FuzzyLogicRobotSimulationDataBase);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, FuzzyLogicRobotSimulationDataBase);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(FuzzyLogicRobotSimulationDataBase);
    return true;
}

bool FuzzyLogicRobotSimulationDataBase::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,FuzzyLogicRobotSimulationDataBase, DataBase);
    bool ret = false;
    switch (static_cast<FuzzyLogicRobotSimulationDataBaseParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, FuzzyLogicRobotSimulationDataBase);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, FuzzyLogicRobotSimulationDataBase);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool FuzzyLogicRobotSimulationDataBase::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, FuzzyLogicRobotSimulationDataBase, DataBase);
    bool ret = false;
    switch (static_cast<FuzzyLogicRobotSimulationDataBaseParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat FuzzyLogicRobotSimulationDataBase::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {

    default:
        break;
    }
    return DataBase::checkParamAndProccess(param, value, dbObjectParamRules);
}

DataBaseObject* FuzzyLogicRobotSimulationDataBase::createObject(DataBaseObject *obj, uint newType){
    if(obj == this)
        return this;
    if(obj->getObjectType() != NUMB_OF_DATABASE_OBJECT_TYPES) return nullptr;
    DB_OBJECT_CREATE_OBJECT_CALL_BASE(obj, FuzzyLogicRobotSimulationDataBase, DataBase);
    switch(static_cast<FuzzyLogicRobotSimulationDataBaseTypes>(newType)){
    case FLRS_SIMULATION_AREA_TEMPLATE:
        return new SimulationAreaTemplate(obj);
    case FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT:
        return new SimulationAreaTemplateElement(obj);
    default:
        return nullptr;
    }
}


/*void FuzzyLogicRobotSimulationDataBase::set_dataBaseGeneralInformation(FuzzyLogicRobotSimulationDataBaseGeneralInformation* set){dataBaseGeneralInformation = set;}
FuzzyLogicRobotSimulationDataBaseGeneralInformation* FuzzyLogicRobotSimulationDataBase::get_dataBaseGeneralInformation(){return dataBaseGeneralInformation;}
//GET_SET_NDO_DEFINITION(FuzzyLogicRobotSimulationDataBase, FuzzyLogicRobotSimulationDataBaseGeneralInformation*, dataBaseGeneralInformation)
GET_DEFINITION(FuzzyLogicRobotSimulationDataBase,DataBase**, dataBaseObjects)
GET_DEFINITION(FuzzyLogicRobotSimulationDataBase,uint, numbOfDataBases)
GET_DEFINITION(FuzzyLogicRobotSimulationDataBase,FuzzyLogicRobotSimulationDataBaseError, error)*/


/*void FuzzyLogicRobotSimulationDataBase::prepareToRead(){

}*/


// ----------------------------------------------------------------------------------------------------------------------------------------------
