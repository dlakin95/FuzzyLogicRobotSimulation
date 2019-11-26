#ifndef PICTURESLISTELEMENT_HPP
#define PICTURESLISTELEMENT_HPP

// _INCLUDES_ SimulationAreaTemplatesListElement.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QCheckBox>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"DataBase/databaseobject.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ SimulationAreaTemplatesListElement.hpp --------------------------------------------------------------------------------------------------------------------------------------
class SimulationAreaTemplatesList;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ SimulationAreaTemplatesListElement -----------------------------------------------------------------------------------------------------------------------------------------------
class SimulationAreaTemplatesListElement : public QWidget{
public:
    // _CONSTRUCTORS_ SimulationAreaTemplatesListElement.hpp
    SimulationAreaTemplatesListElement(SimulationAreaTemplatesList* mainListParent, DataBaseObject*& refObj, SimulationAreaTemplatesListElement* refListParent = nullptr);

    // _DESTRUCTORS_ SimulationAreaTemplatesListElement.hpp
    virtual ~SimulationAreaTemplatesListElement();

protected:
    // _PRIVATE_MEMBERS_ SimulationAreaTemplatesListElement.hpp
    SimulationAreaTemplatesList* mainListParent = nullptr;
    SimulationAreaTemplatesListElement* parent = nullptr;
    DataBaseObject* refObj = nullptr;
    uint curHeight = 0;
    bool reallocationFlag = false;

    QLineEdit titleLE;
    QCheckBox checkBox;

public:
    // _PUBLIC_MEMBERS_ SimulationAreaTemplatesListElement.hpp

protected:
    // _PRIVATE_METHODS_ SimulationAreaTemplatesListElement.hpp
    virtual void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();
    virtual void generateText();
    virtual void clearElements(){}
    virtual void load(){}
    virtual inline void addNewDbObj(DataBaseObject* dbObj){

    }

    // On Action Functions
    virtual bool onPressedEvent(){}
    virtual bool onReleasedEvent(){}

    virtual void createContextMenu(QAction* actions);
    virtual void execContextMenu(QPoint& eventPos);

public:
    // _PUBLIC_METHODS_ SimulationAreaTemplatesListElement.hpp
    GET_DECLARATION(SimulationAreaTemplatesList*, mainListParent)
    GET_DECLARATION(SimulationAreaTemplatesListElement*, parent)
    GET_SET_DECLARATION(DataBaseObject*, refObj)
    GET_DECLARATION(uint, curHeight)
    GET_DECLARATION(QLineEdit&, titleLE)
    GET_SET_DECLARATION(bool, reallocationFlag)

    virtual void reload(){}
    bool editModeCheckName(QKeyEvent *ev);
    virtual void reallocateElements(SimulationAreaTemplatesListElement*&);
    void resizeEvent(QResizeEvent*);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);

     SimulationAreaTemplatesListElement* allowUpdate(){setUpdatesEnabled(true); return this;}
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // PICTURESLISTELEMENT_HPP
