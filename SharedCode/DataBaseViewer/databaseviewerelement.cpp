
// _INCLUDES_ DataBaseViewerElement.cpp -------------------------------------------------------------------------------------------------------------------
#include "databaseviewerelement.hpp"
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
#include<QResizeEvent>
#include"databaseviewerlist.hpp"
#include<QPainter>
#include<QPen>
#include"../SharedCode/DataBase/databaseobject.hpp"
#include"../SharedCode/DataBase/getparamrules.hpp"
#include"../SharedCode/DataBase/databasesearchengine.hpp"
#include<QAction>
#include<QMenu>
#include<QKeyEvent>
#include"databaseviewer.hpp"
#include"../SharedCode/AppWindow/appwindow.hpp"
#include"../SharedCode/App/app.hpp"
#include"../SharedCode/DataBase/databasecategory.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseViewerElement -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseViewerElement.cpp
DataBaseViewerElement::DataBaseViewerElement(DataBaseViewerList* mainListParent, DataBaseObject*& refObj, DataBaseViewerElement* refListParent) :
    mainListParent(mainListParent), parent(refListParent), refObj(refObj), titleLE(this), checkBox(this)
{
    initalize();
    if(refListParent)
        setParent(refListParent);
    else {
        setParent(mainListParent);
    }
}


// _DESTRUCTORS_ DataBaseViewerElement.cpp
DataBaseViewerElement::~DataBaseViewerElement(){
    clearMemory();
}

// _PRIVATE_METHODS_ DataBaseViewerElement.cpp
void DataBaseViewerElement::initalize(){
    setUpdatesEnabled(false);
    generateText();
    createObjects();
    createLayout();
    connectEvents();
}

void DataBaseViewerElement::generateText(){

}

void DataBaseViewerElement::createObjects(){
    if(!mainListParent->get_newObjectFlag()){
        QString title;
        GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
        if(!refObj->getParam(&title, gpr) || !gpr.initialized || title.isEmpty()){
            titleLE.setText(QString("DatabaseObject Error"));
        }else{
            titleLE.setText(title);
        }
    }
}

void DataBaseViewerElement::createLayout(){
    generateText();    
    // Title Label    
    if(mainListParent->get_elementAtEditMode() == this){
        if(!mainListParent->get_newNameAccepted()){
            titleLE.setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
        }else{
            titleLE.setStyleSheet("");
        }
        titleLE.setFrame(true);
        titleLE.setReadOnly(false);
    }else{
        titleLE.setReadOnly(true);
        titleLE.setFrame(false);
        titleLE.setStyleSheet("");
    }
    titleLE.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_GEOMETRY);

    // CheckBox
    checkBox.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_GEOMETRY);
}

void DataBaseViewerElement::connectEvents(){
    titleLE.installEventFilter(this);
    this->installEventFilter(this);
}

void DataBaseViewerElement::clearMemory(){

}

void DataBaseViewerElement::reallocateElements(DataBaseViewerElement* &caller){
    curHeight = LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT;
}

void DataBaseViewerElement::createContextMenu(QAction *actions){
    // Action 1 (0) Add Test Group
    (actions + 0)->setText("Change Name");
    (actions + 0)->setParent(this);
}

void DataBaseViewerElement::execContextMenu(QPoint& eventPos){
    QMenu menu;
    QAction action[1];
    createContextMenu(action);
    uint i = 0;
    for( ; i < 1; i++){
        menu.addAction(action + i);
    }
    QAction* at = nullptr;
    at = menu.exec(eventPos);
    for(i = 0; i < 1; i++){
        if(at == action + i)
            break;
    }
    switch(i){
    case 0:
    {
        mainListParent->putElementAtEditMode(this);
    }
        break;
    default:
        break;
    }
}


// _PUBLIC_METHODS_ DataBaseViewerElement.cpp
GET_DEFINITION(DataBaseViewerElement, DataBaseViewerList*, mainListParent)
GET_DEFINITION(DataBaseViewerElement, DataBaseViewerElement*, parent)
GET_DEFINITION(DataBaseViewerElement, uint, curHeight)
GET_SET_NDO_DEFINITION(DataBaseViewerElement, DataBaseObject*, refObj)
GET_DEFINITION(DataBaseViewerElement, QLineEdit&, titleLE)
GET_SET_NDO_DEFINITION(DataBaseViewerElement, bool, reallocationFlag);

bool DataBaseViewerElement::editModeCheckName(QKeyEvent *ev){
    QLineEdit* le = &titleLE;
    uint len = le->text().length();
    if(len > 29){
        switch(ev->key()){
        case Qt::Key_Left:
            return false;
        case Qt::Key_Right:
            return false;
        case Qt::Key_Backspace:
            le->backspace();
            break;
        case Qt::Key_Delete:
            le->del();
            break;
        default:
            return true;
        }
    }
    else{
        switch(ev->key()){
        case Qt::Key_Escape:
            mainListParent->editModeCancel();
            return true;
        case Qt::Key_Left:
            return false;
        case Qt::Key_Right:
            return false;
        case Qt::Key_Enter:
            return true;
        case Qt::Key_Tab:
            return true;
        case Qt::Key_Slash:
            return true;
        case Qt::Key_Backslash:
            return true;
        case Qt::Key_Return:
            mainListParent->editModeAccept();
            return true;
        case Qt::Key_Colon:
            return true;
        case Qt::Key_Asterisk:
            return true;
        case Qt::Key_Less:
            return true;
        case Qt::Key_Greater:
            return true;
        case Qt::Key_QuoteDbl:
            return true;
        case Qt::Key_Question:
            return true;
        case Qt::Key_Bar:
            return true;
        case Qt::Key_Alt:
            return true;
        case Qt::Key_Shift:
            return true;
        case Qt::Key_Control:
            return true;
        case Qt::Key_Space:
            return true;
        case Qt::Key_Backspace:
            le->backspace();
            break;
        case Qt::Key_Delete:
            le->del();
            break;
        default:
            le->insert(ev->text());
            break;
        }
    }    
    len = le->text().length();
    if(le->text().isEmpty() || len > 30){
        //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
        mainListParent->set_newNameAccepted(false);
        return true;
    }    else{
        //le->setStyleSheet("");
    }

    // Check if category exist    
    QString tempText = le->text();
    DataBaseSearchEngineFilter* filter = new DataBaseSearchEngineFilter;
    if(!parent){
        DataBase* refDB = mainListParent->get_parent()->get_parent()->get_parent()->get_dbMenager().get_dataBase();
        filter->initialize(true, DATABASE_OBJECT_CATEGORY, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        DataBaseSearchEngine dbSearchEngine;
        dbSearchEngine.addFilter(filter);
        if(dbSearchEngine.search(refDB)){   // Success
            if(dbSearchEngine.get_result().numbOfObjects > 0){  // Category with the same name exist
                if(!mainListParent->get_newObjectFlag()){
                    QString oldName;
                    GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
                    if(!refObj->getParam(&oldName, gpr)){
                        //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                        mainListParent->set_newNameAccepted(false);
                    }
                    if(oldName == tempText){
                        //le->setStyleSheet("");
                        mainListParent->set_newNameAccepted(true);
                    }else{
                        //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                        mainListParent->set_newNameAccepted(false);
                    }
                }else{
                    //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                    mainListParent->set_newNameAccepted(false);
                }
            }else{
                //le->setStyleSheet("");
                mainListParent->set_newNameAccepted(true);
            }
        }else{  // Search Engine Fail
            //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
            mainListParent->set_newNameAccepted(false);
        }
    }else{
        filter->initialize(true, UINT_MAX, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        DataBaseSearchEngineFilter* deepFilter = new DataBaseSearchEngineFilter();
        deepFilter->initialize(true, UINT_MAX, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        filter->addLinkedDeepFilter(deepFilter);
        DataBaseSearchEngine dbSearchEngine;
        dbSearchEngine.addFilter(filter);
        if(dbSearchEngine.search(parent->get_refObj())){   // Success
            if(dbSearchEngine.get_result().numbOfObjects > 0){  // Category with the same name exist
                if(!mainListParent->get_newObjectFlag()){
                    QString oldName;
                    GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
                    if(!refObj->getParam(&oldName, gpr)){
                        //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                        mainListParent->set_newNameAccepted(false);
                    }
                    if(oldName == tempText){
                        //le->setStyleSheet("");
                        mainListParent->set_newNameAccepted(true);
                    }else{
                        //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                        mainListParent->set_newNameAccepted(false);
                    }
                }else{
                    //le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                    mainListParent->set_newNameAccepted(false);
                }
            }else{
                //le->setStyleSheet("");
                mainListParent->set_newNameAccepted(true);
            }
        }else{  // Search Engine Fail
           // le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
            mainListParent->set_newNameAccepted(false);
        }
    }
    return true;
}

void DataBaseViewerElement::resizeEvent(QResizeEvent *event){
    /*// Title Label
    titleLE.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_TEXT_LABEL_GEOMETRY);

    // CheckBox
    checkBox.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_CHECK_BOX_GEOMETRY);*/

}

void DataBaseViewerElement::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setBrush(QColor(190, 190, 190, 200));
    p.setPen(pen);
    if(mainListParent->get_currentElement() == this){
        p.setBrush(QColor(240, 240, 240, 200));
    }else{
        p.setBrush(QColor(220, 220, 220, 200));
    }
    p.drawRoundedRect(QRect(QPoint(0,0), size() - QSize(1, 1)), 5, 5);
    DataBaseViewerElement::createLayout();
}

bool DataBaseViewerElement::eventFilter(QObject *obj, QEvent *ev){
    switch (ev->type()) {
        case QEvent::MouseButtonDblClick:
        {
            if(obj == this || obj == &titleLE){
                mainListParent->get_parent()->get_parent()->get_parent()->openDBObject(this);
                return true;
            }
        }
        break;
        case QEvent::KeyPress:
        {
            if(obj == &titleLE && this == mainListParent->get_elementAtEditMode()){
                if(editModeCheckName(static_cast<QKeyEvent*>(ev))){
                    return true;
                }
            }
        }
        break;
        case QEvent::MouseButtonPress:
        {
        if(!mainListParent->get_elementAtEditMode()){
            if(obj == this || obj == &titleLE){
                if(static_cast<QMouseEvent*>(ev)->button() == Qt::RightButton){
                    QPoint point = static_cast<QMouseEvent*>(ev)->globalPos();
                    execContextMenu(point);
                    return true;
                }else{
                    mainListParent->selectElement(this);
                    return true;
                }
            }
        }
        }
        break;
    default:
        break;
    }
    return QWidget::eventFilter(obj, ev);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
