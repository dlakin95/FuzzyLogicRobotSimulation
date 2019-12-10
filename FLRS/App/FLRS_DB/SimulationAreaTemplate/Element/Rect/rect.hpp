#ifndef LEDMATRIXPICTUREELEMENTRECT_HPP
#define LEDMATRIXPICTUREELEMENTRECT_HPP

#include<QGraphicsRectItem>
#include"../element.hpp"
#include"rectparams.hpp"

class SimulationAreaTemplateElementRect : public virtual SimulationAreaTemplateElement{
public:
    SimulationAreaTemplateElementRect();
    SimulationAreaTemplateElementRect(uint numbOfParams);
    SimulationAreaTemplateElementRect(DataBaseObject* obj);
    SimulationAreaTemplateElementRect(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationAreaTemplateElementRect() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {

    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {

    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaTemplateElementRect, SimulationAreaTemplateElement, SimulationAreaTemplateElementRectParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual  SimulationAreaTemplateElementTypes getElementType() const override {return SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_RECT;}

};


#endif // LEDMATRIXPICTUREELEMENTRECT_HPP
