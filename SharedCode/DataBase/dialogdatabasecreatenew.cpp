#include"dialogdatabasecreatenew.hpp"
#include<QKeyEvent>
#include"database.hpp"
#include"databasegeneralinformation.hpp"
#include"setparamrules.hpp"
#include"../GeneralPurposeMacros/databasemenegmentmacros.hpp"
#include"../GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"databasemenager.hpp"

/* Uncomment If need to make custom dialog with this constructor
  DialogDataBaseCreateNew::DialogDataBaseCreateNew(DialogType setType, QWidget *setParent){
    parent = setParent;
    type = setType;
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogDataBaseCreateNew{border: 2px ridge grey;}");
    createDialog();
    show();
}*/

DialogDataBaseCreateNew::DialogDataBaseCreateNew(DataBase* refDb, QWidget* setParent) : Dialog(setParent),  refDB(refDb),
    title(DIALOG_DATABASE_CREATE_NEW_TITLE_LABEL_TEXT,this),
    newDBNameLabel(DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LABEL_TEXT, this),
    newDBNameLE(this),
    acceptButton(DIALOG_DATABASE_CREATE_NEW_ACCEPT_BUTTON_TEXT, this),
    cancelButton(DIALOG_DATABASE_CREATE_NEW_CANCEL_BUTTON_TEXT, this)
{
    if(!refDB){
        constructionError =  true;
    }else{
        create();
    }
}

DialogDataBaseCreateNew::~DialogDataBaseCreateNew(){

}

void DialogDataBaseCreateNew::create(){
    QFont f("Comic Sans MS", 14, QFont::Medium);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogDataBaseCreateNew{border: 2px ridge grey;}");
    setWindowModality(Qt::ApplicationModal);
    resize(DIALOG_DATABASE_CREATE_NEW_WIDTH, DIALOG_DATABASE_CREATE_NEW_HEIGHT);
    title.setGeometry(DIALOG_DATABASE_CREATE_NEW_TITLE_LABEL_X, DIALOG_DATABASE_CREATE_NEW_TITLE_LABEL_Y,DIALOG_DATABASE_CREATE_NEW_TITLE_LABEL_WIDTH,DIALOG_DATABASE_CREATE_NEW_TITLE_LABEL_HEIGHT);
    title.setStyleSheet(DIALOG_DATABASE_CREATE_NEW_TITLE_LABEL_STYLESHEET);
    title.setAlignment(Qt::AlignCenter);
    newDBNameLabel.setGeometry(DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LABEL_X,DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LABEL_Y,DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LABEL_WIDTH,DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LABEL_HEIGHT);
    newDBNameLE.setGeometry(DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LE_X,DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LE_Y,DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LE_WIDTH,DIALOG_DATABASE_CREATE_NEW_NEW_DB_NAME_LE_HEIGHT);
    acceptButton.setGeometry(DIALOG_DATABASE_CREATE_NEW_ACCEPT_BUTTON_X,DIALOG_DATABASE_CREATE_NEW_ACCEPT_BUTTON_Y,DIALOG_DATABASE_CREATE_NEW_ACCEPT_BUTTON_WIDTH,DIALOG_DATABASE_CREATE_NEW_ACCEPT_BUTTON_HEIGHT);
    cancelButton.setGeometry(DIALOG_DATABASE_CREATE_NEW_CANCEL_BUTTON_X,DIALOG_DATABASE_CREATE_NEW_CANCEL_BUTTON_Y, DIALOG_DATABASE_CREATE_NEW_CANCEL_BUTTON_WIDTH,DIALOG_DATABASE_CREATE_NEW_CANCEL_BUTTON_HEIGHT);
    acceptButton.setAlignment(Qt::AlignCenter);
    cancelButton.setAlignment(Qt::AlignCenter);
    newDBNameLabel.setStyleSheet(DIALOG_STYLESHEET_DATA_LABEL);
    newDBNameLE.setStyleSheet(DIALOG_STYLESHEET_LINE_EDIT_WRONG_DATA);
    acceptButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_LOWLIGHT);
    cancelButton.setStyleSheet(DIALOG_STYLESHEET_BUTTON_LOWLIGHT);
    newDBNameLE.installEventFilter(this);
    acceptButton.installEventFilter(this);
    cancelButton.installEventFilter(this);
    show();
}

bool DialogDataBaseCreateNew::eventFilter(QObject* obj, QEvent* ev){
    switch(ev->type()){
    case QEvent::KeyPress:
    {
        if(obj == &newDBNameLE){
            if(standardLEKeyPressed(static_cast<QKeyEvent*>(ev), &newDBNameLE))
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

bool DialogDataBaseCreateNew::standardLEKeyPressed(QKeyEvent *ev, QLineEdit *le){
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
    } else{
        le->setStyleSheet("");
        nameAccepted = true;
    }
    return true;
}

void DialogDataBaseCreateNew::acceptButtonPressed(){
    if(nameAccepted){
        //refDB->set_dataBaseGeneralInformation(new DataBaseGeneralInformation());
        QString dbName = newDBNameLE.text();
        SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), UINT_MAX, SET_PARAM_ACTION_ADD};
        //if(!refDB->get_dataBaseGeneralInformation()->setParam((&dbName), spr)){  // Error
             // Do Nothing _PH_
        //    return;
        //}
        // All is Set
        done(ACCEPT_RESULT);
    }
}

void DialogDataBaseCreateNew::cancelButtonPressed(){

    SET_PTR_DO(refDB, nullptr);
    done(CANCEL_RESULT);
}
