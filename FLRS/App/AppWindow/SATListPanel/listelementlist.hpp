#ifndef PICTURESLISTELEMENTLIST_HPP
#define PICTURESLISTELEMENTLIST_HPP

// _INCLUDES_ SimulationAreaTemplatesListElementList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"listelement.hpp"
#include"../SharedCode/ExpandButton/expandbutton.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ SimulationAreaTemplatesListElementList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class SimulationAreaTemplatesList;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ SimulationAreaTemplatesListElementList -----------------------------------------------------------------------------------------------------------------------------------------------
class SimulationAreaTemplatesListElementList : public SimulationAreaTemplatesListElement{
public:
    // _CONSTRUCTORS_ SimulationAreaTemplatesListElementList.hpp
    SimulationAreaTemplatesListElementList(SimulationAreaTemplatesList* mainListParent,  DataBaseObject* refObj,SimulationAreaTemplatesListElement* refListParent = nullptr);
    // _DESTRUCTORS_ SimulationAreaTemplatesListElementList.hpp
    virtual ~SimulationAreaTemplatesListElementList() override;

protected:
    // _PRIVATE_MEMBERS_ SimulationAreaTemplatesListElementList.hpp
    SimulationAreaTemplatesListElement** elements = nullptr;
    uint numbOfElements = 0;

    ExpandButton expandButton;
public:
    // _PUBLIC_MEMBERS_ SimulationAreaTemplatesListElementList.hpp

protected:
    // _PRIVATE_METHODS_ SimulationAreaTemplatesListElementList.hpp
    void createObjects()override;
    void createLayout()override;
    void connectEvents()override{expandButton.installEventFilter(this);}
    void clearMemory()override;
    void generateText()override;
    void reallocateElements(SimulationAreaTemplatesListElement*&)override;
    void clearElements()override{}
    void load()override;
    virtual inline void addNewDbObj(DataBaseObject* dbObj) override;
    // On Action Functions
    bool onPressedEvent()override{}
    bool onReleasedEvent()override{}

    void createContextMenu(QAction* actions) override;
    void execContextMenu(QPoint& eventPos) override;

public:
    // _PUBLIC_METHODS_ SimulationAreaTemplatesListElementList.hpp
    GET_DECLARATION(SimulationAreaTemplatesListElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(uint, level)


    bool addElement(SimulationAreaTemplatesListElement*);    // Dont reallocate
    bool removeElement(SimulationAreaTemplatesListElement*); // Dont reallocate
    bool addListElement(SimulationAreaTemplatesListElement* newObj);
    bool removeListElement(SimulationAreaTemplatesListElement*);

    virtual void reload()override;
    void resizeEvent(QResizeEvent* ev)override;
    bool eventFilter(QObject* obj, QEvent* ev)override;
    void paintEvent(QPaintEvent* ev)override;
};


// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // PICTURESLISTELEMENTLIST_HPP
