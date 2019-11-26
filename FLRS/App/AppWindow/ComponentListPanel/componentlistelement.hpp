#ifndef COMPONENTLISTELEMENT_HPP
#define COMPONENTLISTELEMENT_HPP

// _INCLUDES_ ComponentListElement.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QCheckBox>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ ComponentListElement.hpp --------------------------------------------------------------------------------------------------------------------------------------
class ComponentList;
class DataBaseObject;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ ComponentListElement -----------------------------------------------------------------------------------------------------------------------------------------------
class ComponentListElement : public QWidget{
public:
    // _CONSTRUCTORS_ ComponentListElement.hpp
    ComponentListElement(ComponentList* mainListParent, DataBaseObject*& refObj, ComponentListElement* refListParent = nullptr);

    // _DESTRUCTORS_ ComponentListElement.hpp
    virtual ~ComponentListElement();

protected:
    // _PRIVATE_MEMBERS_ ComponentListElement.hpp
    ComponentList* mainListParent = nullptr;
    ComponentListElement* parent = nullptr;
    DataBaseObject* refObj = nullptr;
    uint curHeight = 0;
    bool reallocationFlag = false;

    QLineEdit titleLE;
    QCheckBox checkBox;

public:
    // _PUBLIC_MEMBERS_ ComponentListElement.hpp

protected:
    // _PRIVATE_METHODS_ ComponentListElement.hpp
    virtual void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();
    virtual void generateText();
    virtual void clearElements(){}
    virtual void load(){}
    //virtual inline void addNewDbObj(DataBaseObject* dbObj){

    //}

    // On Action Functions
    virtual bool onPressedEvent(){}
    virtual bool onReleasedEvent(){}

    virtual void createContextMenu(QAction* actions);
    virtual void execContextMenu(QPoint& eventPos);

public:
    // _PUBLIC_METHODS_ ComponentListElement.hpp
    GET_DECLARATION(ComponentList*, mainListParent)
    GET_DECLARATION(ComponentListElement*, parent)
    GET_SET_DECLARATION(DataBaseObject*, refObj)
    GET_DECLARATION(uint, curHeight)
    GET_DECLARATION(QLineEdit&, titleLE)
    GET_SET_DECLARATION(bool, reallocationFlag)

    virtual void reload(){}
    bool editModeCheckName(QKeyEvent *ev);
    virtual void reallocateElements(ComponentListElement*&);
    void resizeEvent(QResizeEvent*);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);

     ComponentListElement* allowUpdate(){setUpdatesEnabled(true); return this;}
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // COMPONENTLISTELEMENT_HPP
