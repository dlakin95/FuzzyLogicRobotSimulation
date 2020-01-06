#ifndef ELIPSE_HPP
#define ELIPSE_HPP

#include<QGraphicsEllipseItem>
#include"../element.hpp"
#include"elipseparams.hpp"

class SimulationAreaTemplateElementElipse : public virtual SimulationAreaTemplateElement, public QGraphicsEllipseItem{
public:
    SimulationAreaTemplateElementElipse();
    SimulationAreaTemplateElementElipse(uint numbOfParams);
    SimulationAreaTemplateElementElipse(DataBaseObject* obj);
    SimulationAreaTemplateElementElipse(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationAreaTemplateElementElipse() override;

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
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaTemplateElementElipse, SimulationAreaTemplateElement, SimulationAreaTemplateElementElipseParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual  SimulationAreaTemplateElementTypes getElementType() const override {return SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_ELIPSE;}

};

#endif // ELIPSE_HPP
