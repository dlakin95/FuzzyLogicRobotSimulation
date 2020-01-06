#ifndef LEDMATRIXPICTUREELEMENT_HPP
#define LEDMATRIXPICTUREELEMENT_HPP

#include"DataBase/databaseobject.hpp"
#include"elementparams.hpp"
#include"elementtypes.hpp"
#include"elementshape.hpp"

class QGraphicsItem;
class SimulationAreaTemplate;
class SimulationAreaTemplateElement : public DataBaseObject{
public:
    SimulationAreaTemplateElement();
    SimulationAreaTemplateElement(uint numbOfParams);
    SimulationAreaTemplateElement(DataBaseObject* obj);
    SimulationAreaTemplateElement(DataBaseObject* obj, uint numbOfParams);
    virtual ~SimulationAreaTemplateElement() override;

protected:
    //QGraphicsItem* object = nullptr;

    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_TEMPLATE_ELEMENT_X),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_TEMPLATE_ELEMENT_Y),
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION),
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(SIMULATION_AREA_TEMPLATE_ELEMENT_SHAPE),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(SIMULATION_AREA_TEMPLATE_ELEMENT_X),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(SIMULATION_AREA_TEMPLATE_ELEMENT_Y),
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION),
    };

public:
    virtual QGraphicsItem* curItem(){return nullptr;}

    DB_OBJECT_STANDARD_METHODS(SimulationAreaTemplateElement, DataBaseObject, SimulationAreaTemplateElementParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS, SimulationAreaTemplateElementTypes, NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_TYPES, NUMB_OF_DATABASE_OBJECT_TYPES)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override;

    virtual SimulationAreaTemplateElementTypes getElementType()const{return SIMULATION_AREA_TEMPLATE_ELEMENT_NO_TYPE;}

    virtual bool sceneEventFilter(QGraphicsItem *obj, QEvent *ev);

    virtual SimulationAreaTemplate* scene();

    virtual Shape getShape(){return NUMB_OF_SHAPES;}

};


#endif // LEDMATRIXPICTUREELEMENT_HPP
