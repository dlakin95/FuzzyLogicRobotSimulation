#ifndef LEDMATRIXPICTUREELEMENTLEDMATRIX_HPP
#define LEDMATRIXPICTUREELEMENTLEDMATRIX_HPP

#include"../rect.hpp"
#include"simulationareaparams.hpp"

class SimulationAreaTemplateElementSimulationArea : public SimulationAreaTemplateElementRect{
public:
    SimulationAreaTemplateElementSimulationArea();
    SimulationAreaTemplateElementSimulationArea(uint numbOfParams);
    SimulationAreaTemplateElementSimulationArea(DataBaseObject* obj);
    SimulationAreaTemplateElementSimulationArea(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationAreaTemplateElementSimulationArea() override;

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
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaTemplateElementSimulationArea, SimulationAreaTemplateElementRect, SimulationAreaTemplateElementSimulationAreaParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_SIMULATION_AREA_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_RECT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual  SimulationAreaTemplateElementTypes getElementType() const override {return SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_SIMULATION_AREA;}

};


#endif // LEDMATRIXPICTUREELEMENTLEDMATRIX_HPP
