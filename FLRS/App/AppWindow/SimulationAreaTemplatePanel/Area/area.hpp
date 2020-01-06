#ifndef PAINTAREA_HPP
#define PAINTAREA_HPP

#include<QWidget>
#include<QGraphicsView>
//#include"../SimulationAreaTemplateTools/painttools.hpp"
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.hpp"

class SimulationAreaTemplatePanel;
class QGraphicsScene;
class SimulationAreaTemplateArea : public QGraphicsView{
public:
    SimulationAreaTemplateArea(SimulationAreaTemplatePanel* parent, QGraphicsScene* refScene = nullptr);
    virtual ~SimulationAreaTemplateArea() override;

protected:
    SimulationAreaTemplatePanel* parent = nullptr;

    //SimulationAreaTemplateTools paintTools;
    //QGraphicsView view;
    //QGraphicsScene* refScene = nullptr;
    bool repaintPixelPointer = false;

    void initalize();
    virtual void createObjects();
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();

    inline void saveView();
public:
    GET_DECLARATION(SimulationAreaTemplatePanel*, parent)

    void resizeEvent(QResizeEvent* ev) override;
    void paintEvent(QPaintEvent* ev) override;
    bool eventFilter(QObject* obj, QEvent* ev) override;
    void wheelEvent(QWheelEvent* ev)override;

    inline SimulationAreaTemplate* scene();
    void setScene(SimulationAreaTemplate*);
};

#endif // PAINTAREA_HPP
