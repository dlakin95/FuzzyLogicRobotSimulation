#include"dialogyesnoquestion.hpp"
#include<QTimer>
#include<QEvent>
#include<QLabel>
/* Uncomment If need to make custom dialog with this constructor
  DialogYesNoQuestion::DialogYesNoQuestion(DialogType setType, QWidget *setParent){
    parent = setParent;
    type = setType;
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogYesNoQuestion{border: 2px ridge grey;}");
    createDialog();
    show();
}*/

DialogYesNoQuestion::DialogYesNoQuestion(QString title, QString content, QWidget* setParent) : Dialog (setParent),
    titleLabel(new QLabel(title, this)),
    questionLabel(new QLabel(content, this)),
    yesButton(new QLabel("Tak", this)),
    noButton(new QLabel("Nie", this))
{
    create();
}

DialogYesNoQuestion::~DialogYesNoQuestion(){
    delete titleLabel;
    delete questionLabel;
    delete yesButton;
    delete noButton;
}

void DialogYesNoQuestion::create(){
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogYesNoQuestion{border: 2px ridge grey;}");
    QFontMetrics titleMetrics(QFont("Comic Sans MS",12, QFont::Medium));
    QFontMetrics contentMetrics(font());
    titleLabel->setWordWrap(true);
    titleLabel->setFont(QFont("Comic Sans MS",12, QFont::Medium));
    questionLabel->setWordWrap(true);
    int referenceWidth = MIN_REFERENCE_WIDTH;
    int numbOfButtons = 2;
    int buttonWidth = YES_NO_BUTTON_WIDTH;
    referenceWidth += HORIZONTAL_OFFSET + referenceWidth;
    setFixedWidth(referenceWidth + 2 * HORIZONTAL_OFFSET);
    int horizontalOffset = (width() - numbOfButtons * buttonWidth ) / (numbOfButtons + 1);
    if(!titleLabel->text().isEmpty())
    {
        titleLabel->setGeometry(HORIZONTAL_OFFSET, VERTICAL_BORDER_OFFSET, referenceWidth, titleMetrics.boundingRect(0, 0, referenceWidth, MAX_TEST_RECT_HEIGHT, Qt::AlignHCenter | Qt::TextWordWrap, titleLabel->text()).height() + 5);
        titleLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setGeometry(HORIZONTAL_OFFSET, titleLabel->y() + titleLabel->height() + VERTICAL_OFFSET, referenceWidth, contentMetrics.boundingRect(0, 0, referenceWidth, MAX_TEST_RECT_HEIGHT, Qt::AlignHCenter | Qt::TextWordWrap, questionLabel->text()).height() + 5);
        yesButton->setAlignment(Qt::AlignCenter);
        yesButton->setGeometry(horizontalOffset , questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
        yesButton->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
        noButton->setAlignment(Qt::AlignCenter);
        noButton->setGeometry(width() - horizontalOffset - buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
        noButton->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
        setFixedHeight(yesButton->y() + BUTTONS_HEIGHT + VERTICAL_BORDER_OFFSET);
    }else{
        delete titleLabel;
        titleLabel = nullptr;
        questionLabel->setAlignment(Qt::AlignCenter);
        questionLabel->setGeometry(HORIZONTAL_OFFSET, VERTICAL_BORDER_OFFSET, referenceWidth, contentMetrics.boundingRect(0, 0, referenceWidth, MAX_TEST_RECT_HEIGHT, Qt::AlignHCenter | Qt::TextWordWrap, questionLabel->text()).height() + 5);
        yesButton->setAlignment(Qt::AlignCenter);
        yesButton->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
        yesButton->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
        noButton->setAlignment(Qt::AlignCenter);
        noButton->setGeometry(width() - horizontalOffset - buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
        noButton->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
        setFixedHeight(yesButton->y() + BUTTONS_HEIGHT + VERTICAL_BORDER_OFFSET);
    }
    yesButton->installEventFilter(this);
    noButton->installEventFilter(this);
    show();
}

void DialogYesNoQuestion::yesButtonReleased(){
    done(YES_RESULT);
}

void DialogYesNoQuestion::noButtonReleased(){
    done(NO_RESULT);
}

bool DialogYesNoQuestion::eventFilter(QObject* obj, QEvent* ev){
    switch(ev->type()){
    case QEvent::MouseButtonRelease:
    {
        if(yesButton == obj){
            yesButtonReleased();
            return true;
        }
        if(noButton == obj){
            noButtonReleased();
            return true;
        }
    }
        break;
    default:
        break;
    }
    return Dialog::eventFilter(obj, ev);
}

