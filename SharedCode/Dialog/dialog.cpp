#include"dialog.hpp"
#include<QTimer>

/* Uncomment If need to make custom dialog with this constructor
  Dialog::Dialog(DialogType setType, QWidget *setParent){
    parent = setParent;
    type = setType;
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("Dialog{border: 2px ridge grey;}");
    createDialog();
    show();
}*/
Dialog::Dialog(QWidget* setParent) : parent(setParent){

}

Dialog::~Dialog(){
    delete  exitCode;
    exitCode = nullptr;
}

void Dialog::setExitCode(DialogResult* dlgExitCode){
    if(exitCode != nullptr)
        delete exitCode;
    exitCode = dlgExitCode;
}

bool Dialog::eventFilter(QObject* obj, QEvent* ev){    
    return QObject::eventFilter(obj, ev);
}

QWidget* Dialog::getParent(){
    return parent;
}
