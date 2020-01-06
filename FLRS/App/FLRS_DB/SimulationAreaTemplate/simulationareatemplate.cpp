
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
#include"App/FLRS_DB/SimulationAreaTemplate/Element/Elipse/Robot/robot.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Rect/obstaclerect.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/Element/Obstacle/Ellipse/obstacleellipse.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/Element/SimulationArea/Rect/SARect.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplate -----------------------------------------------------------------------------------------------------------------------------------------------

// Static Members
constexpr bool SimulationAreaTemplate::optionality[];
constexpr bool SimulationAreaTemplate::paramIsObject[];


// _CONSTRUCTORS_ SimulationAreaTemplate.cpp
SimulationAreaTemplate::SimulationAreaTemplate() : SimulationAreaTemplate(static_cast<uint>(0)){
    //addRect(QRect())
    installEventFilter(this);
}

SimulationAreaTemplate::SimulationAreaTemplate(uint numbOfParams) : DataBaseObject(static_cast<DatabaseObjectType>(DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE)), numbOfParams + NUMB_OF_SIMULATION_AREA_TEMPLATE_PARAMETERS), QGraphicsScene(){
    //setSceneRect(QRectF(QPoint(-1000,-1000), QSize(2000, 2000)));
    //sceneRectItem.setRect(sceneRect());
    //addItem(&sceneRectItem);
    //qDebug() << "Bounding Rect";
    //qDebug() << tempItemsBoundingRect;
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
GET_DEFINITION(SimulationAreaTemplate, QRectF, tempItemsBoundingRect)

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
    case SIMULATION_AREA_TEMPLATE_ELEMENTS:
    {
        if(paramRules.index < numbOfElements)
        {
            if(paramRules.index + 1 < numbOfElements)
                paramRules.nextAvailable = true;
            *static_cast<SimulationAreaTemplateElement**>(value) = (*(elements + paramRules.index));
        }else{
            return false;
        }
    }
        break;
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
    case SIMULATION_AREA_TEMPLATE_ELEMENTS:
    {
        switch(paramRules.action){
        case SET_PARAM_ACTION_ADD:
        {
            setParamId = true;
            if(!(numbOfElements == UINT_MAX || (*static_cast<DataBaseObject**>(value))->getObjectType() != DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT) || (*static_cast<SimulationAreaTemplateElement**>(value))->getElementType() == SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE))
            {
                if(!(ret = addElement(*static_cast<SimulationAreaTemplateElement**>(value)))){
                    return  false;
                }
                addItem((*static_cast<SimulationAreaTemplateElement**>(value))->curItem());
                if((*static_cast<SimulationAreaTemplateElement**>(value))->curItem())
                    (*static_cast<SimulationAreaTemplateElement**>(value))->curItem()->installSceneEventFilter((*static_cast<SimulationAreaTemplateElement**>(value))->curItem());
                sceneChangeByAddItem((*static_cast<SimulationAreaTemplateElement**>(value))->curItem());
                tempItemsBoundingRect = itemsBoundingRect();
                ret = true;
            }
        }
            break;
        case SET_PARAM_ACTION_REMOVE:
        {
            removeItem((*static_cast<SimulationAreaTemplateElement**>(value))->curItem());
            if(removeElement((*static_cast<SimulationAreaTemplateElement**>(value)))){
                ret = true;
            }
        }
            break;
        default:
            return false;
        }
    }
        break;
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
    case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_OBSTACLE:
    case SIMULATION_AREA_TEMPLATE_MODE_DRAW_ELIPSE_OBSTACLE:
    case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_SIMULATION_AREA:
    {

    }
        break;
    case SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT:
    {
        for(int i = 0; i < views().size(); i++){
            views().at(i)->setMouseTracking(true);
        }
        curMode->tempElement = new SimulationAreaTemplateElementRobot();
        acceptSceneChange = false;
        SetParamRules spr = {DB_GET_REAL_PARAM(SimulationAreaTemplate, SIMULATION_AREA_TEMPLATE_ELEMENTS), UINT_MAX, SET_PARAM_ACTION_ADD};
        if(!setParam(&(curMode->tempElement), spr)){
            SET_PTR_DO(curMode->tempElement, nullptr);
            deactivateCurMode();
        }
        acceptSceneChange = true;
    }
        break;
    }
}

void SimulationAreaTemplate::deactivateCurMode(){
    // DeInit Sequance
    if(curMode){
        switch(curMode->type){
        case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_OBSTACLE:
        case SIMULATION_AREA_TEMPLATE_MODE_DRAW_ELIPSE_OBSTACLE:
        case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_SIMULATION_AREA:
        {
            if(curMode->tempElement){
                SetParamRules spr = {DB_GET_REAL_PARAM(SimulationAreaTemplate, SIMULATION_AREA_TEMPLATE_ELEMENTS), UINT_MAX, SET_PARAM_ACTION_REMOVE};
                if(!setParam(&(curMode->tempElement), spr)){
                    SET_PTR_DO(curMode->tempElement, nullptr);
                    // Internal Error
                }
            }
        }
            break;
        case SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT:
        {
            for(int i = 0; i < views().size(); i++){
                views().at(i)->setMouseTracking(false);
            }
            if(curMode->tempElement){
                SetParamRules spr = {DB_GET_REAL_PARAM(SimulationAreaTemplate, SIMULATION_AREA_TEMPLATE_ELEMENTS), UINT_MAX, SET_PARAM_ACTION_REMOVE};
                if(!setParam(&(curMode->tempElement), spr)){
                    SET_PTR_DO(curMode->tempElement, nullptr);
                    // Internal Error
                }
            }
        }
            break;
        }
    }
    // --------------
    SET_PTR_DO(curMode, nullptr);
    changedFlag = true;
}

bool SimulationAreaTemplate::eventFilter(QObject *obj, QEvent *ev){
    // Process Cur Mode Events
    if(ev->type() == SimulationAreaTemplateEventChangeMode::SimulationAreaTemplateChangeMode)
        activateMode(static_cast<SimulationAreaTemplateEventChangeMode*>(ev)->get_newModeType(), static_cast<SimulationAreaTemplateEventChangeMode*>(ev)->get_phase());
    if(curMode){
        switch (curMode->type) {
        case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_OBSTACLE:
        {
            switch(static_cast<SimulationAreaTemplateModeDrawRectPhase>(curMode->phase)){
            case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_PHASE_START_POINT:
            {
                switch(ev->type()){
                case QEvent::GraphicsSceneMousePress:
                {
                    if(static_cast<QGraphicsSceneMouseEvent*>(ev)->buttons() & Qt::LeftButton){
                        curMode->phase = SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_PHASE_END_POINT;
                        curMode->tempElement = new ObstacleRect();
                        curMode->tempElement->curItem()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
                        static_cast<ObstacleRect*>(curMode->tempElement->curItem())->setRect(QRectF(QPointF(0,0),QSize(1,1)));
                        curMode->tempElement->curItem()->show();
                        acceptSceneChange = false;
                        SetParamRules spr = {DB_GET_REAL_PARAM(SimulationAreaTemplate, SIMULATION_AREA_TEMPLATE_ELEMENTS), UINT_MAX, SET_PARAM_ACTION_ADD};
                        if(!setParam(&(curMode->tempElement), spr)){
                            SET_PTR_DO(curMode->tempElement, nullptr);
                            deactivateCurMode();
                        }
                        acceptSceneChange = true;

                    }
                }
                    break;
                case QEvent::GraphicsSceneMouseRelease:
                {
                    if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::RightButton)
                        deactivateCurMode();
                }
                    break;
                }
            }
                break;
            case SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_PHASE_END_POINT:
            {
                switch (ev->type()) {
                case QEvent::GraphicsSceneMouseMove:
                {
                    if(static_cast<QGraphicsSceneMouseEvent*>(ev)->buttons() & Qt::LeftButton)
                    {
                        static_cast<ObstacleRect*>(curMode->tempElement->curItem())->setRect(QRectF(QPointF(0,0), static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos() - curMode->tempElement->curItem()->pos()));

                    }
                }
                break;
                case QEvent::GraphicsSceneMouseRelease:
                {
                    if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::LeftButton)
                    {
                        static_cast<ObstacleRect*>(curMode->tempElement->curItem())->setRect(QRectF(QPointF(0,0), static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos() - curMode->tempElement->curItem()->pos()));
                        sceneChangeByAddItem(curMode->tempElement->curItem());
                        curMode->tempElement = nullptr;
                        deactivateCurMode();
                    }else if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::RightButton){
                        deactivateCurMode();
                    }
                }
                break;
                case QEvent::Enter:
                {
                    if(obj == this){
                        curMode->tempElement->curItem()->show();
                    }
                }
                    break;
                case QEvent::Leave:
                {
                    if(obj == this){
                        curMode->tempElement->curItem()->hide();
                    }
                }
                    break;
                }
            }
                break;
            }
        }
            break;
        case SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT:
        {   // SINGLE PHASE MODE
            switch(ev->type()){
            case QEvent::GraphicsSceneMouseMove:
            {
                curMode->tempElement->curItem()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
            }
            break;
            case QEvent::Enter:
            {
                if(obj == this){
                    curMode->tempElement->curItem()->show();
                }
            }
                break;
            case QEvent::Leave:
            {
                if(obj == this){
                    curMode->tempElement->curItem()->hide();
                }
            }
                break;
            case QEvent::GraphicsSceneMouseRelease:
            {
                if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::LeftButton)
                {
                    curMode->tempElement->curItem()->setPos(static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
                    sceneChangeByAddItem(curMode->tempElement->curItem());
                    curMode->tempElement = nullptr;
                    deactivateCurMode();
                }else if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() == Qt::RightButton){
                    deactivateCurMode();
                }
            }
            break;
            }
        }
            break;
        }
    }
    // Modes Independant Events Filter
    switch(ev->type()){
    case QEvent::GraphicsSceneMouseMove:
    {
        if(static_cast<QGraphicsSceneMouseEvent*>(ev)->buttons() & Qt::MiddleButton){
            QPointF delta = lastMPos - (static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos());
            lastMPos = static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos() + delta;
            QRectF rect = sceneRect();
            rect.translate(delta);
            setSceneRect(rect);
        }
    }
        break;
    case QEvent::GraphicsSceneMousePress:
    {
        if(static_cast<QGraphicsSceneMouseEvent*>(ev)->buttons() & Qt::MiddleButton){
            lastMPos = static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos();
            //startTimer();
        }
    }
        break;
    case QEvent::GraphicsSceneMouseRelease:
    {
        if(static_cast<QGraphicsSceneMouseEvent*>(ev)->button() & Qt::MiddleButton){
            lastMPos = static_cast<QGraphicsSceneMouseEvent*>(ev)->scenePos();
            //endTimer();
        }


    }
        break;
    }
    return QGraphicsScene::eventFilter(obj, ev);
}

