// _INCLUDES_ DataBaseViewer.cpp -------------------------------------------------------------------------------------------------------------------
#include "databaseviewer.hpp"
#include"../SharedCode/AppWindow/appwindow.hpp"
#include"databaseviewerelement.hpp"
#include"../SharedCode/DataBase/databaseobject.hpp"
#include"../SharedCode/GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../SharedCode/GeneralPurposeMacros/databasemenegmentmacros.hpp"
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
#include"databaseviewerelementlist.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include"../SharedCode/AppWindow/appwindow.hpp"
#include"../SharedCode/App/app.hpp"
#include"databasemenager.hpp"
#include"../SharedCode/DataBase/databasecategory.hpp"
#include"../SharedCode/DataBaseViewer/dialogdatabasevieweraddcategory.hpp"
#include"../SharedCode/DataBase/database.hpp"
#include<QPainter>
#include<QPen>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseViewer -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseViewer.cpp
DataBaseViewer::DataBaseViewer(AppWindow* parent) : QScrollArea (parent), parent(parent), list(this)
{
  initalize();
}

// _DESTRUCTORS_ DataBaseViewer.cpp
DataBaseViewer::~DataBaseViewer(){
    clearMemory();
}

// _PRIVATE_METHODS_ DataBaseViewer.cpp
void DataBaseViewer::initalize(){
    createObjects();
    createLayout();
    connectEvents();
}

void DataBaseViewer::createObjects(){

}

void DataBaseViewer::createLayout(){
    setStyleSheet("background-color: transparent");
    verticalScrollBar()->setStyleSheet("QScrollBar::vertical{background: transparent; width: 5px;} QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical, QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical, QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{border: none; background: none; color: none;} QScrollBar::handle:vertical{background-color: white; border: 1px solid black;}");
    setFrameShape(QFrame::NoFrame);
    setWidget(&list);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    show();
}

void DataBaseViewer::connectEvents(){
    installEventFilter(this);
}

void DataBaseViewer::clearMemory(){

}

void DataBaseViewer::createContextMenu(QAction *actions){
    // Action 1 (0) Add Test Group
    (actions + 0)->setText("Add Category");
    (actions + 0)->setParent(this);
}

void DataBaseViewer::execContextMenu(QPoint& eventPos){
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

// _PUBLIC_METHODS_ DataBaseViewer.cpp
GET_DEFINITION(DataBaseViewer, AppWindow*, parent)
GET_DEFINITION(DataBaseViewer, DataBaseViewerList&, list)

void DataBaseViewer::resizeEvent(QResizeEvent *ev){
    list.resize(LO_DATABASE_VIEWER_LIST_SIZE(LAYOUT_CURRENT_HEIGHT));
}

void DataBaseViewer::clear(){
    list.clearElements();
}

bool DataBaseViewer::load(DataBase *db){
    list.load(db);
}

bool DataBaseViewer::clearAndLoad(DataBase *db){
    list.clearElements();
    list.load(db);
}

bool DataBaseViewer::clearAndLoadDbObj(DataBaseObject *dbObj){
    list.clearElements();
    list.loadDBObject(dbObj);
}

bool DataBaseViewer::loadDbObj(DataBaseObject *dbObj){
    list.loadDBObject(dbObj);
}

DataBaseViewerElement* DataBaseViewer::createElement(DataBaseObject* refObj, DataBaseViewerElement* refObjParent){
    return DataBaseViewer::createElement(refObj, refObjParent, refObj->getObjectType());
}

DataBaseViewerElement* DataBaseViewer::createElement(DataBaseObject* refObj, DataBaseViewerElement* refObjParent, uint type){
    switch(type){
    case DATABASE_OBJECT_CATEGORY:
        return (new DataBaseViewerElementList(&list, refObj, refObjParent))->allowUpdate();
    default:
        break;
    }
    return nullptr;
}

bool DataBaseViewer::eventFilter(QObject *obj, QEvent *ev){
    // Events Catched by DataBaseViewer
    // - Mouse Pressed (Right Button on DataBaseViewer widget, call function execContextMenu)
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

void DataBaseViewer::paintEvent(QPaintEvent *ev){
    QPainter p(viewport());
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}
// ----------------------------------------------------------------------------------------------------------------------------------------------
