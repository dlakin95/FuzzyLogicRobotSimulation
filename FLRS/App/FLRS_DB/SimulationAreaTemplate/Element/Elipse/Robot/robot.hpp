#ifndef ROBOT_HPP
#define ROBOT_HPP

#include<QGraphicsEllipseItem>
#include"../elipse.hpp"
#include"robotparams.hpp"

class SimulationAreaTemplateElementRobot : public SimulationAreaTemplateElementElipse{
public:
    SimulationAreaTemplateElementRobot();
    SimulationAreaTemplateElementRobot(uint numbOfParams);
    SimulationAreaTemplateElementRobot(DataBaseObject* obj);
    SimulationAreaTemplateElementRobot(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationAreaTemplateElementRobot() override;

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
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaTemplateElementRobot, SimulationAreaTemplateElementElipse, SimulationAreaTemplateElementRobotParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ELIPSE_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual  SimulationAreaTemplateElementTypes getElementType() const override {return SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_ROBOT;}

};

#endif // ROBOT_HPP
