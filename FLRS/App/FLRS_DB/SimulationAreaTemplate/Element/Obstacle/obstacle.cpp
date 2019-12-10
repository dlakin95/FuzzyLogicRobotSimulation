
// _INCLUDES_ Obstacle.cpp -------------------------------------------------------------------------------------------------------------------
#include"obstacle.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ Obstacle -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool Obstacle::optionality[];
constexpr bool Obstacle::paramIsObject[];

// _CONSTRUCTORS_ Obstacle.cpp
Obstacle::Obstacle() : Obstacle(static_cast<uint>(0)){}

Obstacle::Obstacle(uint numbOfParams) : SimulationAreaTemplateElement(numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS){

}


Obstacle::Obstacle(DataBaseObject* obj) : Obstacle(obj, 0){}

Obstacle::Obstacle(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElement(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS){

}

// _DESTRUCTORS_ Obstacle.cpp
Obstacle::~Obstacle(){

}

// _PRIVATE_METHODS_ Obstacle.cpp


// _PUBLIC_METHODS_ Obstacle.cpp
const QString Obstacle::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, Obstacle, SimulationAreaTemplateElement);
    switch(static_cast<ObstacleParameters>(param)){
    DB_GET_PARAM_NAME(OBSTACLE_SHAPE);
    default:
        return QString();
    }
}

QString Obstacle::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,Obstacle, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_QSTRING(Obstacle);
    switch (static_cast<ObstacleParameters>(paramRules.param)) {
    case OBSTACLE_SHAPE:
        return QString::number(getShape());
    default:
        return QString();
    }
}

bool Obstacle::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, Obstacle, SimulationAreaTemplateElement);
    DB_OBJECT_IS_INITIALIZED_BOOL(Obstacle);
    switch (static_cast<ObstacleParameters>(paramRules.param)) {
    case OBSTACLE_SHAPE:
    {
        *static_cast<ObstacleShape*>(value) = getShape();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool Obstacle::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,Obstacle, SimulationAreaTemplateElement);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<ObstacleParameters>(paramRules.param)) {
    // For Parameters with SetParamRules    
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, Obstacle);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, Obstacle);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(Obstacle);
    return true;
}

bool Obstacle::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,Obstacle, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<ObstacleParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, Obstacle);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, Obstacle);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool Obstacle::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, Obstacle, SimulationAreaTemplateElement);
    bool ret = false;
    switch (static_cast<ObstacleParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat Obstacle::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT_TEMPLATE_ELEMENT = object
    case OBSTACLE_SHAPE:
    {

    }
    default:
        break;
    }
    return SimulationAreaTemplateElement::checkParamAndProccess(param, value, dbObjectParamRules);
}



