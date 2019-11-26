

// _INCLUDES_ MenuBar.cpp -------------------------------------------------------------------------------------------------------------------
#include"menubar.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindow.hpp"
#include"../../app.hpp"
#include"../appwindowlayoutmacros.hpp"
#include<QFile>
#include<QEvent>
#include<QDebug>
#include"App/FLRS_DB/flrsdatabase.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ MenuBar -----------------------------------------------------------------------------------------------------------------------------------------------
const QString MenuBar::menuNames[NUMB_OF_MENU_BAR_MENUS] =  {
    MB_NAME_ACCESS(MENU_BAR_MENU_FILE),
    MB_NAME_ACCESS(MENU_BAR_MENU_TOOLS)
};

const QString MenuBar::menuFileOptionNames[NUMB_OF_MENU_BAR_FILE_OPTIONS] =  {
    MB_NAME_ACCESS(MENU_BAR_MENU_FILE_OPTION_NEW),
    MB_NAME_ACCESS(MENU_BAR_MENU_FILE_OPTION_OPEN),
    MB_NAME_ACCESS(MENU_BAR_MENU_FILE_OPTION_SAVE),
    MB_NAME_ACCESS(MENU_BAR_MENU_FILE_OPTION_SAVE_AS),
    MB_NAME_ACCESS(MENU_BAR_MENU_FILE_OPTION_CLOSE)
};

const QString MenuBar::menuToolsOptionNames[NUMB_OF_MENU_BAR_TOOLS_OPTIONS] =  {
    MB_NAME_ACCESS(MENU_BAR_MENU_TOOLS_OPTION_DRAW_POINT),
    MB_NAME_ACCESS(MENU_BAR_MENU_TOOLS_OPTION_DRAW_LINE),
    MB_NAME_ACCESS(MENU_BAR_MENU_TOOLS_OPTION_DRAW_RECT),
    MB_NAME_ACCESS(MENU_BAR_MENU_TOOLS_OPTION_DRAW_ELIPSE),
    MB_NAME_ACCESS(MENU_BAR_MENU_TOOLS_OPTION_CLEAR_RECT)
};

const QString* MenuBar::menuOptionsNames[NUMB_OF_MENU_BAR_MENUS] = {
    menuFileOptionNames,
    menuToolsOptionNames
};

const uint MenuBar::menuOptionsNumb[NUMB_OF_MENU_BAR_MENUS] = {
    NUMB_OF_MENU_BAR_FILE_OPTIONS,
    NUMB_OF_MENU_BAR_TOOLS_OPTIONS
};

// _CONSTRUCTORS_ MenuBar.cpp
MenuBar::MenuBar(AppWindow* parent) : QMenuBar (parent), parent(parent)
{
    createMenu();
    createOptions();
}

// _DESTRUCTORS_ MenuBar.cpp
MenuBar::~MenuBar(){

}

// _PRIVATE_METHODS_ MenuBar.cpp
void MenuBar::createMenu(){
    for(uint i = 0; i < NUMB_OF_MENU_BAR_MENUS; i++)
    {
        QMenu* curMenu = menus + i;
        curMenu->setTitle(menuNames[i]);
        addMenu(curMenu);
        curMenu->installEventFilter(this);
    }
}

void MenuBar::createOptions(){
    for(uint curMenuI = 0; curMenuI < NUMB_OF_MENU_BAR_MENUS; curMenuI++){
        QMenu* curMenu = menus + curMenuI;
        uint curMenuNumbOfOptions = MenuBar::menuOptionsNumb[curMenuI];
        for(uint curOptionI = 0; curOptionI < curMenuNumbOfOptions; curOptionI++){
            QAction* curOption = options[curMenuI] + curOptionI;
            curOption->setText(menuOptionsNames[curMenuI][curOptionI]);
            curOption->setParent(curMenu);
            curMenu->addAction(curOption);
        }
    }
}

// _PUBLIC_METHODS_ MenuBar.cpp
GET_DEFINITION(MenuBar, AppWindow*, parent)

void MenuBar::reloadMenu(){

}

bool MenuBar::eventFilter(QObject *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::MouseButtonRelease:
    if(&menus[MENU_BAR_MENU_FILE] == obj){
        if(menus[MENU_BAR_MENU_FILE].activeAction() == &fileOptions[MENU_BAR_MENU_FILE_OPTION_OPEN]){
            openBaseOptionTriggerred();
            break;
        }
        if(menus[MENU_BAR_MENU_FILE].activeAction() == &fileOptions[MENU_BAR_MENU_FILE_OPTION_SAVE]){
            saveBaseOptionTriggerred();
            break;
        }
    }
        /*
        if(dataBaseMenu.activeAction() == dataBaseOptions + 1){

            break;
        }
        if(dataBaseMenu.activeAction() == dataBaseOptions + 2){
            saveBaseOptionTriggerred();
            break;
        }
        if(dataBaseMenu.activeAction() == dataBaseOptions + 3){
            saveAsBaseOptionTriggerred();
            break;
        }
        if(dataBaseMenu.activeAction() == dataBaseOptions + 4){
            closeBaseOptionTriggerred();
            break;
        }
    }
    if(&graphicalObjectMenu == obj){
        if(graphicalObjectMenu.activeAction() == graphicalObjectOptions){
            newDBObjectOptionTriggerred();
            break;
        }
        if(graphicalObjectMenu.activeAction() == graphicalObjectOptions + 1){
            openDBObjectOptionTriggerred();
            break;
        }
        if(graphicalObjectMenu.activeAction() == graphicalObjectOptions + 2){
            saveDBObjectOptionTriggerred();
            break;
        }
        if(graphicalObjectMenu.activeAction() == graphicalObjectOptions + 3){
            closeDBObjectOptionTriggerred();
            break;
        }
    }
        break;*/
    default:
        break;
    }
    return QObject::eventFilter(obj, ev);
}

void MenuBar::openBaseOptionTriggerred(){
    FuzzyLogicRobotSimulationDataBase* db = new FuzzyLogicRobotSimulationDataBase();
    if(!parent->get_parent()->get_dbMenager().openDataBase(*db)){
        SET_PTR_DO(db, nullptr);
    }
    parent->get_simulationAreaTemplatesListPanel().load(db);
}

void MenuBar::saveBaseOptionTriggerred(){
    FuzzyLogicRobotSimulationDataBase* db = static_cast<FuzzyLogicRobotSimulationDataBase*>(parent->get_simulationAreaTemplatesListPanel().get_list().get_currentElementRefObj());
    //if(db && db->getObjectType() == DB_GET_REAL_TYPE(DataBaseObject, DATABASE_OBJECT_DATABASE) && parent->get_parent()->get_dbMenager().saveDataBase(*db))

}

// ----------------------------------------------------------------------------------------------------------------------------------------------
