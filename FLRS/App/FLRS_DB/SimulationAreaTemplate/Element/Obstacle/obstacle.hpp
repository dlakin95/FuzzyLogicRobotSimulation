#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include"../element.hpp"
#include"obstacleparam.hpp"
class Obstacle : public SimulationAreaTemplateElement{
public:
    Obstacle();
    Obstacle(uint numbOfParams);
    Obstacle(DataBaseObject* obj);
    Obstacle(DataBaseObject* obj, uint numbOfParams);
    virtual ~Obstacle() override;

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
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(Obstacle, SimulationAreaTemplateElement, ObstacleParameters, NUMB_OF_OBSTACLE_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override;

    virtual SimulationAreaTemplateElementTypes getElementType() const override{return SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_OBSTACLE;}

    virtual bool sceneEventFilter(QGraphicsItem *obj, QEvent *ev) override;
};

#endif // OBSTACLE_HPP
