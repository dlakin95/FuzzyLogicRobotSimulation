#ifndef OBSTACLERECT_HPP
#define OBSTACLERECT_HPP

#include<QGraphicsRectItem>
#include"../obstacle.hpp"
#include"obstaclerectparam.hpp"

class ObstacleRect : public Obstacle , public QGraphicsRectItem{
public:
    ObstacleRect();
    ObstacleRect(uint numbOfParams);
    ObstacleRect(DataBaseObject* obj);
    ObstacleRect(DataBaseObject* obj, uint numbOfParams);
    virtual ~ObstacleRect() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_RECT_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_RECT_HEIGHT)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_RECT_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_RECT_HEIGHT)
    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(ObstacleRect, Obstacle, ObstacleRectParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_OBSTACLE_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual QGraphicsItem* curItem()override{return this;}

    virtual ObstacleShape getShape() override{return OBSTACLE_SHAPE_RECT;}
};

#endif // OBSTACLERECT_HPP
