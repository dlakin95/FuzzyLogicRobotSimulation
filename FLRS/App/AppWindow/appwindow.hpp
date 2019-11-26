#ifndef APPWINDOW_HPP
#define APPWINDOW_HPP

#include"App/AppWindow/ComponentListPanel/componentlistpanel.hpp"
#include<QWidget>
#include<QSplitter>
#include"MenuBar/menubar.hpp"
#include"ToolBar/toolbar.hpp"
#include"App/AppWindow/SATListPanel/listpanel.hpp"
#include"App/AppWindow/SimulationAreaTemplatePanel/templatepanel.hpp"

class App;
class AppWindow : public QWidget{
public:
    AppWindow(App* parent);
    ~AppWindow();
private:
    // Parent
    App* parent = nullptr;

    // Top
    MenuBar menuBar;
    ToolBar toolBar;

    // Horizontal Splitter for  ------------------------------------------------------
    QSplitter splitter;

    // Splitter Content =============================================================

    // Components List Panel (SimulationAreaTemplates Splitter <- List of SimulationAreaTemplates  + List of Components - GraphicalObjects)
    QSplitter templatesSplitter;
    SimulationAreaTemplatesListPanel simulationAreaTemplatesListPanel;
    ComponentListPanel componentListPanel;

    // SimulationAreaTemplate Panel
    SimulationAreaTemplatePanel paintPanel;

    // ===============================================================================
    // -------------------------------------------------------------------------------

    // _PRIVATE_METHODS_ AppWindow.hpp
    void initilize();
    void createObjects();   // Pointers Only
    void createLayout();
    void connectEvents();
    void clearMemory();
public:
    // _PUBLIC_METHODS_ AppWindow.hpp
    GET_DECLARATION(App*, parent)
    GET_DECLARATION(QSplitter&, windowSplitter)
    GET_DECLARATION(SimulationAreaTemplatesListPanel&, simulationAreaTemplatesListPanel)

    void resizeEvent(QResizeEvent* ev);
    bool eventFilter(QObject*, QEvent*);
    void reload();
};

#endif // APPWINDOW_HPP
