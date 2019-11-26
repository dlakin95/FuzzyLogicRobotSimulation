#ifndef PICTURESLISTPANEL_HPP
#define PICTURESLISTPANEL_HPP


#include<QScrollArea>
#include"list.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class AppWindow;
class FuzzyLogicRobotSimulationDataBase;
class DataBaseObject;
class SimulationAreaTemplatesListPanel : public QScrollArea{
public:
    SimulationAreaTemplatesListPanel(AppWindow* parent);
    ~SimulationAreaTemplatesListPanel();

protected:
    AppWindow* parent = nullptr;
    SimulationAreaTemplatesList list;

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
        GET_DECLARATION(SimulationAreaTemplatesList&, list)

        void reload(){list.reload();}

        void clear();
        bool clearAndLoad(FuzzyLogicRobotSimulationDataBase*);
        bool load(FuzzyLogicRobotSimulationDataBase*);
        //bool clearAndLoadDbObj(DataBaseObject*);
        //bool loadDbObj(DataBaseObject*);

        inline void addNewDbObj(FuzzyLogicRobotSimulationDataBase* dbObj){
            if(dbObj){
                list.addNewDbObject(dbObj);
            }
        }

        virtual SimulationAreaTemplatesListElement* createElement(DataBaseObject*, SimulationAreaTemplatesListElement*);
        virtual SimulationAreaTemplatesListElement* createElement(DataBaseObject*, SimulationAreaTemplatesListElement*, uint);

        //inline bool addElement(SimulationAreaTemplatesListElement* newElem){
        //    return list.addElement(newElem);
        //}

        //inline bool removeElement(SimulationAreaTemplatesListElement* remElem){
        //    return list.removeElement(remElem);
        //}

        void resizeEvent(QResizeEvent* ev);
        void paintEvent(QPaintEvent* ev);
        bool eventFilter(QObject* obj, QEvent* ev);

};


#endif // PICTURESLISTPANEL_HPP
