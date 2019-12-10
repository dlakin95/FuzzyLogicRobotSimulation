#ifndef DATABASEVIEWERLIST_HPP
#define DATABASEVIEWERLIST_HPP
// _INCLUDES_ DataBaseViewerList.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QWidget>
#include"../../SharedCode/GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseViewerList.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewer;
class DataBaseViewerElement;
class DataBase;
class DataBaseObject;
class QLineEdit;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseViewerList -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewerList : public QWidget{
public:
    // _CONSTRUCTORS_ DataBaseViewerList.hpp
    DataBaseViewerList(DataBaseViewer* parent);

    // _DESTRUCTORS_ DataBaseViewerList.hpp
    ~DataBaseViewerList();

private:
    // _PRIVATE_MEMBERS_ DataBaseViewerList.hpp
    DataBaseViewer* parent = nullptr;
    DataBaseViewerElement** elements = nullptr;
    uint numbOfElements = 0;
    DataBaseViewerElement* currentElement = nullptr;

    DataBaseViewerElement* elementAtEditMode = nullptr;
    bool newNameAccepted = false;

    bool newObjectFlag = false;

    bool reallocationFlag = false;
public:
    // _PUBLIC_MEMBERS_ DataBaseViewerList.hpp

private:
    // _PRIVATE_METHODS_ DataBaseViewerList.hpp
    void initalize();
    void createObjects();
    void createLayout();
    void connectEvents();
    void clearMemory();
public:
    // _PUBLIC_METHODS_ DataBaseViewerList.hpp
    GET_DECLARATION(DataBaseViewer*, parent)
    GET_DECLARATION(DataBaseViewerElement**, elements)
    GET_DECLARATION(uint, numbOfElements)
    GET_DECLARATION(DataBaseViewerElement*, currentElement)
    GET_DECLARATION(DataBaseViewerElement*, elementAtEditMode)
    GET_SET_DECLARATION(bool, newNameAccepted)
    GET_SET_DECLARATION(bool, newObjectFlag)

    void reload();
    bool addElement(DataBaseViewerElement* newElem);
    bool removeElement(DataBaseViewerElement* remElem);
    void clearElements();
    bool load(DataBase*);
    bool loadDBObject(DataBaseObject*);
    void reallocateElements(DataBaseViewerElement*&);   // Caller (Reallocate from caller, if caller == nullptr, from first element)

    void addNewDbObject(DataBaseObject* dbObj){
        newObjectFlag = true;

        loadDBObject(dbObj);
    }
    void selectElement(DataBaseViewerElement* ele){currentElement = ele; repaint();}
    void putElementAtEditMode(DataBaseViewerElement* ele);
    void editModeAccept();
    void editModeCancel();
    void paintEvent(QPaintEvent* ev);
    void resizeEvent(QResizeEvent* ev);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEVIEWERLIST
