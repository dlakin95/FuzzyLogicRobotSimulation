#ifndef PAINTTOOLS_HPP
#define PAINTTOOLS_HPP
#include<QToolBar>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

#define PAINT_TOOLS_OPTION_ICON_ACCESS(enumName) enumName##_ICON

#define PAINT_TOOLS_OPTION_RECT_ICON (QIcon("Icons/paintToolRect.png"))
#define PAINT_TOOLS_OPTION_SIMULATION_AREA_ICON (QIcon("Icons/paintToolLEDMatrix.png"))
#define PAINT_TOOLS_OPTION_ELIPSE_ICON (QIcon("Icons/paintToolLEDMatrix.png"))
#define PAINT_TOOLS_OPTION_ROBOT_ICON (QIcon("Icons/paintToolLEDMatrix.png"))

enum SimulationAreaTemplateToolsOptions{
    PAINT_TOOLS_OPTION_SIMULATION_AREA,
    PAINT_TOOLS_OPTION_RECT,
    PAINT_TOOLS_OPTION_ELIPSE,
    PAINT_TOOLS_OPTION_ROBOT,
    NUMB_OF_PAINT_TOOLS_OPTIONS
};

class SimulationAreaTemplatePanel;
class SimulationAreaTemplateTools : public QToolBar{
    Q_OBJECT
public:
    SimulationAreaTemplateTools(SimulationAreaTemplatePanel*);
    ~SimulationAreaTemplateTools();

private:
    SimulationAreaTemplatePanel* parent = nullptr;

    QAction paintToolsOptions[NUMB_OF_PAINT_TOOLS_OPTIONS];

    void init();

public:
    GET_DECLARATION(SimulationAreaTemplatePanel*, parent)

    void actionRun(SimulationAreaTemplateToolsOptions option);
    void reloadToolBar();
    bool eventFilter(QObject*, QEvent*);    

public slots:
    void addSimulationAreaTemplate();
    void addRect();
    void addElipse();
    void addRobot();
};

#endif // PAINTTOOLS_HPP
