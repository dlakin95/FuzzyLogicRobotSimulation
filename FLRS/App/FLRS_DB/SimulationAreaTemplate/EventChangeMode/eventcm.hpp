#ifndef LEDMATRIXPICTURECHANGEMODE_HPP
#define LEDMATRIXPICTURECHANGEMODE_HPP

#include<QEvent>
#include"App/FLRS_DB/SimulationAreaTemplate/Mode/mode.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class SimulationAreaTemplateEventChangeMode : public QEvent{
    public:
    SimulationAreaTemplateEventChangeMode(SimulationAreaTemplateModeType newModeType, uint phase = 0) : QEvent(SimulationAreaTemplateChangeMode), newModeType(newModeType), phase(phase){}
    virtual ~SimulationAreaTemplateEventChangeMode()override{}

private:

    SimulationAreaTemplateModeType newModeType = SIMULATION_AREA_TEMPLATE_MODE_DEFAULT;
    uint phase = 0;

public:
    static const QEvent::Type SimulationAreaTemplateChangeMode = static_cast<QEvent::Type>(1000);

    SimulationAreaTemplateModeType  get_newModeType() const {return newModeType;}
    uint get_phase(){return phase;}

};

#endif // LEDMATRIXPICTURECHANGEMODE_HPP
