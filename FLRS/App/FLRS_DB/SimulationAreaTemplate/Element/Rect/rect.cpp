
// _INCLUDES_ SimulationAreaTemplateElementRect.cpp -------------------------------------------------------------------------------------------------------------------
#include"rect.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplateElementRect -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplateElementRect::optionality[];
constexpr bool SimulationAreaTemplateElementRect::paramIsObject[];

// _CONSTRUCTORS_ SimulationAreaTemplateElementRect.cpp
SimulationAreaTemplateElementRect::SimulationAreaTemplateElementRect() : SimulationAreaTemplateElementRect(static_cast<uint>(0)){}

SimulationAreaTemplateElementRect::SimulationAreaTemplateElementRect(uint numbOfParams) : SimulationAreaTemplateElement(numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_RECT_PARAMETERS){

}


SimulationAreaTemplateElementRect::SimulationAreaTemplateElementRect(DataBaseObject* obj) : SimulationAreaTemplateElementRect(obj, 0){}

SimulationAreaTemplateElementRect::SimulationAreaTemplateElementRect(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElement(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_RECT_PARAMETERS){

}

// _DESTRUCTORS_ SimulationAreaTemplateElementRect.cpp
SimulationAreaTemplateElementRect::~SimulationAreaTemplateElementRect(){

}

// _PRIVATE_METHODS_ SimulationAreaTemplateElementRect.cpp


// _PUBLIC_METHODS_ SimulationAreaTemplateElementRect.cpp
const QString SimulationAreaTemplateElementRect::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaTemplateElementRect, SimulationAreaTemplateElement);
    switch(static_cast<SimulationAreaTemplateElementRectParameters>(param)){
    default:
        return QString();
    }
}

QString SimulationAreaTemplateElementRect::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaTemplateElementRect, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaTemplateElementRect);
    switch (static_cast<SimulationAreaTemplateElementRectParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool SimulationAreaTemplateElementRect::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaTemplateElementRect, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaTemplateElementRect);
    switch (static_cast<SimulationAreaTemplateElementRectParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool SimulationAreaTemplateElementRect::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaTemplateElementRect, SimulationAreaTemplateElement);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaTemplateElementRectParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaTemplateElementRect);
    return true;
}

bool SimulationAreaTemplateElementRect::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaTemplateElementRect, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementRectParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaTemplateElementRect::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaTemplateElementRect, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementRectParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaTemplateElementRect::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    default:
        break;
    }
    return SimulationAreaTemplateElement::checkParamAndProccess(param, value, dbObjectParamRules);
}



