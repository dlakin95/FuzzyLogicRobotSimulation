#ifndef COMPONENTLIST_HPP
#define COMPONENTLIST_HPP

// _INCLUDES_ ComponentList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ ComponentList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class ComponentListPanel;
class ComponentListElement;
class QLineEdit;
class SimulationAreaTemplate;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ ComponentList -----------------------------------------------------------------------------------------------------------------------------------------------
class ComponentList : public QWidget{
public:
    // _CONSTRUCTORS_ ComponentList.hpp
    ComponentList(ComponentListPanel* parent);

    // _DESTRUCTORS_ ComponentList.hpp
    ~ComponentList();

private:
    // _PRIVATE_MEMBERS_ ComponentList.hpp
    ComponentListPanel* parent = nullptr;
    ComponentListElement** elements = nullptr;
    uint numbOfElements = 0;
    ComponentListElement* currentElement = nullptr;

    ComponentListElement* elementAtEditMode = nullptr;
    bool newNameAccepted = false;

    bool newObjectFlag = false;

    bool reallocationFlag = false;
public:
    // _PUBLIC_MEMBERS_ ComponentList.hpp

private:
    // _PRIVATE_METHODS_ ComponentList.hpp
    void initalize();
    void createObjects();
    void createLayout();
    void connectEvents();
    void clearMemory();
public:
    // _PUBLIC_METHODS_ ComponentList.hpp
    GET_DECLARATION(ComponentListPanel*, parent)
    GET_DECLARATION(ComponentListElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(ComponentListElement*, currentElement)
    GET_DECLARATION(ComponentListElement*, elementAtEditMode)
    GET_SET_DECLARATION(bool, newNameAccepted)
    GET_SET_DECLARATION(bool, newObjectFlag)

    void reload();
    bool addElement(ComponentListElement* newElem);
    bool removeElement(ComponentListElement* remElem);
    void clearElements();
    bool load(SimulationAreaTemplate*);
    bool loadDBObject(SimulationAreaTemplate*);
    void reallocateElements(ComponentListElement*&);   // Caller (Reallocate from caller, if caller == nullptr, from first element)

    //void addNewDbObject(DataBaseObject* dbObj){
       // newObjectFlag = true;

      //  loadDBObject(dbObj);
    //}
    void selectElement(ComponentListElement* ele){currentElement = ele; repaint();}
    void putElementAtEditMode(ComponentListElement* ele);
    void editModeAccept();
    void editModeCancel();
    void paintEvent(QPaintEvent* ev);
    void resizeEvent(QResizeEvent* ev);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // COMPONENTLIST_HPP
