// _INCLUDES_ SimulationAreaTemplatesListPanel.cpp -------------------------------------------------------------------------------------------------------------------
#include "listpanel.hpp"
#include"../appwindow.hpp"
#include"listelement.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include"listelementlist.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include"../../app.hpp"
#include<QPainter>
#include<QPen>
#include"App/FLRS_DB/flrsdatabase.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplatesListPanel -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ SimulationAreaTemplatesListPanel.cpp
SimulationAreaTemplatesListPanel::SimulationAreaTemplatesListPanel(AppWindow* parent) : QScrollArea (parent), parent(parent), list(this)
{
  initalize();
}

// _DESTRUCTORS_ SimulationAreaTemplatesListPanel.cpp
SimulationAreaTemplatesListPanel::~SimulationAreaTemplatesListPanel(){
    clearMemory();
}

// _PRIVATE_METHODS_ SimulationAreaTemplatesListPanel.cpp
void SimulationAreaTemplatesListPanel::initalize(){
    createObjects();
    createLayout();
    connectEvents();
}

void SimulationAreaTemplatesListPanel::createObjects(){

}

void SimulationAreaTemplatesListPanel::createLayout(){
    setStyleSheet("background-color: transparent");
    verticalScrollBar()->setStyleSheet("QScrollBar::vertical{background: transparent; width: 5px;} QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical, QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical, QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{border: none; background: none; color: none;} QScrollBar::handle:vertical{background-color: white; border: 1px solid black;}");
    setFrameShape(QFrame::NoFrame);
    setWidget(&list);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    show();
}

void SimulationAreaTemplatesListPanel::connectEvents(){
    installEventFilter(this);
}

void SimulationAreaTemplatesListPanel::clearMemory(){

}

void SimulationAreaTemplatesListPanel::createContextMenu(QAction *actions){
    // Action 1 (0) Add SimulationAreaTemplates Data Base
    (actions + 0)->setText("New SimulationAreaTemplates Catalog");
    (actions + 0)->setParent(this);
}

void SimulationAreaTemplatesListPanel::execContextMenu(QPoint& eventPos){
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
        addNewDbObj(new FuzzyLogicRobotSimulationDataBase());
     }
        break;
    default:
        break;
    }
}

// _PUBLIC_METHODS_ SimulationAreaTemplatesListPanel.cpp
GET_DEFINITION(SimulationAreaTemplatesListPanel, AppWindow*, parent)
GET_DEFINITION(SimulationAreaTemplatesListPanel, SimulationAreaTemplatesList&, list)

void SimulationAreaTemplatesListPanel::resizeEvent(QResizeEvent *ev){
    list.resize(LO_DATABASE_VIEWER_LIST_SIZE(LAYOUT_CURRENT_HEIGHT));
}

void SimulationAreaTemplatesListPanel::clear(){
    list.clearElements();
}

bool SimulationAreaTemplatesListPanel::load(FuzzyLogicRobotSimulationDataBase *db){
    list.load(db);
}

bool SimulationAreaTemplatesListPanel::clearAndLoad(FuzzyLogicRobotSimulationDataBase *db){
    list.clearElements();
    list.load(db);
}
/*
bool SimulationAreaTemplatesListPanel::clearAndLoadDbObj(DataBaseObject *dbObj){
    list.clearElements();
    list.loadDBObject(dbObj);
}

bool SimulationAreaTemplatesListPanel::loadDbObj(DataBaseObject *dbObj){
    list.loadDBObject(dbObj);
}
*/
SimulationAreaTemplatesListElement* SimulationAreaTemplatesListPanel::createElement(DataBaseObject* refObj, SimulationAreaTemplatesListElement* refObjParent){
    return SimulationAreaTemplatesListPanel::createElement(refObj, refObjParent, refObj->getObjectType());
}

SimulationAreaTemplatesListElement* SimulationAreaTemplatesListPanel::createElement(DataBaseObject* refObj, SimulationAreaTemplatesListElement* refObjParent, uint type){
    switch(type){
    case DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE):
    {
        return (new SimulationAreaTemplatesListElement(&list, refObj, refObjParent))->allowUpdate();
    }
        break;
    case DB_GET_REAL_TYPE(DataBaseObject, DATABASE_OBJECT_DATABASE):
    {
        return (new SimulationAreaTemplatesListElementList(&list, refObj, refObjParent))->allowUpdate();
    }
        break;
    default:
        break;
    }
    return nullptr;
}

bool SimulationAreaTemplatesListPanel::eventFilter(QObject *obj, QEvent *ev){
    // Events Catched by SimulationAreaTemplatesListPanel
    // - Mouse Pressed (Right Button on SimulationAreaTemplatesListPanel widget, call function execContextMenu)
    switch(ev->type()){
    case QEvent::MouseButtonPress:
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
        break;
    default:
        break;
    }
    return QScrollArea::eventFilter(obj, ev);
}

void SimulationAreaTemplatesListPanel::paintEvent(QPaintEvent *ev){
    QPainter p(viewport());
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}
// ----------------------------------------------------------------------------------------------------------------------------------------------
