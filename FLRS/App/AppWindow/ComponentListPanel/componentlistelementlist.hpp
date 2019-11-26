#ifndef COMPONENTLISTELEMENTLIST_HPP
#define COMPONENTLISTELEMENTLIST_HPP

// _INCLUDES_ ComponentListElementList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"componentlistelement.hpp"
#include"ExpandButton/expandbutton.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ ComponentListElementList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class ComponentList;
class DataBaseObject;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ ComponentListElementList -----------------------------------------------------------------------------------------------------------------------------------------------
class ComponentListElementList : public ComponentListElement{
public:
    // _CONSTRUCTORS_ ComponentListElementList.hpp
    ComponentListElementList(ComponentList* mainListParent,  DataBaseObject* refObj,ComponentListElement* refListParent = nullptr);
    // _DESTRUCTORS_ ComponentListElementList.hpp
    virtual ~ComponentListElementList() override;

protected:
    // _PRIVATE_MEMBERS_ ComponentListElementList.hpp
    ComponentListElement** elements = nullptr;
    uint numbOfElements = 0;

    ExpandButton expandButton;
public:
    // _PUBLIC_MEMBERS_ ComponentListElementList.hpp

protected:
    // _PRIVATE_METHODS_ ComponentListElementList.hpp
    void createObjects()override;
    void createLayout()override;
    void connectEvents()override{expandButton.installEventFilter(this);}
    void clearMemory()override;
    void generateText()override;
    void reallocateElements(ComponentListElement*&)override;
    void clearElements()override{}
    void load()override;
    //virtual inline void addNewDbObj(DataBaseObject* dbObj);
    // On Action Functions
    bool onPressedEvent()override{}
    bool onReleasedEvent()override{}

    void createContextMenu(QAction* actions) override;
    void execContextMenu(QPoint& eventPos) override;

public:
    // _PUBLIC_METHODS_ ComponentListElementList.hpp
    GET_DECLARATION(ComponentListElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(uint, level)


    bool addElement(ComponentListElement*);    // Dont reallocate
    bool removeElement(ComponentListElement*); // Dont reallocate
    bool addListElement(ComponentListElement* newObj);
    bool removeListElement(ComponentListElement*);

    virtual void reload()override;
    void resizeEvent(QResizeEvent* ev)override;
    bool eventFilter(QObject* obj, QEvent* ev)override;
    void paintEvent(QPaintEvent* ev)override;
};


// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // COMPONENTLISTELEMENTLIST_HPP
