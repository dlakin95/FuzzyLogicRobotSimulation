#ifndef SARECT_HPP
#define SARECT_HPP

#include"../simarea.hpp"
#include"SARectParam.hpp"
#include<QGraphicsRectItem>

class SimulationAreaRect : public SimulationArea , public QGraphicsRectItem{
public:
    SimulationAreaRect();
    SimulationAreaRect(uint numbOfParams);
    SimulationAreaRect(DataBaseObject* obj);
    SimulationAreaRect(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationAreaRect() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_RECT_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_RECT_HEIGHT)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_RECT_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_RECT_HEIGHT)
    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaRect, SimulationArea, SimulationAreaRectParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_SIMULATION_AREA_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual QGraphicsItem* curItem()override{return this;}
};

#endif // SARECT_HPP
