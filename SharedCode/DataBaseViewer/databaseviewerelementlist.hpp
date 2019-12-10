#ifndef DATABASEVIEWERELEMENTLIST_HPP
#define DATABASEVIEWERELEMENTLIST_HPP
// _INCLUDES_ DataBaseViewerElementList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"databaseviewerelement.hpp"
#include"../SharedCode/ExpandButton/expandbutton.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseViewerElementList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewerList;
class DataBaseObject;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseViewerElementList -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewerElementList : public DataBaseViewerElement{
public:
    // _CONSTRUCTORS_ DataBaseViewerElementList.hpp
    DataBaseViewerElementList(DataBaseViewerList* mainListParent,  DataBaseObject* refObj,DataBaseViewerElement* refListParent = nullptr);
    // _DESTRUCTORS_ DataBaseViewerElementList.hpp
    virtual ~DataBaseViewerElementList();

protected:
    // _PRIVATE_MEMBERS_ DataBaseViewerElementList.hpp
    DataBaseViewerElement** elements = nullptr;
    uint numbOfElements = 0;

    ExpandButton expandButton;
public:
    // _PUBLIC_MEMBERS_ DataBaseViewerElementList.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseViewerElementList.hpp
    void createObjects()override;
    void createLayout()override;
    void connectEvents()override{expandButton.installEventFilter(this);}
    void clearMemory()override;
    void generateText()override;
    void reallocateElements(DataBaseViewerElement*&)override;
    void clearElements()override{}
    void load()override;
    virtual inline void addNewDbObj(DataBaseObject* dbObj);
    // On Action Functions
    bool onPressedEvent()override{}
    bool onReleasedEvent()override{}

    void createContextMenu(QAction* actions) override;
    void execContextMenu(QPoint& eventPos) override;

public:
    // _PUBLIC_METHODS_ DataBaseViewerElementList.hpp
    GET_DECLARATION(DataBaseViewerElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(uint, level)


    bool addElement(DataBaseViewerElement*);    // Dont reallocate
    bool removeElement(DataBaseViewerElement*); // Dont reallocate
    bool addListElement(DataBaseViewerElement* newObj);
    bool removeListElement(DataBaseViewerElement*);

    virtual void reload()override;
    void resizeEvent(QResizeEvent* ev)override;
    bool eventFilter(QObject* obj, QEvent* ev)override;
    void paintEvent(QPaintEvent* ev)override;
};


// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEVIEWERELEMENTLIST
