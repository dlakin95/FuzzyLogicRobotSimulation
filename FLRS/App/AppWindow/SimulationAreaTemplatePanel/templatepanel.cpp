// _INCLUDES_ SimulationAreaTemplatePanel.cpp -------------------------------------------------------------------------------------------------------------------
#include "templatepanel.hpp"
#include"../appwindow.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"App/AppWindow/appwindowlayoutmacros.hpp"
#include<QScrollBar>
#include<QResizeEvent>
#include<QMouseEvent>
#include<QMenu>
#include<QPainter>
#include<QPen>
#include"App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.hpp"
#include"App/FLRS_DB/flrsdatabase.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ SimulationAreaTemplatePanel -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ SimulationAreaTemplatePanel.cpp
SimulationAreaTemplatePanel::SimulationAreaTemplatePanel(AppWindow* parent) : QWidget(parent), parent(parent), paintTools(this), paintArea(this)
{
   initalize();
}

// _DESTRUCTORS_ SimulationAreaTemplatePanel.cpp
SimulationAreaTemplatePanel::~SimulationAreaTemplatePanel(){
    clearMemory();
}

// _PRIVATE_METHODS_ SimulationAreaTemplatePanel.cpp
void SimulationAreaTemplatePanel::initalize(){
    paintTools.move(LO_PAINT_TOOLS_POS);
    paintArea.move(LO_PAINT_AREA_POS);
    createObjects();
    createLayout();
    connectEvents();
}

void SimulationAreaTemplatePanel::createObjects(){

}

void SimulationAreaTemplatePanel::createLayout(){

}

void SimulationAreaTemplatePanel::connectEvents(){
    //installEventFilter(this);
}

void SimulationAreaTemplatePanel::clearMemory(){

}

// _PUBLIC_METHODS_ SimulationAreaTemplatePanel.cpp
GET_DEFINITION(SimulationAreaTemplatePanel, SimulationAreaTemplateArea&, paintArea)


void SimulationAreaTemplatePanel::resizeEvent(QResizeEvent *ev){
    paintTools.resize(LO_PAINT_TOOLS_SIZE);
    paintArea.resize(LO_PAINT_AREA_SIZE);
}

void SimulationAreaTemplatePanel::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setPen(pen);
    p.drawRect(QRect(QPoint(0,0), size() - QSize(1,1)));
}

bool SimulationAreaTemplatePanel::eventFilter(QObject *obj, QEvent *ev){
    return QWidget::eventFilter(obj, ev);
}

void SimulationAreaTemplatePanel::reload(){
    SimulationAreaTemplate* picture = static_cast<SimulationAreaTemplate*>(parent->get_simulationAreaTemplatesListPanel().get_list().get_currentElementRefObj());
    if(picture && picture->getObjectType() == DB_GET_REAL_TYPE(FuzzyLogicRobotSimulationDataBase, FLRS_SIMULATION_AREA_TEMPLATE))
        paintArea.setScene(picture);
    else
        paintArea.setScene(nullptr);
    paintArea.show();
}




/*void SimulationAreaTemplatePanel::setPicture(SimulationAreaTemplate* newPicture){
    paintArea.setScene(newPicture);
}*/
// ----------------------------------------------------------------------------------------------------------------------------------------------
