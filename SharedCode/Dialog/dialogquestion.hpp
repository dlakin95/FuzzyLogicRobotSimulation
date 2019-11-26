#ifndef DIALOGQUESTION_HPP
#define DIALOGQUESTION_HPP
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

// ------------------ DialogQuestion Class ------------------------------------

class DialogQuestion : public Dialog{
    Q_OBJECT
public:
    // Constuctor for types: QUESTION
    DialogQuestion(QString title, QString content, QWidget* setParent, QString setFirstOption, QString setSecondOption = QString(), QString setThirdOption = QString());

    // Destructor
    virtual ~DialogQuestion() override;
private:
    // Elements
    // For types: YES_NO_QUESTION, QUESTION
    QLabel* titleLabel = nullptr;
    QLabel* questionLabel = nullptr;
    QLabel* firstOptionLabel = nullptr;
    QLabel* secondOptionLabel = nullptr;
    QLabel* thirdOptionLabel = nullptr;

    // Control Functions
    void create() override;
public:
    // Event Functions
    void firstOptionLabelReleased();
    void secondOptionLabelReleased();
    void thirdOptionLabelReleased();
public:
    bool eventFilter(QObject* obj, QEvent* ev) override;
};


#endif // DIALOGQUESTION_HPP
