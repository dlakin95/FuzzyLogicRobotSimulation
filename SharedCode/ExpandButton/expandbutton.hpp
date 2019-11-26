#ifndef EXPANDBUTTON_HPP
#define EXPANDBUTTON_HPP

#define EXPAND_BUTTON_ICON ("Icons/downExtendArrowIcon.png")

#include<QLabel>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"

class ExpandButton : public QLabel{
public:
    ExpandButton(QWidget* parent);
    ~ExpandButton();

protected:
    bool expanded = false;
    bool drawing = false;

public:
    GET_DECLARATION(bool, expanded)

    inline void expand(){expanded = true;}
    inline void unexpand(){expanded = false;}
    inline void toggle(){expanded = !expanded;}

    void paintEvent(QPaintEvent* ev);
};

#endif // EXPANDBUTTON_HPP
