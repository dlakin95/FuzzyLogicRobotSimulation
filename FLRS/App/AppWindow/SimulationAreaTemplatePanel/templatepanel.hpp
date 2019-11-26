#ifndef PAINTPANEL_HPP
#define PAINTPANEL_HPP

#include<QWidget>
#include<QGraphicsView>
#include"Area/area.hpp"
#include"Tools/tools.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class AppWindow;
class QGraphicsScene;
class SimulationAreaTemplatePanel : public QWidget{
public:
    SimulationAreaTemplatePanel(AppWindow* parent);
    ~SimulationAreaTemplatePanel();

protected:
    AppWindow* parent = nullptr;

    SimulationAreaTemplateTools paintTools;
    SimulationAreaTemplateArea paintArea;

    //QGraphicsView paintArea;
    //QGraphicsScene* refScene = nullptr;

    void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();
public:
    GET_DECLARATION(SimulationAreaTemplateArea&, paintArea)

    void resizeEvent(QResizeEvent* ev);
    void paintEvent(QPaintEvent* ev);
    bool eventFilter(QObject* obj, QEvent* ev);
    void reload();
};

#endif // PAINTPANEL_HPP
