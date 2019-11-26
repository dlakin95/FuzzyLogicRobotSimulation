
// _INCLUDES_ SimulationAreaTemplateElementRobot.cpp -------------------------------------------------------------------------------------------------------------------
#include"robot.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplateElementRobot -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplateElementRobot::optionality[];
constexpr bool SimulationAreaTemplateElementRobot::paramIsObject[];

// _CONSTRUCTORS_ SimulationAreaTemplateElementRobot.cpp
SimulationAreaTemplateElementRobot::SimulationAreaTemplateElementRobot() : SimulationAreaTemplateElementRobot(static_cast<uint>(0)){}

SimulationAreaTemplateElementRobot::SimulationAreaTemplateElementRobot(uint numbOfParams) : SimulationAreaTemplateElementElipse(numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS){
    if(object){
        static_cast<QGraphicsEllipseItem*>(object)->setRect(QRectF(object->pos(), QSizeF(31.1, 31.1))); // Cm
    }
}


SimulationAreaTemplateElementRobot::SimulationAreaTemplateElementRobot(DataBaseObject* obj) : SimulationAreaTemplateElementRobot(obj, 0){}

SimulationAreaTemplateElementRobot::SimulationAreaTemplateElementRobot(DataBaseObject* obj, uint numbOfParams) : SimulationAreaTemplateElementElipse(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS){
    if(object){
        static_cast<QGraphicsEllipseItem*>(object)->setRect(QRectF(object->pos(), QSizeF(31.1, 31.1))); // Cm
    }
}

// _DESTRUCTORS_ SimulationAreaTemplateElementRobot.cpp
SimulationAreaTemplateElementRobot::~SimulationAreaTemplateElementRobot(){

}

// _PRIVATE_METHODS_ SimulationAreaTemplateElementRobot.cpp


// _PUBLIC_METHODS_ SimulationAreaTemplateElementRobot.cpp
const QString SimulationAreaTemplateElementRobot::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse);
    switch(static_cast<SimulationAreaTemplateElementRobotParameters>(param)){
    default:
        return QString();
    }
}

QString SimulationAreaTemplateElementRobot::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaTemplateElementRobot);
    switch (static_cast<SimulationAreaTemplateElementRobotParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool SimulationAreaTemplateElementRobot::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaTemplateElementRobot);
    switch (static_cast<SimulationAreaTemplateElementRobotParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool SimulationAreaTemplateElementRobot::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaTemplateElementRobotParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementRobot);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementRobot);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaTemplateElementRobot);
    return true;
}

bool SimulationAreaTemplateElementRobot::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementRobotParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElementRobot);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElementRobot);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaTemplateElementRobot::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateElementRobotParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaTemplateElementRobot::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    default:
        break;
    }
    return SimulationAreaTemplateElementElipse::checkParamAndProccess(param, value, dbObjectParamRules);
}



