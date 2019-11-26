#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP
#include<QToolBar>
#include<QAction>
#include<QIcon>

#define TB_NAME_ACCESS(enumName) enumName##_ICON
#define TB_CHECKABLE_ACCESS(enumName) enumName##_CHECKABLE

// TOOL CONFIGURATION ----------------------------------------------------------------------------------------

enum ToolBarOptions{
    TOOL_BAR_OPTION_DRAW_POINT,
    TOOL_BAR_OPTION_DRAW_LINE,
    TOOL_BAR_OPTION_DRAW_RECT,
    TOOL_BAR_OPTION_DRAW_ELIPSE,
    TOOL_BAR_OPTION_CLEAR_RECT,
    NUMB_OF_TOOL_BAR_OPTIONS
};

// Tools Menu Options Names
#define TOOL_BAR_OPTION_DRAW_POINT_ICON QString("Draw Point")
#define TOOL_BAR_OPTION_DRAW_LINE_ICON QString("Draw Line")
#define TOOL_BAR_OPTION_DRAW_RECT_ICON QString("Draw Rect")
#define TOOL_BAR_OPTION_DRAW_ELIPSE_ICON QString("Draw Elipse")
#define TOOL_BAR_OPTION_CLEAR_RECT_ICON QString("Clear Rect")

// Tools Menu Options Names
#define TOOL_BAR_OPTION_DRAW_POINT_CHECKABLE (true)
#define TOOL_BAR_OPTION_DRAW_LINE_CHECKABLE (true)
#define TOOL_BAR_OPTION_DRAW_RECT_CHECKABLE (true)
#define TOOL_BAR_OPTION_DRAW_ELIPSE_CHECKABLE (true)
#define TOOL_BAR_OPTION_CLEAR_RECT_CHECKABLE (true)

class AppWindow;
class ToolBar : public QToolBar{
public:
    ToolBar(AppWindow*);
    ~ToolBar();

    static const QIcon icons[NUMB_OF_TOOL_BAR_OPTIONS];
    static constexpr bool optionCheckable[NUMB_OF_TOOL_BAR_OPTIONS] = {
       TB_CHECKABLE_ACCESS(TOOL_BAR_OPTION_DRAW_POINT),
       TB_CHECKABLE_ACCESS(TOOL_BAR_OPTION_DRAW_LINE),
       TB_CHECKABLE_ACCESS(TOOL_BAR_OPTION_DRAW_RECT),
       TB_CHECKABLE_ACCESS(TOOL_BAR_OPTION_DRAW_ELIPSE),
       TB_CHECKABLE_ACCESS(TOOL_BAR_OPTION_CLEAR_RECT),
    };

    AppWindow* parent = nullptr;
    QAction buttons[NUMB_OF_TOOL_BAR_OPTIONS];

    void init();    
    bool eventFilter(QObject* obj, QEvent* ev);
    void actionRun(ToolBarOptions i);
};


#endif // TOOLBAR_HPP
