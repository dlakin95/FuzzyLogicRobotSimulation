
// _INCLUDES_ SimulationAreaTemplate.cpp -------------------------------------------------------------------------------------------------------------------
#include"simulationareatemplate.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../flrsdatabase.hpp"
#include"Element/element.hpp"
#include<QEvent>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include"App/AppWindow/SimulationAreaTemplatePanel/templatepanel.hpp"
#include<QDebug>
#include"EventChangeMode/eventcm.hpp"
#include<QGraphicsItem>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplate -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplate::optionality[];
constexpr bool SimulationAreaTemplate::paramIsObject[];


// _CONSTRUCTORS_ SimulationAreaTemplate.cpp
SimulationAreaTemplate::SimulationAreaTemplate() : DataBaseObject(static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE)), NUMB_OF_SIMULATION_AREA_TEMPLATE_PARAMETERS), QGraphicsScene(){
    //addRect(QRect())
    installEventFilter(this);
}

SimulationAreaTemplate::SimulationAreaTemplate(DataBaseObject* obj) : DataBaseObject(*obj, static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE)), NUMB_OF_SIMULATION_AREA_TEMPLATE_PARAMETERS), QGraphicsScene(){
    installEventFilter(this);
}

// _DESTRUCTORS_ SimulationAreaTemplate.cpp
SimulationAreaTemplate::~SimulationAreaTemplate(){
    //SET_PTR_DO(dataBaseGeneralInformation, nullptr);
    SET_PTR_DO(curMode, nullptr);
    ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

// _PRIVATE_METHODS_ SimulationAreaTemplate.cpp


// _PUBLIC_METHODS_ SimulationAreaTemplate.cpp
GET_DEFINITION(SimulationAreaTemplate, bool, changedFlag)

const QString SimulationAreaTemplate::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, SimulationAreaTemplate, DataBaseObject);
    switch(static_cast<SimulationAreaTemplateParameters>(param)){
    default:
        return QString();
    }
}

QString SimulationAreaTemplate::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,SimulationAreaTemplate, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_QSTRING(SimulationAreaTemplate);
    switch (static_cast<SimulationAreaTemplateParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool SimulationAreaTemplate::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, SimulationAreaTemplate, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_BOOL(SimulationAreaTemplate);
    switch (static_cast<SimulationAreaTemplateParameters>(paramRules.param)) {
    default:
        return false;
    }
    return true;
}

bool SimulationAreaTemplate::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,SimulationAreaTemplate, DataBaseObject);
    bool ret = false;
    bool setParamId = false;
    switch (static_cast<SimulationAreaTemplateParameters>(paramRules.param)) {
    // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplate);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplate);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    DB_SET_PARAM_ID(SimulationAreaTemplate);
    return true;
}

bool SimulationAreaTemplate::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,SimulationAreaTemplate, DataBaseObject);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, SimulationAreaTemplate);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, SimulationAreaTemplate);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool SimulationAreaTemplate::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, SimulationAreaTemplate, DataBaseObject);
    bool ret = false;
    switch (static_cast<SimulationAreaTemplateParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

DataBaseFileOperationStat SimulationAreaTemplate::checkParamAndProccess(QString &param, QString &value, DataBaseObjectsReadFileContainer* dbObjectParamRules){
    CHECK_PARAM_INIT;
    switch (param.length()) {
    // SIMULATION_AREA_TEMPLATE_ELEMENT = object
    default:
        break;
    }
    return DataBaseObject::checkParamAndProccess(param, value, dbObjectParamRules);
}

void SimulationAreaTemplate::activateMode(SimulationAreaTemplateModeType type, uint phase){
    deactivateCurMode();
    SET_PTR_NDO(curMode, new SimulationAreaTemplateMode{type});
    // Init Sequance
    switch(type){
    case SIMULATION_AREA_TEMPLATE_MODE_DEFAULT:
    {

    }
        break;
    case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT:
    {

    }
        break;
    case SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT:
    {   // Current Size 64x64  - Item
        // Track Mouse Move to Redraw Matrix Position
        for(int i = 0; i < views().size(); i++){
            views().at(i)->setMouseTracking(true);
        }
        //curMode->tempElement = new SimulationAreaTemplateElementRect();
        qDebug() << "Scene Active MOde";
        qDebug() << this;
        qDebug() << static_cast<QGraphicsItem*>(static_cast<void*>(curMode->tempElement));
        addItem(static_cast<QGraphicsItem*>(static_cast<void*>(curMode->tempElement)));
    }
        break;
    }
}

void SimulationAreaTemplate::deactivateCurMode(){
    // DeInit Sequance
    if(curMode){
        switch(curMode->type){
        case SIMULATION_AREA_TEMPLATE_MODE_DEFAULT:
        {

        }
            break;
        case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT:
        {

        }
            break;
        case SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT:
        {
            for(int i = 0; i < views().size(); i++){
                views().at(i)->setMouseTracking(true);
            }
            SET_PTR_DO(curMode->tempElement, nullptr);
        }
            break;
        }
    }
    // --------------
    SET_PTR_DO(curMode, nullptr);
}

bool SimulationAreaTemplate::eventFilter(QObject *obj, QEvent *ev){
    // Process Cur Mode Events
    if(ev->type() == SimulationAreaTemplateEventChangeMode::SimulationAreaTemplateChangeMode)
        activateMode(static_cast<SimulationAreaTemplateEventChangeMode*>(ev)->get_newModeType(), static_cast<SimulationAreaTemplateEventChangeMode*>(ev)->get_phase());
    if(curMode){
        switch (curMode->type) {
        case SIMULATION_AREA_TEMPLATE_MODE_DEFAULT:
        {

        }
            break;
        case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT:
        {

        }
            break;
        case SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT:
        {   // SINGLE PHASE MODE
            switch(ev->type()){
                case QEvent::GraphicsSceneMouseMove:
                {
                    curMode->tempElement->get_object()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
                }
                break;
                case QEvent::GraphicsSceneMouseRelease:
                {
                    if(static_cast<QGraphicsSceneMouseEvent*>(ev)->buttons() == Qt::LeftButton)
                    {
                        curMode->tempElement->get_object()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
                        curMode->tempElement = nullptr;
                        deactivateCurMode();
                    }else if(static_cast<QGraphicsSceneMouseEvent*>(ev)->buttons() == Qt::LeftButton){
                        deactivateCurMode();
                    }
                }
                break;
            }
        }
            break;
        }
    }else{
        qDebug() << "CurMode = nullptr";
    }
    return QGraphicsScene::eventFilter(obj, ev);
}

