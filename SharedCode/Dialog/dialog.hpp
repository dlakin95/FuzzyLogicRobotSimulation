#ifndef DIALOG_HPP
#define DIALOG_HPP

// ------------------ Macros --------------------------------------------
#define YES_NO_BUTTON_WIDTH (90)
#define BUTTONS_HEIGHT (25)
#define HORIZONTAL_OFFSET (10)
#define VERTICAL_BORDER_OFFSET (10)
#define VERTICAL_OFFSET (5)
#define MIN_REFERENCE_WIDTH (250)
#define MAX_TEST_RECT_HEIGHT (200)

// Include macros
//#include "mainmacros.hpp"
//#include "windowmacros.hpp"

// ----------------------------------------------------------------------

// ------------------ Includes ------------------------------------------
#include<QDialog>
#include"dialogtypeenum.hpp"
#include"dialogresultenum.hpp"
// ----------------------------------------------------------------------

// ------------------ Predefinitions ------------------------------------
// ----------------------------------------------------------------------

// ------------------ Dialog Class ------------------------------------

class Dialog : public QDialog{
    Q_OBJECT
public:
    Dialog(QWidget* setParent);

    // Destructor
    ~Dialog();
protected:
    // Parent
    QWidget* parent = nullptr;

    // Dialog Answer
    DialogResult *exitCode = nullptr;

    // Control Functions
    virtual void create() = 0;

    // Construction Error
    bool constructionError = false;
public:
    // Event Functions

    inline bool isConstructionError(){return constructionError;}
    void setExitCode(DialogResult*);    
    QWidget* getParent();
    virtual bool eventFilter(QObject* obj, QEvent* ev);
};


#endif // DIALOG_HPP
