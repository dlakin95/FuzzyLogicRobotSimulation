#ifndef PICTURESLIST_HPP
#define PICTURESLIST_HPP

// _INCLUDES_ SimulationAreaTemplatesList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ SimulationAreaTemplatesList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class SimulationAreaTemplatesListPanel;
class SimulationAreaTemplatesListElement;
class FuzzyLogicRobotSimulationDataBase;
class DataBaseObject;
class QLineEdit;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ SimulationAreaTemplatesList -----------------------------------------------------------------------------------------------------------------------------------------------
class SimulationAreaTemplatesList : public QWidget{
public:
    // _CONSTRUCTORS_ SimulationAreaTemplatesList.hpp
    SimulationAreaTemplatesList(SimulationAreaTemplatesListPanel* parent);

    // _DESTRUCTORS_ SimulationAreaTemplatesList.hpp
    ~SimulationAreaTemplatesList();

private:
    // _PRIVATE_MEMBERS_ SimulationAreaTemplatesList.hpp
    SimulationAreaTemplatesListPanel* parent = nullptr;
    SimulationAreaTemplatesListElement** elements = nullptr;
    uint numbOfElements = 0;
    SimulationAreaTemplatesListElement* currentElement = nullptr;

    SimulationAreaTemplatesListElement* elementAtEditMode = nullptr;
    bool newNameAccepted = false;

    bool newObjectFlag = false;

    bool reallocationFlag = false;
public:
    // _PUBLIC_MEMBERS_ SimulationAreaTemplatesList.hpp

private:
    // _PRIVATE_METHODS_ SimulationAreaTemplatesList.hpp
    void initalize();
    void createObjects();
    void createLayout();
    void connectEvents();
    void clearMemory();
public:
    // _PUBLIC_METHODS_ SimulationAreaTemplatesList.hpp
    GET_DECLARATION(SimulationAreaTemplatesListPanel*, parent)
    GET_DECLARATION(SimulationAreaTemplatesListElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(SimulationAreaTemplatesListElement*, currentElement)
    GET_DECLARATION(SimulationAreaTemplatesListElement*, elementAtEditMode)
    GET_SET_DECLARATION(bool, newNameAccepted)
    GET_SET_DECLARATION(bool, newObjectFlag)

    DataBaseObject* get_currentElementRefObj();
    void reload();
    bool addElement(SimulationAreaTemplatesListElement* newElem);
    bool removeElement(SimulationAreaTemplatesListElement* remElem);
    void clearElements();
    bool load(FuzzyLogicRobotSimulationDataBase*);
    bool loadDBObject(FuzzyLogicRobotSimulationDataBase*);
    void reallocateElements(SimulationAreaTemplatesListElement*&);   // Caller (Reallocate from caller, if caller == nullptr, from first element)

    void addNewDbObject(FuzzyLogicRobotSimulationDataBase* dbObj){
        newObjectFlag = true;
        loadDBObject(dbObj);
    }
    void selectElement(SimulationAreaTemplatesListElement* ele){currentElement = ele; repaint();}
    void putElementAtEditMode(SimulationAreaTemplatesListElement* ele);
    void editModeAccept();
    void editModeCancel();
    void paintEvent(QPaintEvent* ev);
    void resizeEvent(QResizeEvent* ev);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // PICTURESLIST_HPP
