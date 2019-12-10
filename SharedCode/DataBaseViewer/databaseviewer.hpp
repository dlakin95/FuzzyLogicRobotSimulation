#ifndef DATABASEVIEWER_HPP
#define DATABASEVIEWER_HPP
// _INCLUDES_ DataBaseViewer.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"databaseviewerlist.hpp"
#include<QScrollArea>
#include"../SharedCode/GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"../SharedCode/DataBase/databaseobjecttype.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseViewer.hpp --------------------------------------------------------------------------------------------------------------------------------------
class AppWindow;
class DataBase;
class DataBaseObject;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseViewer -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseViewer : public QScrollArea{
public:
    // _CONSTRUCTORS_ DataBaseViewer.hpp
    DataBaseViewer(AppWindow* parent);
    // _DESTRUCTORS_ DataBaseViewer.hpp
    virtual ~DataBaseViewer();

protected:
    // _PRIVATE_MEMBERS_ DataBaseViewer.hpp
    AppWindow* parent = nullptr;
    DataBaseViewerList list;

public:
    // _PUBLIC_MEMBERS_ DataBaseViewer.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseViewer.hpp
    void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();

    void createContextMenu(QAction* actions);
    void execContextMenu(QPoint& eventPos);

public:
    // _PUBLIC_METHODS_ DataBaseViewer.hpp
    GET_DECLARATION(AppWindow*, parent)
    GET_DECLARATION(DataBaseViewerList&, list)

    void reload(){list.reload();}

    void clear();
    bool clearAndLoad(DataBase*);
    bool load(DataBase*);
    bool clearAndLoadDbObj(DataBaseObject*);
    bool loadDbObj(DataBaseObject*);

    inline void addNewDbObj(DataBaseObject* dbObj){
        if(dbObj){
            list.addNewDbObject(dbObj);
        }
    }

    virtual DataBaseViewerElement* createElement(DataBaseObject*, DataBaseViewerElement*);
    virtual DataBaseViewerElement* createElement(DataBaseObject*, DataBaseViewerElement*, uint);

    inline bool addElement(DataBaseViewerElement* newElem){
        return list.addElement(newElem);
    }

    inline bool removeElement(DataBaseViewerElement* remElem){
        return list.removeElement(remElem);
    }

    void resizeEvent(QResizeEvent* ev);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEVIEWER
