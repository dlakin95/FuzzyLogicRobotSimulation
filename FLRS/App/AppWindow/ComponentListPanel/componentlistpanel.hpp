#ifndef COMPONENTLISTPANEL_HPP
#define COMPONENTLISTPANEL_HPP

#include<QScrollArea>
#include"componentlist.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"


class AppWindow;
class SimulationAreaTemplate;
class DataBaseObject;
class ComponentListPanel : public QScrollArea{
public:
    ComponentListPanel(AppWindow* parent);
    ~ComponentListPanel();

protected:
    AppWindow* parent = nullptr;
    ComponentList list;

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
        GET_DECLARATION(ComponentList&, list)

        void reload();

        void clear();
        bool clearAndLoad(SimulationAreaTemplate*);
        bool load(SimulationAreaTemplate*);
        bool clearAndLoadDbObj(DataBaseObject*);
        bool loadDbObj(DataBaseObject*);

        //inline void addNewDbObj(DataBaseObject* dbObj){
        //    if(dbObj){
        //        list.addNewDbObject(dbObj);
        //    }
        //}

        virtual ComponentListElement* createElement(DataBaseObject*, ComponentListElement*);
        virtual ComponentListElement* createElement(DataBaseObject*, ComponentListElement*, uint);

        inline bool addElement(ComponentListElement* newElem){
            return list.addElement(newElem);
        }

        inline bool removeElement(ComponentListElement* remElem){
            return list.removeElement(remElem);
        }

        void resizeEvent(QResizeEvent* ev);
        void paintEvent(QPaintEvent* ev);
        bool eventFilter(QObject* obj, QEvent* ev);

};

#endif // COMPONENTLISTPANEL_HPP
