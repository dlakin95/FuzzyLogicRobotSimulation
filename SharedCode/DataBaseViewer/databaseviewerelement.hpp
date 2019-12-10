#ifndef DATABASEVIEWERELEMENT_HPP
#define DATABASEVIEWERELEMENT_HPP
// _INCLUDES_ DataBaseViewerElement.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QCheckBox>
#include"../SharedCode/GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseViewerElement.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewerList;
class DataBaseObject;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseViewerElement -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewerElement : public QWidget{
public:
    // _CONSTRUCTORS_ DataBaseViewerElement.hpp
    DataBaseViewerElement(DataBaseViewerList* mainListParent, DataBaseObject*& refObj, DataBaseViewerElement* refListParent = nullptr);

    // _DESTRUCTORS_ DataBaseViewerElement.hpp
    virtual ~DataBaseViewerElement();

protected:
    // _PRIVATE_MEMBERS_ DataBaseViewerElement.hpp
    DataBaseViewerList* mainListParent = nullptr;
    DataBaseViewerElement* parent = nullptr;
    DataBaseObject* refObj = nullptr;
    uint curHeight = 0;
    bool reallocationFlag = false;

    QLineEdit titleLE;
    QCheckBox checkBox;

public:
    // _PUBLIC_MEMBERS_ DataBaseViewerElement.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseViewerElement.hpp
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
    // _PUBLIC_METHODS_ DataBaseViewerElement.hpp
    GET_DECLARATION(DataBaseViewerList*, mainListParent)
    GET_DECLARATION(DataBaseViewerElement*, parent)
    GET_SET_DECLARATION(DataBaseObject*, refObj)
    GET_DECLARATION(uint, curHeight)
    GET_DECLARATION(QLineEdit&, titleLE)
    GET_SET_DECLARATION(bool, reallocationFlag)

    virtual void reload(){}
    bool editModeCheckName(QKeyEvent *ev);
    virtual void reallocateElements(DataBaseViewerElement*&);
    void resizeEvent(QResizeEvent*);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);

     DataBaseViewerElement* allowUpdate(){setUpdatesEnabled(true); return this;}
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEVIEWERELEMENT
