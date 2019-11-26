
// _INCLUDES_ SimulationAreaTemplateElementSimulationArea.cpp -------------------------------------------------------------------------------------------------------------------
#include"simulationarea.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
#include<QPen>
#include<QBrush>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplateElementSimulationArea -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplateElementSimulationArea::optionality[];
constexpr bool SimulationAreaTemplateElementSimulationArea::paramIsObject[];

// _CONSTRUCTORS_ SimulationAreaTemplateElementSimulationArea.cpp
SimulationAreaTemplateElementSimulationArea::SimulationAreaTemplateElementSimulationArea() : SimulationAreaTemplateElementSimulationArea(static_cast<uint>(0)){}

SimulationAreaTemplateElementSimulationArea::SimulationAreaTemplateElementSimulationArea(uint numbOfParams) : SimulationAreaTemplateElementRect(numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_SIMULATION_AREA_PARAMETERS){

}


SimulationAreaTemplateElementSimulationArea::SimulationAreaTemplateElementSimulationArea(DataBaseObject* obj) : SimulationAreaTemplateElementSimulationArea(obj, 0){}

SimulationAreaTemplateElementSimulationArea::SimulationAreaTemplateElementSimulationArea(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElementRect(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_SIMULATION_AREA_PARAMETERS){

}

// _DESTRUCTORS_ SimulationAreaTemplateElementSimulationArea.cpp
SimulationAreaTemplateElementSimulationArea::~SimulationAreaTemplateElementSimulationArea(){

}

// _PRIVATE_METHODS_ SimulationAreaTemplateElementSimulationArea.cpp


// _PUBLIC_METHODS_ SimulationAreaTemplateElementSimulationArea.cpp
const QString SimulationAreaTemplateElementSimulationArea::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect);
    switch(static_cast<SimulationAreaTemplateElementSimulationAreaParameters>(param)){
    default:
        return QString();
    }
}

QString SimulationAreaTemplateElementSimulationArea::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaTemplateElementSimulationArea);
    switch (static_cast<SimulationAreaTemplateElementSimulationAreaParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool SimulationAreaTemplateElementSimulationArea::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaTemplateElementSimulationArea);
    switch (static_cast<SimulationAreaTemplateElementSimulationAreaParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool SimulationAreaTemplateElementSimulationArea::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaTemplateElementSimulationAreaParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementSimulationArea);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementSimulationArea);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaTemplateElementSimulationArea);
    return true;
}

bool SimulationAreaTemplateElementSimulationArea::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementSimulationAreaParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementSimulationArea);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementSimulationArea);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaTemplateElementSimulationArea::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementSimulationAreaParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaTemplateElementSimulationArea::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // LED_MATRIX_PICTURE_ELEMENT = object
    default:
        break;
    }
    return SimulationAreaTemplateElementRect::checkParamAndProccess(param, value, dbObjectParamRules);
}



