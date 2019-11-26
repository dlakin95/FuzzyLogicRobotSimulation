#ifndef LEDMATRIXPICTURE_HPP
#define LEDMATRIXPICTURE_HPP

#include"DataBase/databaseobject.hpp"
#include<QGraphicsScene>
#include"satemplateparams.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"Mode/mode.hpp"

class SimulationAreaTemplateElement;
class SimulationAreaTemplate : public DataBaseObject, public QGraphicsScene{
public:
    SimulationAreaTemplate();
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
    // LED Matrix Picture Basic Config
    //SimulationAreaTemplateBasicConfig *basicConfig = nullptr;

    // LED Matrix Picture Elements
    SimulationAreaTemplateElement **elements = nullptr;
    uint numbOfElements = 0;

    // For Scene Mode
    SimulationAreaTemplateMode* curMode = nullptr;

    // Changed Flag
    bool changedFlag = false;

public:
    GET_DECLARATION(bool, changedFlag)

    DB_OBJECT_STANDARD_METHODS_NO_TYPES(SimulationAreaTemplate, DataBaseObject, SimulationAreaTemplateParameters, NUMB_OF_SIMULATION_AREA_TEMPLATE_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject(uint newType)override{return nullptr;}

    void activateMode(SimulationAreaTemplateModeType type, uint phase);
    void deactivateCurMode();

    bool eventFilter(QObject *obj, QEvent *ev) override;
};


#endif // LEDMATRIXPICTURE_HPP