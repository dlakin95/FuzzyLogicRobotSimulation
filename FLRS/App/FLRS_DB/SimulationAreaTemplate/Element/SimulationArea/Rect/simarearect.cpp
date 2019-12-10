
// _INCLUDES_ SimulationAreaRect.cpp -------------------------------------------------------------------------------------------------------------------
#include"SARect.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaRect -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaRect::optionality[];
constexpr bool SimulationAreaRect::paramIsObject[];

// _CONSTRUCTORS_ SimulationAreaRect.cpp
SimulationAreaRect::SimulationAreaRect() : SimulationAreaRect(static_cast<uint>(0)){}

SimulationAreaRect::SimulationAreaRect(uint numbOfParams) : SimulationArea(numbOfParams + NUMB_OF_SIMULATION_AREA_PARAMETERS){

}


SimulationAreaRect::SimulationAreaRect(DataBaseObject* obj) : SimulationAreaRect(obj, 0){}

SimulationAreaRect::SimulationAreaRect(DataBaseObject* obj, uint numbOfParams) : SimulationArea(obj,numbOfParams + NUMB_OF_SIMULATION_AREA_PARAMETERS){

}

// _DESTRUCTORS_ SimulationAreaRect.cpp
SimulationAreaRect::~SimulationAreaRect(){

}

// _PRIVATE_METHODS_ SimulationAreaRect.cpp


// _PUBLIC_METHODS_ SimulationAreaRect.cpp
const QString SimulationAreaRect::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaRect, SimulationArea);
    switch(static_cast<SimulationAreaRectParameters>(param)){
    case SIMULATION_AREA_RECT_WIDTH:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_RECT_WIDTH);
    case SIMULATION_AREA_RECT_HEIGHT:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_RECT_HEIGHT);
    default:
        return QString();
    }
}

QString SimulationAreaRect::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaRect, SimulationArea);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaRect);
    switch (static_cast<SimulationAreaRectParameters>(paramRules.param)) {
    case SIMULATION_AREA_RECT_WIDTH:
        return QString::number(rect().width());
    case SIMULATION_AREA_RECT_HEIGHT:
        return QString::number(rect().height());
    default:
        return QString();
    }
}

bool SimulationAreaRect::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaRect, SimulationArea);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaRect);
    switch (static_cast<SimulationAreaRectParameters>(paramRules.param)) {
    case SIMULATION_AREA_RECT_WIDTH:
    {
        *static_cast<qreal*>(value) = rect().width();
    }
        break;
    case SIMULATION_AREA_RECT_HEIGHT:
    {
        *static_cast<qreal*>(value) = rect().height();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool SimulationAreaRect::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaRect, SimulationArea);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaRectParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case SIMULATION_AREA_RECT_WIDTH:
    {
         setRect(QRectF(rect().topLeft(), QSize(*static_cast<qreal*>(value), rect().height())));
    }
        break;
    case SIMULATION_AREA_RECT_HEIGHT:
    {
         setRect(QRectF(rect().topLeft(), QSize(rect().width(), *static_cast<qreal*>(value))));
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaRect);
    return true;
}

bool SimulationAreaRect::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaRect, SimulationArea);
    bool ret = false;
    switch (static_cast<SimulationAreaRectParameters>(paramRules.param)) {
    case SIMULATION_AREA_RECT_WIDTH:
    {
         setRect(QRectF(rect().topLeft(), QSize(str.toDouble(), rect().height())));
    }
        break;
    case SIMULATION_AREA_RECT_HEIGHT:
    {
         setRect(QRectF(rect().topLeft(), QSize(rect().width(), str.toDouble())));
    }
        break;
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaRect::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaRect, SimulationArea);
    bool ret = false;
    switch (static_cast<SimulationAreaRectParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaRect::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    case PARAM_LENGTH_5:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_RECT_WIDTH), PARAM_LENGTH_5){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(SimulationAreaRect, SIMULATION_AREA_RECT_WIDTH, value, dbObjectParamRules);
        }
    }
        break;
    case PARAM_LENGTH_6:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_RECT_HEIGHT), PARAM_LENGTH_6){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(SimulationAreaRect, SIMULATION_AREA_RECT_HEIGHT, value, dbObjectParamRules);
        }
    }
        break;
    default:
        break;
    }
    return SimulationArea::checkParamAndProccess(param, value, dbObjectParamRules);
}



