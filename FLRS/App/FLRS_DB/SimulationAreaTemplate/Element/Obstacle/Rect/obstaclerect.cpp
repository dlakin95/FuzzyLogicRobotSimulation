
// _INCLUDES_ ObstacleRect.cpp -------------------------------------------------------------------------------------------------------------------
#include"obstaclerect.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QEvent>
#include<QMouseEvent>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ ObstacleRect -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool ObstacleRect::optionality[];
constexpr bool ObstacleRect::paramIsObject[];

// _CONSTRUCTORS_ ObstacleRect.cpp
ObstacleRect::ObstacleRect() : ObstacleRect(static_cast<uint>(0)){}

ObstacleRect::ObstacleRect(uint numbOfParams) : Obstacle(numbOfParams + NUMB_OF_OBSTACLE_RECT_PARAMETERS), QGraphicsRectItem(){
    (*(initializedParameters + DB_GET_REAL_PARAM(ObstacleRect, OBSTACLE_RECT_WIDTH))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(ObstacleRect, OBSTACLE_RECT_HEIGHT))) = true;


}


ObstacleRect::ObstacleRect(DataBaseObject* obj) : ObstacleRect(obj, 0){}

ObstacleRect::ObstacleRect(DataBaseObject* obj, uint numbOfParams) : Obstacle(obj,numbOfParams + NUMB_OF_OBSTACLE_RECT_PARAMETERS), QGraphicsRectItem(){
    (*(initializedParameters + DB_GET_REAL_PARAM(ObstacleRect, OBSTACLE_RECT_WIDTH))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(ObstacleRect, OBSTACLE_RECT_HEIGHT))) = true;
}

// _DESTRUCTORS_ ObstacleRect.cpp
ObstacleRect::~ObstacleRect(){

}

// _PRIVATE_METHODS_ ObstacleRect.cpp


// _PUBLIC_METHODS_ ObstacleRect.cpp
const QString ObstacleRect::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, ObstacleRect, Obstacle);
    switch(static_cast<ObstacleRectParameters>(param)){
    DB_GET_PARAM_NAME(OBSTACLE_RECT_WIDTH);
    DB_GET_PARAM_NAME(OBSTACLE_RECT_HEIGHT);
    default:
        return QString();
    }
}

QString ObstacleRect::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,ObstacleRect, Obstacle);
    DB_OBJECT_IS_INITIALIZED_QSTRING(ObstacleRect);
    switch (static_cast<ObstacleRectParameters>(paramRules.param)) {
    case OBSTACLE_RECT_WIDTH:
        return QString::number(rect().width());
    case OBSTACLE_RECT_HEIGHT:
        return QString::number(rect().height());
    default:
        return QString();
    }
}

bool ObstacleRect::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, ObstacleRect, Obstacle);
    DB_OBJECT_IS_INITIALIZED_BOOL(ObstacleRect);
    switch (static_cast<ObstacleRectParameters>(paramRules.param)) {
    case OBSTACLE_RECT_WIDTH:
    {
        *static_cast<qreal*>(value) = rect().width();
    }
        break;
    case OBSTACLE_RECT_HEIGHT:
    {
        *static_cast<qreal*>(value) = rect().height();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool ObstacleRect::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,ObstacleRect, Obstacle);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<ObstacleRectParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case OBSTACLE_RECT_WIDTH:
    {
        ret = true;
        setRect(QRectF(QPointF(0,0), QSizeF(*static_cast<qreal*>(value), rect().height())));
    }
        break;
    case OBSTACLE_RECT_HEIGHT:
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
            SET_PARAM_RULES_SET_INIT(paramRules, ObstacleRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, ObstacleRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(ObstacleRect);
    return true;
}

bool ObstacleRect::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,ObstacleRect, Obstacle);
    bool ret = false;
    switch (static_cast<ObstacleRectParameters>(paramRules.param)) {
    case OBSTACLE_RECT_WIDTH:
    {
        ret = true;
        setRect(QRectF(QPointF(0,0), QSizeF(str.toDouble(), rect().height())));
    }
        break;
    case OBSTACLE_RECT_HEIGHT:
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
            SET_PARAM_RULES_SET_INIT(paramRules, ObstacleRect);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, ObstacleRect);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool ObstacleRect::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, ObstacleRect, Obstacle);
    bool ret = false;
    switch (static_cast<ObstacleRectParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat ObstacleRect::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // OBSTACLE_RECT_TEMPLATE_ELEMENT = object
    case PARAM_LENGTH_5:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(OBSTACLE_RECT_WIDTH), PARAM_LENGTH_5){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(ObstacleRect, OBSTACLE_RECT_WIDTH, value, dbObjectParamRules);
        }
    }
        break;
    case PARAM_LENGTH_6:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(OBSTACLE_RECT_HEIGHT), PARAM_LENGTH_6){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(ObstacleRect, OBSTACLE_RECT_HEIGHT, value, dbObjectParamRules);
        }
    }
        break;
    default:
        break;
    }
    return Obstacle::checkParamAndProccess(param, value, dbObjectParamRules);
}



bool ObstacleRect::sceneEventFilter(QGraphicsItem *obj, QEvent *ev){


    // CALL ELEMENT EVENT FILTER
    Obstacle::sceneEventFilter(obj, ev);
    return QGraphicsRectItem::sceneEventFilter(obj, ev);
}
