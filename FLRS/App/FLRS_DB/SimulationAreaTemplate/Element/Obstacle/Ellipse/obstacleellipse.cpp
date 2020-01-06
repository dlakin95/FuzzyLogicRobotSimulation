
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

ObstacleEllipse::ObstacleEllipse(uint numbOfParams) : Obstacle(numbOfParams + NUMB_OF_OBSTACLE_ELLIPSE_PARAMETERS){
    (*(initializedParameters + DB_GET_REAL_PARAM(ObstacleEllipse, OBSTACLE_ELLIPSE_WIDTH))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(ObstacleEllipse, OBSTACLE_ELLIPSE_HEIGHT))) = true;
}


ObstacleEllipse::ObstacleEllipse(DataBaseObject* obj) : ObstacleEllipse(obj, 0){}

ObstacleEllipse::ObstacleEllipse(DataBaseObject* obj, uint numbOfParams) : Obstacle(obj,numbOfParams + NUMB_OF_OBSTACLE_ELLIPSE_PARAMETERS){

}

// _DESTRUCTORS_ ObstacleEllipse.cpp
ObstacleEllipse::~ObstacleEllipse(){

}

// _PRIVATE_METHODS_ ObstacleEllipse.cpp


// _PUBLIC_METHODS_ ObstacleEllipse.cpp
const QString ObstacleEllipse::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, ObstacleEllipse, Obstacle);
    switch(static_cast<ObstacleEllipseParameters>(param)){
    DB_GET_PARAM_NAME(OBSTACLE_ELLIPSE_WIDTH);
    DB_GET_PARAM_NAME(OBSTACLE_ELLIPSE_HEIGHT);
    default:
        return QString();
    }
}

QString ObstacleEllipse::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,ObstacleEllipse, Obstacle);
    DB_OBJECT_IS_INITIALIZED_QSTRING(ObstacleEllipse);
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    case OBSTACLE_ELLIPSE_WIDTH:
        return QString::number(rect().width());
    case OBSTACLE_ELLIPSE_HEIGHT:
        return QString::number(rect().height());
    default:
        return QString();
    }
}

bool ObstacleEllipse::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, ObstacleEllipse, Obstacle);
    DB_OBJECT_IS_INITIALIZED_BOOL(ObstacleEllipse);
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    case OBSTACLE_ELLIPSE_WIDTH:
    {
        *static_cast<qreal*>(value) = rect().width();
    }
        break;
    case OBSTACLE_ELLIPSE_HEIGHT:
    {
        *static_cast<qreal*>(value) = rect().height();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool ObstacleEllipse::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,ObstacleEllipse, Obstacle);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case OBSTACLE_ELLIPSE_WIDTH:
    {
        ret = true;
        setRect(QRectF(QPointF(0,0), QSizeF(*static_cast<qreal*>(value), rect().height())));
    }
        break;
    case OBSTACLE_ELLIPSE_HEIGHT:
    {
        ret = true;
        setRect(QRectF(QPointF(0,0), QSizeF(rect().width(), *static_cast<qreal*>(value))));
    }
        break;
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
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,ObstacleEllipse, Obstacle);
    bool ret = false;
    switch (static_cast<ObstacleEllipseParameters>(paramRules.param)) {
    case OBSTACLE_ELLIPSE_WIDTH:
    {
        ret = true;
        setRect(QRectF(QPointF(0,0), QSizeF(str.toDouble(), rect().height())));
    }
        break;
    case OBSTACLE_ELLIPSE_HEIGHT:
    {
        ret = true;
        setRect(QRectF(QPointF(0,0), QSizeF(rect().width(), str.toDouble())));
    }
        break;
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
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, ObstacleEllipse, Obstacle);
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
    case PARAM_LENGTH_5:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(OBSTACLE_ELLIPSE_WIDTH), PARAM_LENGTH_5){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(ObstacleEllipse, OBSTACLE_ELLIPSE_WIDTH, value, dbObjectParamRules);
        }
    }
        break;
    case PARAM_LENGTH_6:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(OBSTACLE_ELLIPSE_HEIGHT), PARAM_LENGTH_6){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(ObstacleEllipse, OBSTACLE_ELLIPSE_HEIGHT, value, dbObjectParamRules);
        }
    }
        break;
    default:
        break;
    }
    return SimulationAreaTemplateElement::checkParamAndProccess(param, value, dbObjectParamRules);
}


bool ObstacleEllipse::sceneEventFilter(QGraphicsItem *obj, QEvent *ev){


    // CALL ELEMENT EVENT FILTER
    return Obstacle::sceneEventFilter(obj, ev);
}
