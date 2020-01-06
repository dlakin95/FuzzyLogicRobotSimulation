#ifndef DIALOGDATABASEVIEWERADDCATEGORY_HPP
#define DIALOGDATABASEVIEWERADDCATEGORY_HPP

// Macros
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
// --------------------------------------

#include"../SharedCode/Dialog/dialog.hpp"
#include<QFrame>
#include<QLineEdit>
#include<QLabel>

class DataBase;
class DataBaseCategory;
class Dialog;

class DialogDataBaseViewerAddCategory : public Dialog{
    Q_OBJECT
public:
    DialogDataBaseViewerAddCategory(DataBase*, DataBaseCategory**, QWidget*);
    virtual ~DialogDataBaseViewerAddCategory() override;

private:
    DataBaseCategory** refCategory = nullptr;
    DataBase* refDB = nullptr;
    QLabel title;
    QLabel newCategoryLabel;
    QLineEdit newCategoryLE;
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

#endif // DIALOGDATABASEVIEWERADDCATEGORY_HPP
