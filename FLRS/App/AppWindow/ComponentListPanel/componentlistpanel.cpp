// _INCLUDES_ ComponentListPanel.cpp -------------------------------------------------------------------------------------------------------------------
#include "componentlistpanel.hpp"
#include"../appwindow.hpp"
#include"componentlistelement.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include"componentlistelementlist.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include"../../app.hpp"
#include<QPainter>
#include<QPen>
#include"App/FLRS_DB/flrsdatabase.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ ComponentListPanel -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ ComponentListPanel.cpp
ComponentListPanel::ComponentListPanel(AppWindow* parent) : QScrollArea (parent), parent(parent), list(this)
{
  initalize();
}

// _DESTRUCTORS_ ComponentListPanel.cpp
ComponentListPanel::~ComponentListPanel(){
    clearMemory();
}

// _PRIVATE_METHODS_ ComponentListPanel.cpp
void ComponentListPanel::initalize(){
    createObjects();
    createLayout();
    connectEvents();
}

void ComponentListPanel::createObjects(){

}

void ComponentListPanel::createLayout(){
    setStyleSheet("background-color: transparent");
    verticalScrollBar()->setStyleSheet("QScrollBar::vertical{background: transparent; width: 5px;} QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical, QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical, QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{border: none; background: none; color: none;} QScrollBar::handle:vertical{background-color: white; border: 1px solid black;}");
    setFrameShape(QFrame::NoFrame);
    setWidget(&list);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    show();
}

void ComponentListPanel::connectEvents(){
    installEventFilter(this);
}

void ComponentListPanel::clearMemory(){

}
/*
void ComponentListPanel::createContextMenu(QAction *actions){
    // Action 1 (0) Add Test Group
    (actions + 0)->setText("Add Category");
    (actions + 0)->setParent(this);
}

void ComponentListPanel::execContextMenu(QPoint& eventPos){
    QMenu menu;
    QAction action[1];
    createContextMenu(action);
    uint i = 0;
    for( ; i < 1; i++){
        menu.addAction(action + i);
    }
    QAction* at = nullptr;
    at = menu.exec(eventPos);
    for(i = 0; i < 1; i++){
        if(at == action + i)
            break;
    }
    switch(i){
    case 0:
    {
        addNewDbObj(new DataBaseCategory());
     }
        break;
    default:
        break;
    }
}
*/
// _PUBLIC_METHODS_ ComponentListPanel.cpp
GET_DEFINITION(ComponentListPanel, AppWindow*, parent)
GET_DEFINITION(ComponentListPanel, ComponentList&, list)

void ComponentListPanel::resizeEvent(QResizeEvent *ev){
    list.resize(LO_DATABASE_VIEWER_LIST_SIZE(LAYOUT_CURRENT_HEIGHT));
}

void ComponentListPanel::reload(){
    SimulationAreaTemplate* curPicture = nullptr;
    SimulationAreaTemplate* curPictureListElement = static_cast<SimulationAreaTemplate*>(parent->get_simulationAreaTemplatesListPanel().get_list().get_currentElementRefObj());
    if(list.get_elements() && list.get_numbOfElements() > 0)
        curPicture = static_cast<SimulationAreaTemplate*>((*list.get_elements())->get_refObj());
    // Element Changed - Reload List
    if(curPicture != curPictureListElement){
        if(curPictureListElement->getObjectType() == DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE)){
            clearAndLoad(curPictureListElement);
        }else{
            clear();
        }
    }
}

void ComponentListPanel::clear(){
    list.clearElements();
}

bool ComponentListPanel::load(SimulationAreaTemplate *db){
    return list.load(db);
}

bool ComponentListPanel::clearAndLoad(SimulationAreaTemplate *db){
    list.clearElements();
    return list.load(db);
}
/*
bool ComponentListPanel::clearAndLoadDbObj(DataBaseObject *dbObj){
    list.clearElements();
    list.loadDBObject(dbObj);
}

bool ComponentListPanel::loadDbObj(DataBaseObject *dbObj){
    list.loadDBObject(dbObj);
}
*/
ComponentListElement* ComponentListPanel::createElement(DataBaseObject* refObj, ComponentListElement* refObjParent){
    return ComponentListPanel::createElement(refObj, refObjParent, refObj->getObjectType());
}

ComponentListElement* ComponentListPanel::createElement(DataBaseObject* refObj, ComponentListElement* refObjParent, uint type){
    switch(type){
    //case DATABASE_OBJECT_CATEGORY:
    //    return (new ComponentListElementList(&list, refObj, refObjParent))->allowUpdate();
    case DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE_ELEMENT):
        return (new ComponentListElement(&list, refObj, refObjParent))->allowUpdate();
    case DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE):
        return (new ComponentListElementList(&list, refObj, refObjParent))->allowUpdate();
    default:
        break;
    }
    return nullptr;
}

bool ComponentListPanel::eventFilter(QObject *obj, QEvent *ev){
    // Events Catched by ComponentListPanel
    // - Mouse Pressed (Right Button on ComponentListPanel widget, call function execContextMenu)
    switch(ev->type()){
    /*case QEvent::MouseButtonPress:
    {

    }
        break;
    case QEvent::MouseButtonRelease:
    {
        if(!list.get_elementAtEditMode()){
            if(obj == this && static_cast<QMouseEvent*>(ev)->button() == Qt::RightButton){
                QPoint point = static_cast<QMouseEvent*>(ev)->globalPos();
                execContextMenu(point);
                return true;
            }
        }
    }
        break;*/
    default:
        break;
    }
    return QScrollArea::eventFilter(obj, ev);
}

void ComponentListPanel::paintEvent(QPaintEvent *ev){
    QPainter p(viewport());
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}
// ----------------------------------------------------------------------------------------------------------------------------------------------
