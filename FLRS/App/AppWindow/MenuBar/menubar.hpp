#ifndef MENUBAR_HPP
#define MENUBAR_HPP

// _INCLUDES_ MenuBar.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QMenuBar>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ MenuBar.hpp --------------------------------------------------------------------------------------------------------------------------------------
class AppWindow;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

#define MB_NAME_ACCESS(enumName) enumName##_TITLE
// MENU CONGIGURATION ----------------------------------------------------------------------------------------
enum MenuBarMenus{
    MENU_BAR_MENU_FILE,
    MENU_BAR_MENU_TOOLS,
    NUMB_OF_MENU_BAR_MENUS
};
// Menu Names
#define MENU_BAR_MENU_FILE_TITLE (QString("File"))
#define MENU_BAR_MENU_TOOLS_TITLE (QString("Tools"))

enum MenuBarMenuFileOptions{
    MENU_BAR_MENU_FILE_OPTION_NEW,
    MENU_BAR_MENU_FILE_OPTION_OPEN,
    MENU_BAR_MENU_FILE_OPTION_SAVE,
    MENU_BAR_MENU_FILE_OPTION_SAVE_AS,
    MENU_BAR_MENU_FILE_OPTION_CLOSE,
    NUMB_OF_MENU_BAR_FILE_OPTIONS
};

// File Menu Options Names
#define MENU_BAR_MENU_FILE_OPTION_NEW_TITLE QString("New")
#define MENU_BAR_MENU_FILE_OPTION_OPEN_TITLE QString("Open")
#define MENU_BAR_MENU_FILE_OPTION_SAVE_TITLE QString("Save")
#define MENU_BAR_MENU_FILE_OPTION_SAVE_AS_TITLE QString("Save As")
#define MENU_BAR_MENU_FILE_OPTION_CLOSE_TITLE QString("Close")

enum MenuBarMenuToolsOptions{
    MENU_BAR_MENU_TOOLS_OPTION_DRAW_POINT,
    MENU_BAR_MENU_TOOLS_OPTION_DRAW_LINE,
    MENU_BAR_MENU_TOOLS_OPTION_DRAW_RECT,
    MENU_BAR_MENU_TOOLS_OPTION_DRAW_ELIPSE,
    MENU_BAR_MENU_TOOLS_OPTION_CLEAR_RECT,
    NUMB_OF_MENU_BAR_TOOLS_OPTIONS
};

// Tools Menu Options Names
#define MENU_BAR_MENU_TOOLS_OPTION_DRAW_POINT_TITLE QString("Draw Point")
#define MENU_BAR_MENU_TOOLS_OPTION_DRAW_LINE_TITLE QString("Draw Line")
#define MENU_BAR_MENU_TOOLS_OPTION_DRAW_RECT_TITLE QString("Draw Rect")
#define MENU_BAR_MENU_TOOLS_OPTION_DRAW_ELIPSE_TITLE QString("Draw Elipse")
#define MENU_BAR_MENU_TOOLS_OPTION_CLEAR_RECT_TITLE QString("Clear Rect")

// -----------------------------------------------------------------------------------------------------------

// _CLASSDEF_ MenuBar -----------------------------------------------------------------------------------------------------------------------------------------------
class MenuBar : public QMenuBar{
public:
    // _CONSTRUCTORS_ MenuBar.hpp
    MenuBar(AppWindow*);
    // _DESTRUCTORS_ MenuBar.hpp
    ~MenuBar();

protected:
    // _PRIVATE_MEMBERS_ MenuBar.hpp
     static const QString menuNames[NUMB_OF_MENU_BAR_MENUS];
     static const QString menuFileOptionNames[NUMB_OF_MENU_BAR_FILE_OPTIONS];
     static const QString menuToolsOptionNames[NUMB_OF_MENU_BAR_TOOLS_OPTIONS];
     static const QString* menuOptionsNames[NUMB_OF_MENU_BAR_MENUS];

     static const uint menuOptionsNumb[NUMB_OF_MENU_BAR_MENUS];
    AppWindow* parent = nullptr;

    QMenu menus[NUMB_OF_MENU_BAR_MENUS];

    QAction fileOptions[NUMB_OF_MENU_BAR_FILE_OPTIONS];
    QAction toolsOptions[NUMB_OF_MENU_BAR_TOOLS_OPTIONS];

    QAction* options[NUMB_OF_MENU_BAR_MENUS] = {
        fileOptions,
        toolsOptions
    };

public:
    // _PUBLIC_MEMBERS_ MenuBar.hpp

protected:
    // _PRIVATE_METHODS_ MenuBar.hpp
    void createMenu();
    void createOptions();

    void newBaseOptionTriggerred();
    void openBaseOptionTriggerred();
    void saveBaseOptionTriggerred();
    void saveAsBaseOptionTriggerred();
    void closeBaseOptionTriggerred();

    void newDBObjectOptionTriggerred();
    void openDBObjectOptionTriggerred();
    void saveDBObjectOptionTriggerred();
    void closeDBObjectOptionTriggerred();

public:
    // _PUBLIC_METHODS_ MenuBar.hpp
    GET_DECLARATION(AppWindow*, parent)

    void reloadMenu();
    bool eventFilter(QObject*, QEvent*);
};


// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // MENUBAR_HPP
