#ifndef SIMAREA_HPP
#define SIMAREA_HPP

#include"../element.hpp"
#include"simareaparam.hpp"


class SimulationArea : public SimulationAreaTemplateElement{
public:
    SimulationArea();
    SimulationArea(uint numbOfParams);
    SimulationArea(DataBaseObject* obj);
    SimulationArea(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationArea() override;

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
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationArea, SimulationAreaTemplateElement, SimulationAreaParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override;

    virtual  SimulationAreaTemplateElementTypes getElementType() const override {return SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_SIMULATION_AREA;}


};


#endif // SIMAREA_HPP
