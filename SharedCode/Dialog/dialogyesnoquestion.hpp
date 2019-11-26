#ifndef DIALOGYESNOQUESTION_HPP
#define DIALOGYESNOQUESTION_HPP


// ------------------ Macros --------------------------------------------
// Include macros
//#include "mainmacros.hpp"
//#include "windowmacros.hpp"

// ----------------------------------------------------------------------

// ------------------ Includes ------------------------------------------
#include"dialog.hpp"

// ----------------------------------------------------------------------

// ------------------ Predefinitions ------------------------------------
class QLabel;
// ----------------------------------------------------------------------

// ------------------ DialogYesNoQuestion Class ------------------------------------

class DialogYesNoQuestion : public Dialog{
    Q_OBJECT
public:
    // Constuctor for types:  YES_NO_QUESTION
    DialogYesNoQuestion(QString title, QString content, QWidget* setParent);

    // Destructor
    virtual ~DialogYesNoQuestion() override;
private:
    // Elements
    // For types: YES_NO_QUESTION, QUESTION
    QLabel* titleLabel = nullptr;
    QLabel* questionLabel = nullptr;
    QLabel* yesButton = nullptr;
    QLabel* noButton = nullptr;

    // Control Functions
    void create() override;
public:
    // Event Functions
    void yesButtonReleased();
    void noButtonReleased();

public:    
    bool eventFilter(QObject* obj, QEvent* ev) override;
};



#endif // DIALOGYESNOQUESTION_HPP
