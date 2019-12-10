#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include"../element.hpp"
#include"obstacleparam.hpp"
#include"obstacleshape.hpp"

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
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_SHAPE),
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(OBSTACLE_SHAPE),
    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(Obstacle, SimulationAreaTemplateElement, ObstacleParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override;

    virtual ObstacleShape getShape(){return NUMB_OF_OBSTACLE_SHAPES;}
};

#endif // OBSTACLE_HPP
