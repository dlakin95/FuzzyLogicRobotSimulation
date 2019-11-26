
// _INCLUDES_ SimulationAreaTemplateElementElipse.cpp -------------------------------------------------------------------------------------------------------------------
#include"elipse.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplateElementElipse -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplateElementElipse::optionality[];
constexpr bool SimulationAreaTemplateElementElipse::paramIsObject[];

// _CONSTRUCTORS_ SimulationAreaTemplateElementElipse.cpp
SimulationAreaTemplateElementElipse::SimulationAreaTemplateElementElipse() : SimulationAreaTemplateElementElipse(static_cast<uint>(0)){}

SimulationAreaTemplateElementElipse::SimulationAreaTemplateElementElipse(uint numbOfParams) : SimulationAreaTemplateElement(numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS){
    SET_PTR_DO(object, new QGraphicsEllipseItem());
}


SimulationAreaTemplateElementElipse::SimulationAreaTemplateElementElipse(DataBaseObject* obj) : SimulationAreaTemplateElementElipse(obj, 0){}

SimulationAreaTemplateElementElipse::SimulationAreaTemplateElementElipse(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElement(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS){
    SET_PTR_DO(object, new QGraphicsEllipseItem());
}

// _DESTRUCTORS_ SimulationAreaTemplateElementElipse.cpp
SimulationAreaTemplateElementElipse::~SimulationAreaTemplateElementElipse(){

}

// _PRIVATE_METHODS_ SimulationAreaTemplateElementElipse.cpp


// _PUBLIC_METHODS_ SimulationAreaTemplateElementElipse.cpp
const QString SimulationAreaTemplateElementElipse::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement);
    switch(static_cast<SimulationAreaTemplateElementElipseParameters>(param)){
    default:
        return QString();
    }
}

QString SimulationAreaTemplateElementElipse::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaTemplateElementElipse);
    switch (static_cast<SimulationAreaTemplateElementElipseParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool SimulationAreaTemplateElementElipse::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaTemplateElementElipse);
    switch (static_cast<SimulationAreaTemplateElementElipseParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool SimulationAreaTemplateElementElipse::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaTemplateElementElipseParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementElipse);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementElipse);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaTemplateElementElipse);
    return true;
}

bool SimulationAreaTemplateElementElipse::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementElipseParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementElipse);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementElipse);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaTemplateElementElipse::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementElipseParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaTemplateElementElipse::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    default:
        break;
    }
    return SimulationAreaTemplateElement::checkParamAndProccess(param, value, dbObjectParamRules);
}



