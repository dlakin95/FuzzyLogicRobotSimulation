// _INCLUDES_ SimulationAreaTemplateArea.cpp -------------------------------------------------------------------------------------------------------------------
#include "area.hpp"
#include"App/AppWindow/SimulationAreaTemplatePanel/templatepanel.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/EventChangeMode/eventcm.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include<QPainter>
#include<QPen>
#include<QDebug>
#include<QApplication>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplateArea -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ SimulationAreaTemplateArea.cpp
SimulationAreaTemplateArea::SimulationAreaTemplateArea(SimulationAreaTemplatePanel* parent, QGraphicsScene* refScene) : QGraphicsView(refScene,parent), parent(parent)
{
   initalize();
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

// _DESTRUCTORS_ SimulationAreaTemplateArea.cpp
SimulationAreaTemplateArea::~SimulationAreaTemplateArea(){
    clearMemory();
}

// _PRIVATE_METHODS_ SimulationAreaTemplateArea.cpp
void SimulationAreaTemplateArea::initalize(){
    //setMouseTracking(true);
    //setRenderHint(QSimulationAreaTemplateer::HighQualityAntialiasing, true);
    createObjects();
    createLayout();
    connectEvents();
}

void SimulationAreaTemplateArea::createObjects(){

}

void SimulationAreaTemplateArea::createLayout(){

}

void SimulationAreaTemplateArea::connectEvents(){
    installEventFilter(this);
}

void SimulationAreaTemplateArea::clearMemory(){

}

// _PUBLIC_METHODS_ SimulationAreaTemplateArea.cpp
GET_DEFINITION(SimulationAreaTemplateArea, SimulationAreaTemplatePanel*, parent)


void SimulationAreaTemplateArea::resizeEvent(QResizeEvent *ev){

}

void SimulationAreaTemplateArea::paintEvent(QPaintEvent *ev){

    //p.drawRect(QRect(QPoint(0,0), QSize(10, 10)));
    //if(repaintPixelPointer){

    //}
    //p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
    QGraphicsView::paintEvent(ev);
}

bool SimulationAreaTemplateArea::eventFilter(QObject *obj, QEvent *ev){
    switch (ev->type()) {    
    /*case QEvent::MouseMove:
    {
        repaintPixelPointer = true;
        repaint();

    }
        break;*/
    case SimulationAreaTemplateEventChangeMode::SimulationAreaTemplateChangeMode:
    {
        if(scene()) return QApplication::sendEvent(scene(), ev);
    }
        break;
    default:
        break;
    }
    return QGraphicsView::eventFilter(obj, ev);
}

void SimulationAreaTemplateArea::wheelEvent(QWheelEvent *ev)
  {
    if(ev->delta() > 0)
      scale(1.25, 1.25);
    else
      scale(0.8, 0.8);
  }

void SimulationAreaTemplateArea::saveView(){
    if(scene())     scene()->setLastViewRect(mapToScene(viewport()->rect()).boundingRect());
}

SimulationAreaTemplate* SimulationAreaTemplateArea::scene(){
    return static_cast<SimulationAreaTemplate*>(QGraphicsView::scene());
}

void SimulationAreaTemplateArea::setScene(SimulationAreaTemplate *newScene){
    // Save View For Last Scene
    saveView();
    QGraphicsView::setScene(newScene);
    if(newScene){
        fitInView(newScene->getLastViewRect(), Qt::KeepAspectRatio);
    }

}
// ----------------------------------------------------------------------------------------------------------------------------------------------
