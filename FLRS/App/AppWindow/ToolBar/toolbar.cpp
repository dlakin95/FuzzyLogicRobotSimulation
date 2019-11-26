#include"toolbar.hpp"
#include<QMouseEvent>
#include<QMenu>
#include"../appwindow.hpp"


const QIcon ToolBar::icons[NUMB_OF_TOOL_BAR_OPTIONS] = {
  QIcon(TB_NAME_ACCESS(TOOL_BAR_OPTION_DRAW_POINT)),
  QIcon(TB_NAME_ACCESS(TOOL_BAR_OPTION_DRAW_LINE)),
  QIcon(TB_NAME_ACCESS(TOOL_BAR_OPTION_DRAW_RECT)),
  QIcon(TB_NAME_ACCESS(TOOL_BAR_OPTION_DRAW_ELIPSE)),
  QIcon(TB_NAME_ACCESS(TOOL_BAR_OPTION_CLEAR_RECT)),
};

ToolBar::ToolBar(AppWindow* parent) : QToolBar (parent), parent(parent){
    init();
}

ToolBar::~ToolBar(){

}

void ToolBar::init(){
    for(uint i = 0; i < NUMB_OF_TOOL_BAR_OPTIONS; i++){
        QAction* tempAction = buttons + i;
        tempAction->setIcon(icons[i]);
        tempAction->setParent(this);
    }
}

void ToolBar::actionRun(ToolBarOptions i){
    switch(i){
    case TOOL_BAR_OPTION_DRAW_POINT:
    {
        //parent->parent->readNewScript();
    }
        break;
    default:
        break;
    }
}

bool ToolBar::eventFilter(QObject *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::MouseButtonRelease:
    {
        if(obj == this){
            QAction* activeted = actionAt(static_cast<QMouseEvent*>(ev)->pos());
            if(activeted){
                uint i = 0;
                for( ; i < NUMB_OF_TOOL_BAR_OPTIONS; i++)
                    if(buttons + i == activeted)
                        break;
                if(i == NUMB_OF_TOOL_BAR_OPTIONS)
                    break;
            }
        }
    }
        break;
    default:
        break;
    }
    return QWidget::eventFilter(obj, ev);
}

