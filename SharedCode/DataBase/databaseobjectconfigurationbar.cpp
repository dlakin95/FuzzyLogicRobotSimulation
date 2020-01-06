// _INCLUDES_ DataBaseObjectConfigurationBar.cpp -------------------------------------------------------------------------------------------------------------------
#include"databaseobjectconfigurationbar.hpp"
#include"../SharedCode/OperationPanel/operationpanel.hpp"
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseObjectConfigurationBar -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseObjectConfigurationBar.cpp
DataBaseObjectConfigurationBar::DataBaseObjectConfigurationBar(OperationPanel* parent) : QWidget (parent), parent(parent), titleLabel(this), configurationButton(this){
    initialize();
}

// _DESTRUCTORS_ DataBaseObjectConfigurationBar.cpp
DataBaseObjectConfigurationBar::~DataBaseObjectConfigurationBar(){

}


// _PRIVATE_METHODS_ DataBaseObjectConfigurationBar.cpp
void DataBaseObjectConfigurationBar::initialize(){
    createObjects();
    createLayout();
    connectEvents();
}

void DataBaseObjectConfigurationBar::createObjects(){
    titleLabel.setReadOnly(true);
    configurationButton.setScaledContents(true);
}

void DataBaseObjectConfigurationBar::createLayout(){
    titleLabel.setGeometry(LO_OPERATION_PANEL_CONFIG_BAR_TITLE_LABEL_GEOMETRY);
    configurationButton.setGeometry(LO_OPERATION_PANEL_CONFIG_BAR_SWITCH_MODE_BUTTON_GEOMETRY);
}

void DataBaseObjectConfigurationBar::connectEvents(){

}

void DataBaseObjectConfigurationBar::clearMemory(){

}

// _PUBLIC_METHODS_ DataBaseObjectConfigurationBar.cpp

bool DataBaseObjectConfigurationBar::eventFilter(QObject *obj, QEvent *ev){
    return QObject::eventFilter(obj, ev);
}

void DataBaseObjectConfigurationBar::resizeEvent(QResizeEvent *ev){
    DataBaseObjectConfigurationBar::createLayout();
}



// ----------------------------------------------------------------------------------------------------------------------------------------------



