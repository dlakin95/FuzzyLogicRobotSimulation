
// _INCLUDES_ ObstacleEllipse.cpp -------------------------------------------------------------------------------------------------------------------
#include"obstacleellipse.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ ObstacleEllipse -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool ObstacleEllipse::optionality[];
constexpr bool ObstacleEllipse::paramIsObject[];

// _CONSTRUCTORS_ ObstacleEllipse.cpp
ObstacleEllipse::ObstacleEllipse() : ObstacleEllipse(static_cast<uint>(0)){}

ObstacleEllipse::ObstacleEllipse(uint numbOfParams) : SimulationAreaTemplateElement(numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS){
    SET_PTR_DO(object, new QGraphicsEllipseItem());
}


ObstacleEllipse::ObstacleEllipse(DataBaseObject* obj) : ObstacleEllipse(obj, 0){}

ObstacleEllipse::ObstacleEllipse(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElement(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS){
    SET_PTR_DO(object, new QGraphicsEllipseItem());
}

// _DESTRUCTORS_ ObstacleEllipse.cpp
ObstacleEllipse::~ObstacleEllipse(){

}

// _PRIVATE_METHODS_ ObstacleEllipse.cpp


// _PUBLIC_METHODS_ ObstacleEllipse.cpp
const QString ObstacleEllipse::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, ObstacleEllipse, SimulationAreaTemplateElement);
    switch(static_cast<ObstacleEllipseParameters>(param)){
    default:
        return QString();
    }
}

QString ObstacleEllipse::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,ObstacleEllipse, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_QSTRING(ObstacleEllipse);
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool ObstacleEllipse::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, ObstacleEllipse, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_BOOL(ObstacleEllipse);
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool ObstacleEllipse::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,ObstacleEllipse, SimulationAreaTemplateElement);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, ObstacleEllipse);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, ObstacleEllipse);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(ObstacleEllipse);
    return true;
}

bool ObstacleEllipse::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,ObstacleEllipse, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, ObstacleEllipse);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, ObstacleEllipse);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool ObstacleEllipse::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, ObstacleEllipse, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<ObstacleEllipseParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat ObstacleEllipse::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    default:
        break;
    }
    return SimulationAreaTemplateElement::checkParamAndProccess(param, value, dbObjectParamRules);
}



