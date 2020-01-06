
// _INCLUDES_ SimulationArea.cpp -------------------------------------------------------------------------------------------------------------------
#include"simarea.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
#include"App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/Rect/SARect.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationArea -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationArea::optionality[];
constexpr bool SimulationArea::paramIsObject[];

// _CONSTRUCTORS_ SimulationArea.cpp
SimulationArea::SimulationArea() : SimulationArea(static_cast<uint>(0)){}

SimulationArea::SimulationArea(uint numbOfParams) : SimulationAreaTemplateElement(numbOfParams + NUMB_OF_SIMULATION_AREA_PARAMETERS){

}


SimulationArea::SimulationArea(DataBaseObject* obj) : SimulationArea(obj, 0){}

SimulationArea::SimulationArea(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElement(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_PARAMETERS){

}

// _DESTRUCTORS_ SimulationArea.cpp
SimulationArea::~SimulationArea(){

}

// _PRIVATE_METHODS_ SimulationArea.cpp


// _PUBLIC_METHODS_ SimulationArea.cpp
const QString SimulationArea::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationArea, SimulationAreaTemplateElement);
    switch(static_cast<SimulationAreaParameters>(param)){
    default:
        return QString();
    }
}

QString SimulationArea::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationArea, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationArea);
    switch (static_cast<SimulationAreaParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool SimulationArea::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationArea, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationArea);
    switch (static_cast<SimulationAreaParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool SimulationArea::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationArea, SimulationAreaTemplateElement);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationArea);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationArea);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationArea);
    return true;
}

bool SimulationArea::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationArea, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<SimulationAreaParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationArea);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationArea);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationArea::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationArea, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<SimulationAreaParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationArea::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    default:
        break;
    }
    return SimulationAreaTemplateElement::checkParamAndProccess(param, value, dbObjectParamRules);
}

DataBaseObject* SimulationArea::createObject(uint newType){
    if(getShape() != NUMB_OF_SHAPES)
        return nullptr;
    switch (newType) {
    case SHAPE_RECT:
        return new SimulationAreaRect(this);
    }
    return nullptr;
}
