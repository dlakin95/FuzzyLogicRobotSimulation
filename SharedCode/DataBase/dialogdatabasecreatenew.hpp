#ifndef DIALOGDATABASECREATENEW_HPP
#define DIALOGDATABASECREATENEW_HPP

// Macros
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
// --------------------------------------

#include"../SharedCode/Dialog/dialog.hpp"
#include<QFrame>
#include<QLineEdit>
#include<QLabel>

class DataBase;
class Dialog;

class DialogDataBaseCreateNew : public Dialog{
    Q_OBJECT
public:
    DialogDataBaseCreateNew(DataBase*, QWidget*);
    virtual ~DialogDataBaseCreateNew() override;

private:
    DataBase* refDB = nullptr;
    QLabel title;
    QLabel newDBNameLabel;
    QLineEdit newDBNameLE;
    QLabel acceptButton;
    QLabel cancelButton;
    bool nameAccepted = false;

    void create() override;
    bool standardLEKeyPressed(QKeyEvent* ev,QLineEdit* le);
    void acceptButtonPressed();
    void cancelButtonPressed();

public:
    bool eventFilter(QObject* obj, QEvent* ev) override;
};

#endif // DIALOGDATABASECREATENEW_HPP
