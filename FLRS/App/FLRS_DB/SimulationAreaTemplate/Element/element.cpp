
// _INCLUDES_ SimulationAreaTemplateElement.cpp -------------------------------------------------------------------------------------------------------------------
#include"element.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../../flrsdatabase.hpp"
#include<QEvent>
#include<QMouseEvent>
//#include"Rect/rect.hpp"
#include"SimulationArea/Rect/SARect.hpp"
#include"Elipse/Robot/robot.hpp"
#include"Obstacle/obstacle.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplateElement -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplateElement::optionality[];
constexpr bool SimulationAreaTemplateElement::paramIsObject[];

// _CONSTRUCTORS_ SimulationAreaTemplateElement.cpp
SimulationAreaTemplateElement::SimulationAreaTemplateElement() : DataBaseObject(static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT)), NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS){
    //QPen outlinePen(Qt::black);
    //outlinePen.setWidth(2);
    //addRect(0, 0, 80, 100, outlinePen);
    //setSceneRect(QRect(QPoint(-100, 100), QPoint(100, -100)));    
}

SimulationAreaTemplateElement::SimulationAreaTemplateElement(uint numbOfParams) : DataBaseObject(static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT)),numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS){
    SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), UINT_MAX, SET_PARAM_ACTION_ADD};
    QString name = QString("Element");
    setParam(name, spr);
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_X))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_Y))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE))) = true;

}

SimulationAreaTemplateElement::SimulationAreaTemplateElement(DataBaseObject* obj) : DataBaseObject(*obj, static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT)), NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS){
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE))) = true;

}

SimulationAreaTemplateElement::SimulationAreaTemplateElement(DataBaseObject* obj, uint numbOfParams) : DataBaseObject(*obj, static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT)),numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS){
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE))) = true;
    (*(initializedParameters + DB_GET_REAL_PARAM(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE))) = true;

}

// _DESTRUCTORS_ SimulationAreaTemplateElement.cpp
SimulationAreaTemplateElement::~SimulationAreaTemplateElement(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);
    //ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

// _PRIVATE_METHODS_ SimulationAreaTemplateElement.cpp


// _PUBLIC_METHODS_ SimulationAreaTemplateElement.cpp

const QString SimulationAreaTemplateElement::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaTemplateElement, DataBaseObject);
    switch(static_cast<SimulationAreaTemplateElementParameters>(param)){
    case SIMULATION_AREA_TEMPLATE_ELEMENT_X:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_X);
    case SIMULATION_AREA_TEMPLATE_ELEMENT_Y:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_Y);
    case SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION);
    case SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE);
    case SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE:
        return DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE);
    default:
        return QString();
    }
}

QString SimulationAreaTemplateElement::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaTemplateElement, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaTemplateElement);
    if(getElementType() == SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE)
        return QString();
    switch (static_cast<SimulationAreaTemplateElementParameters>(paramRules.param)) {
    case SIMULATION_AREA_TEMPLATE_ELEMENT_X:
        return QString::number(curItem()->x());
    case SIMULATION_AREA_TEMPLATE_ELEMENT_Y:
        return QString::number(curItem()->y());
    case SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE:
        return QString::number(getElementType());
    case SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION:
        return QString::number(curItem()->rotation());
    case SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE:
        return QString::number(getShape());
    default:
        return QString();
    }
}

bool SimulationAreaTemplateElement::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaTemplateElement, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaTemplateElement);
    if(getElementType() == SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<SimulationAreaTemplateElementParameters>(paramRules.param)) {
    case SIMULATION_AREA_TEMPLATE_ELEMENT_X:
    {
        *static_cast<qreal*>(value) = curItem()->x();
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_Y:
    {
        *static_cast<qreal*>(value) = curItem()->y();
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION:
    {
        *static_cast<qreal*>(value) = curItem()->rotation();
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE:
    {
        *static_cast<uint*>(value) = getElementType();
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE:
    {
        *static_cast<uint*>(value) = getShape();
    }
        break;
    default:
        return false;
    }
    return true;
}

bool SimulationAreaTemplateElement::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaTemplateElement, DataBaseObject);
    bool ret = false;
    bool setParamId = false;
    if(getElementType() == SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<SimulationAreaTemplateElementParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    case SIMULATION_AREA_TEMPLATE_ELEMENT_X:
    {
         curItem()->setX(*static_cast<qreal*>(value));
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_Y:
    {
         curItem()->setY(*static_cast<qreal*>(value));
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION:
    {
        curItem()->setRotation(*static_cast<qreal*>(value));
    }
        break;
    default:
        return false;
    }
    ret = true;
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElement);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElement);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaTemplateElement);
    return true;
}

bool SimulationAreaTemplateElement::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaTemplateElement, DataBaseObject);
    bool ret = false;
    if(getElementType() == SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<SimulationAreaTemplateElementParameters>(paramRules.param)) {
    case SIMULATION_AREA_TEMPLATE_ELEMENT_X:
    {
         curItem()->setX(static_cast<qreal>(str.toDouble()));
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_Y:
    {
         curItem()->setY(static_cast<qreal>(str.toDouble()));
    }
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION:
    {
        curItem()->setRotation(static_cast<qreal>(str.toDouble()));
    }
        break;
    default:
        return false;
    }
    ret = true;
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplateElement);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplateElement);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaTemplateElement::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaTemplateElement, DataBaseObject);
    bool ret = false;
    if(getElementType() == SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE)
        return false;
    switch (static_cast<SimulationAreaTemplateElementParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaTemplateElement::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;    
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    case PARAM_LENGTH_1:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_X), PARAM_LENGTH_1){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_X, value, dbObjectParamRules);
        }
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_Y), PARAM_LENGTH_1){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_Y, value, dbObjectParamRules);
        }
    }
        break;
    case PARAM_LENGTH_5:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE), PARAM_LENGTH_5){
            return DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE;
        }
    }
        break;
    case PARAM_LENGTH_8:
    {
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE), PARAM_LENGTH_8){
            return DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE;
        }
        CHECK_PARAM_DECISION_BLOCK(param, DB_OBJECT_MACRO_ACCESS_NAME(SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION), PARAM_LENGTH_8){
            DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(SimulationAreaTemplateElement, SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION, value, dbObjectParamRules);
        }
    }
        break;
    default:
        break;
    }
    return DataBaseObject::checkParamAndProccess(param, value, dbObjectParamRules);
}


DataBaseObject* SimulationAreaTemplateElement::createObject(uint newType){
    DataBaseObject* newObj = nullptr;
    if(getElementType() != SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE)
        return nullptr;
    switch(newType){
    case SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_ROBOT:
        newObj = new SimulationAreaTemplateElementRobot(this);
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_OBSTACLE:
        newObj = new Obstacle(this);
        break;
    case SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_SIMULATION_AREA:
        newObj = new SimulationAreaRect(this);
        break;
    default:
        break;
    }
    return newObj;
}

SimulationAreaTemplate* SimulationAreaTemplateElement::scene()
{
    return ((curItem())? static_cast<SimulationAreaTemplate*>(curItem()->scene()) : nullptr);
}

bool SimulationAreaTemplateElement::sceneEventFilter(QGraphicsItem *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::GraphicsSceneMouseMove:
    {
        scene()->sceneChangeByMoveItem(obj);

    }
        break;
    }

}
