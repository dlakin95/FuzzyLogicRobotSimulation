#ifndef OBSTACLEELLIPSE_HPP
#define OBSTACLEELLIPSE_HPP

#include<QGraphicsEllipseItem>
#include"../obstacle.hpp"
#include"obstacleellipseparam.hpp"

class ObstacleEllipse : public Obstacle , public QGraphicsEllipseItem{
public:
    ObstacleEllipse();
    ObstacleEllipse(uint numbOfParams);
    ObstacleEllipse(DataBaseObject* obj);
    ObstacleEllipse(DataBaseObject* obj, uint numbOfParams);
    virtual ~ObstacleEllipse() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_ELLIPSE_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_ELLIPSE_HEIGHT)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_ELLIPSE_WIDTH),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(OBSTACLE_ELLIPSE_HEIGHT)
    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(ObstacleEllipse, Obstacle, ObstacleEllipseParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_OBSTACLE_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    virtual QGraphicsItem* curItem()override{return this;}

    virtual ObstacleShape getShape() override{return OBSTACLE_SHAPE_ELLIPSE;}
};


#endif // OBSTACLEELLIPSE_HPP
