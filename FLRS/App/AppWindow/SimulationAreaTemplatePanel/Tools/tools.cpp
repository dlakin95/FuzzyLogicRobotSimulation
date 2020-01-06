#include"tools.hpp"
#include<QMouseEvent>
#include<QMenu>
#include"App/AppWindow/SimulationAreaTemplatePanel/templatepanel.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/EventChangeMode/eventcm.hpp"
#include<QApplication>

SimulationAreaTemplateTools::SimulationAreaTemplateTools(SimulationAreaTemplatePanel* parent) : QToolBar (parent), parent(parent){
    init();
}

SimulationAreaTemplateTools::~SimulationAreaTemplateTools(){

}

void SimulationAreaTemplateTools::init(){
    setOrientation(Qt::Vertical);
    for(uint i = 0; i < NUMB_OF_PAINT_TOOLS_OPTIONS; i++){
        QAction* tempAction = paintToolsOptions + i;
        tempAction->setIcon(PAINT_TOOLS_OPTION_ICON_ACCESS(PAINT_TOOLS_OPTION_RECT));
        tempAction->setParent(this);
        addAction(tempAction);
    }
    connect(paintToolsOptions, SIGNAL(triggered()), this, SLOT(addRobot()));
    connect(paintToolsOptions + 1, SIGNAL(triggered()), this, SLOT(addRect()));
}

void SimulationAreaTemplateTools::actionRun(SimulationAreaTemplateToolsOptions option){

}

bool SimulationAreaTemplateTools::eventFilter(QObject *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::MouseButtonRelease:
    {
        if(obj == this){
            QAction* activeted = actionAt(static_cast<QMouseEvent*>(ev)->pos());
            if(activeted){
                uint i = 0;
                for( ; i < NUMB_OF_PAINT_TOOLS_OPTIONS; i++)
                    if(paintToolsOptions + i == activeted)
                        break;
                if(i == NUMB_OF_PAINT_TOOLS_OPTIONS)
                    break;
                actionRun(static_cast<SimulationAreaTemplateToolsOptions>(i));
            }
        }
    }
        break;
    default:
        break;
    }
    return QToolBar::eventFilter(obj, ev);
}

void SimulationAreaTemplateTools::addSimulationAreaTemplate(){
    SimulationAreaTemplateEventChangeMode changeModeEv(SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_SIMULATION_AREA);
    QApplication::sendEvent(&parent->get_paintArea(), &changeModeEv);
}

void SimulationAreaTemplateTools::addRect(){
    SimulationAreaTemplateEventChangeMode changeModeEv(SIMULATION_AREA_TEMPLATE_MODE_DRAW_RECT_OBSTACLE);
    QApplication::sendEvent(&parent->get_paintArea(), &changeModeEv);
}

void SimulationAreaTemplateTools::addElipse(){
    SimulationAreaTemplateEventChangeMode changeModeEv(SIMULATION_AREA_TEMPLATE_MODE_DRAW_ELIPSE_OBSTACLE);
    QApplication::sendEvent(&parent->get_paintArea(), &changeModeEv);
}

void SimulationAreaTemplateTools::addRobot(){
    SimulationAreaTemplateEventChangeMode changeModeEv(SIMULATION_AREA_TEMPLATE_MODE_ADD_ROBOT);
    QApplication::sendEvent(&parent->get_paintArea(), &changeModeEv);
}
