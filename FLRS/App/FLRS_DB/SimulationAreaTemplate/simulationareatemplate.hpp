#ifndef LEDMATRIXPICTURE_HPP
#define LEDMATRIXPICTURE_HPP

#include"DataBase/databaseobject.hpp"
#include<QGraphicsScene>
#include"satemplateparams.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"Mode/mode.hpp"
#include<QGraphicsItem>

class SimulationAreaTemplateElement;
class SimulationAreaTemplate : public DataBaseObject, public QGraphicsScene{
public:
    SimulationAreaTemplate();
    SimulationAreaTemplate(uint);
    SimulationAreaTemplate(DataBaseObject* obj);
    virtual ~SimulationAreaTemplate() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {
        DB_OBJECT_MACRO_ACCESS_OPTIONALITY(SIMULATION_AREA_TEMPLATE_ELEMENTS)
    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {
        DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(SIMULATION_AREA_TEMPLATE_ELEMENTS)

    };

    // Scale Factor
    static constexpr int scaleFactor = 0x10;

    // Items Bounding Rect (Dynamic by Scene Change)
    QRectF tempItemsBoundingRect;

    QRectF lastViewRect;

    // SimulationAreaTemplate Elements
    SimulationAreaTemplateElement **elements = nullptr;
    uint numbOfElements = 0;

    // For Scene Mode
    SimulationAreaTemplateMode* curMode = nullptr;

    // Changed Flag
    bool changedFlag = false;

    QPointF lastMPos;

    // To change scene after add item
    bool acceptSceneChange = true;  // Clear only for single action, then set after action (Control function sceneChangeByAddItem when add item)

    inline void sceneChangeByAddItem(QGraphicsItem* item){if(item && acceptSceneChange) setSceneRect(sceneRect() | QRectF(item->scenePos(), item->boundingRect().size()));}


public:
    static inline constexpr double scale(double v){return v * scaleFactor;}

    GET_DECLARATION(bool, changedFlag)
    GET_DECLARATION(QRectF, tempItemsBoundingRect)

    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaTemplate, DataBaseObject, SimulationAreaTemplateParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    void activateMode(SimulationAreaTemplateModeType type, uint phase);
    void deactivateCurMode();

    bool eventFilter(QObject *obj, QEvent *ev) override;

    bool addElement(SimulationAreaTemplateElement* newElem){ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(SimulationAreaTemplateElement, elements, numbOfElements, newElem);}
    bool removeElement(SimulationAreaTemplateElement* remElem){ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(SimulationAreaTemplateElement, elements, numbOfElements, remElem);}
    void clearElements(){ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);}


    void setLastViewRect(QRectF rect){lastViewRect = rect;}
    QRectF getLastViewRect(){return lastViewRect.isEmpty()? (lastViewRect = tempItemsBoundingRect) : lastViewRect;}


    inline void sceneChangeByMoveItem(QGraphicsItem* item){sceneChangeByAddItem(item);}

};


#endif // LEDMATRIXPICTURE_HPP
