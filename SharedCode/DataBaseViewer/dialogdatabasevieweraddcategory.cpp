#include"dialogdatabasevieweraddcategory.hpp"
#include<QKeyEvent>
#include<QTimer>
#include"../DataBase/databasesearchenginefilter.hpp"
#include"../DataBase/databasesearchengine.hpp"
#include"../GeneralPurposeMacros/databasemenegmentmacros.hpp"
#include"../DataBase/databasecategory.hpp"
#include"../DataBase/database.hpp"
#include"../DataBase/setparamrules.hpp"

/* Uncomment If need to make custom dialog with this constructor
  DialogDataBaseViewerAddCategory::DialogDataBaseViewerAddCategory(DialogType setType, QWidget *setParent){
    parent = setParent;
    type = setType;
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogDataBaseViewerAddCategory{border: 2px ridge grey;}");
    createDialog();
    show();
}*/

DialogDataBaseViewerAddCategory::DialogDataBaseViewerAddCategory(DataBase* refDb, DataBaseCategory** refCategory, QWidget* setParent) : Dialog(setParent),  refCategory(refCategory),refDB(refDb),
    title(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_TITLE_LABEL_TEXT,this),
    newCategoryLabel(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LABEL_TEXT, this),
    newCategoryLE(this),
    acceptButton(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_ACCEPT_BUTTON_TEXT, this),
    cancelButton(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_CANCEL_BUTTON_TEXT, this)
{
    if(!refDB || !refCategory){
        constructionError =  true;
    }else{
    create();
    }
}

DialogDataBaseViewerAddCategory::~DialogDataBaseViewerAddCategory(){

}

void DialogDataBaseViewerAddCategory::create(){
    QFont f("Comic Sans MS", 14, QFont::Medium);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogDataBaseViewerAddCategory{border: 2px ridge grey;}");
    setWindowModality(Qt::ApplicationModal);
    resize(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_WIDTH, DIALOG_DATABASE_VIEWER_ADD_CATEGORY_HEIGHT);
    title.setGeometry(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_TITLE_LABEL_X, DIALOG_DATABASE_VIEWER_ADD_CATEGORY_TITLE_LABEL_Y,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_TITLE_LABEL_WIDTH,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_TITLE_LABEL_HEIGHT);
    title.setStyleSheet(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_TITLE_LABEL_STYLESHEET);
    title.setAlignment(Qt::AlignCenter);
    newCategoryLabel.setGeometry(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LABEL_X,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LABEL_Y,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LABEL_WIDTH,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LABEL_HEIGHT);
    newCategoryLE.setGeometry(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LE_X,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LE_Y,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LE_WIDTH,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_NEW_CATEGORY_LE_HEIGHT);
    acceptButton.setGeometry(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_ACCEPT_BUTTON_X,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_ACCEPT_BUTTON_Y,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_ACCEPT_BUTTON_WIDTH,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_ACCEPT_BUTTON_HEIGHT);
    cancelButton.setGeometry(DIALOG_DATABASE_VIEWER_ADD_CATEGORY_CANCEL_BUTTON_X,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_CANCEL_BUTTON_Y, DIALOG_DATABASE_VIEWER_ADD_CATEGORY_CANCEL_BUTTON_WIDTH,DIALOG_DATABASE_VIEWER_ADD_CATEGORY_CANCEL_BUTTON_HEIGHT);
    acceptButton.setAlignment(Qt::AlignCenter);
    cancelButton.setAlignment(Qt::AlignCenter);
    newCategoryLabel.setStyleSheet(DIALOG_STYLESHEET_DATA_LABEL);
    newCategoryLE.setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
    acceptButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_LOWLIGHT);
    cancelButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_LOWLIGHT);
    newCategoryLE.installEventFilter(this);
    acceptButton.installEventFilter(this);
    cancelButton.installEventFilter(this);
    show();
}

bool DialogDataBaseViewerAddCategory::eventFilter(QObject* obj, QEvent* ev){
    switch(ev->type()){
    case QEvent::KeyPress:
    {
        if(obj == &newCategoryLE){
            if(standardLEKeyPressed(static_cast<QKeyEvent*>(ev), &newCategoryLE))
                return true;
        }
    }
        break;
    case QEvent::MouseButtonRelease:
    {
        if(obj == &acceptButton){
            acceptButtonPressed();
            return true;
        }
        if(obj == &cancelButton){
            cancelButtonPressed();
            return true;
        }
    }
        break;
    case QEvent::Enter:
    {
        if(obj == &acceptButton){
            acceptButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_HIGHLIGHT);
            break;
        }
        if(obj == &cancelButton){
            cancelButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_HIGHLIGHT);
            break;
        }
    }
        break;
    case QEvent::Leave:
    {
        if(obj == &acceptButton){
            acceptButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_LOWLIGHT);
            break;
        }
        if(obj == &cancelButton){
            cancelButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_LOWLIGHT);
            break;
        }
    }
        break;
    default:
        break;
    }
    return Dialog::eventFilter(obj, ev);
}

bool DialogDataBaseViewerAddCategory::standardLEKeyPressed(QKeyEvent *ev, QLineEdit *le){
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
        le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
        nameAccepted = false;
        return true;
    }    else{
        le->setStyleSheet("");        
    }
    // Check if category exist
    QString tempText = le->text();
    DataBaseSearchEngineFilter* filter = new DataBaseSearchEngineFilter;
    if(!*refCategory){
        filter->initialize(true, DATABASE_OBJECT_CATEGORY, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        DataBaseSearchEngine dbSearchEngine;
        dbSearchEngine.addFilter(filter);
        if(dbSearchEngine.search(refDB)){   // Success
            if(dbSearchEngine.get_result().numbOfObjects > 0){  // Category with the same name exist
                le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                nameAccepted = false;
            }else{
                le->setStyleSheet("");
                nameAccepted = true;
            }
        }else{  // Search Engine Fail
            le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
            nameAccepted = false;
        }
    }else{
        filter->initialize(true, DATABASE_OBJECT_CATEGORY, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempText);
        DataBaseSearchEngine dbSearchEngine;
        dbSearchEngine.addFilter(filter);
        if(dbSearchEngine.search(*refCategory)){   // Success
            if(dbSearchEngine.get_result().numbOfObjects > 0){  // Category with the same name exist
                le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
                nameAccepted = false;
            }else{
                le->setStyleSheet("");
                nameAccepted = true;
            }
        }else{  // Search Engine Fail
            le->setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
            nameAccepted = false;
        }
    }
    return true;
}

void DialogDataBaseViewerAddCategory::acceptButtonPressed(){
    if(nameAccepted){
        QString acceptedText = newCategoryLE.text();
        SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), UINT_MAX, SET_PARAM_ACTION_ADD};
        (*refCategory) = new DataBaseCategory();
        if(!(*refCategory)->setParam(&acceptedText, spr)){  // Failed
            SET_PTR_DO(refCategory, nullptr);
        }else{
            done(ACCEPT_RESULT);
        }
    }
}

void DialogDataBaseViewerAddCategory::cancelButtonPressed(){
    done(CANCEL_RESULT);
}
