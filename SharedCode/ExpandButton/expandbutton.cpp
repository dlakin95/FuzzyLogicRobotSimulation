#include"expandbutton.hpp"
#include<QPainter>

ExpandButton::ExpandButton(QWidget* parent) : QLabel (parent){
    setScaledContents(true);
    setPixmap(QPixmap(EXPAND_BUTTON_ICON));
}

ExpandButton::~ExpandButton(){

}

GET_DEFINITION(ExpandButton, bool, expanded);

void ExpandButton::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPixmap pixmap = QPixmap(EXPAND_BUTTON_ICON);
    if(expanded){
        pixmap = pixmap.transformed(QTransform().rotate(180));
    }
    p.drawPixmap(pixmap.rect(), pixmap, rect());
    QLabel::paintEvent(ev);
}
