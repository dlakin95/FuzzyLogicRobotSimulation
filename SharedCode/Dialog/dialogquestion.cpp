#include"dialogquestion.hpp"
#include<QTimer>
#include<QKeyEvent>
#include<QLabel>

/* Uncomment If need to make custom dialog with this constructor
  DialogQuestion::DialogQuestion(DialogType setType, QWidget *setParent){
    parent = setParent;
    type = setType;
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogQuestion{border: 2px ridge grey;}");
    createDialog();
    show();
}*/

DialogQuestion::DialogQuestion(QString title, QString content, QWidget *setParent, QString setFirstOption, QString setSecondOption, QString setThirdOption) : Dialog (setParent),
    titleLabel(new QLabel(title, this)),
    questionLabel(new QLabel(content, this)),
    firstOptionLabel(new QLabel(setFirstOption, this)),
    secondOptionLabel(new QLabel(setSecondOption, this)),
    thirdOptionLabel(new QLabel(setThirdOption, this))
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setStyleSheet("DialogQuestion{border: 2px ridge grey;}");
    create();
}

DialogQuestion::~DialogQuestion(){
    delete titleLabel;
    delete questionLabel;
    delete firstOptionLabel;
    delete secondOptionLabel;
    delete thirdOptionLabel;
}

void DialogQuestion::create(){
    QFontMetrics titleMetrics(QFont("Comic Sans MS",12, QFont::Medium));
    QFontMetrics contentMetrics(font());
    titleLabel->setWordWrap(true);
    titleLabel->setFont(QFont("Comic Sans MS",12, QFont::Medium));
    questionLabel->setWordWrap(true);
        int referenceWidth = 0;
        int numbOfButtons = 0;
        int buttonWidth = 0;
        if(!firstOptionLabel->text().isEmpty()){
            if(!secondOptionLabel->text().isEmpty()){
                if(!thirdOptionLabel->text().isEmpty()){
                    numbOfButtons = 3;
                    referenceWidth = contentMetrics.horizontalAdvance(thirdOptionLabel->text());
                }else{
                    numbOfButtons = 2;
                }
                int tempHA = contentMetrics.horizontalAdvance(secondOptionLabel->text());
                if(referenceWidth < tempHA)
                    referenceWidth = tempHA;
            }else{
                numbOfButtons = 1;
            }
            int tempHA = contentMetrics.horizontalAdvance(firstOptionLabel->text());
            if(referenceWidth < tempHA)
               referenceWidth = tempHA;
        }
        referenceWidth += 15;
        switch(numbOfButtons){
        case 2:
            referenceWidth += HORIZONTAL_OFFSET + referenceWidth;
            break;
        case 3:
            referenceWidth += 2* HORIZONTAL_OFFSET + 2* referenceWidth;
            break;
        default:
            break;
        }
        if(referenceWidth < MIN_REFERENCE_WIDTH){
            if((buttonWidth = (referenceWidth - (numbOfButtons - 1) * HORIZONTAL_OFFSET) / numbOfButtons) < 40)
                buttonWidth = 40;
            referenceWidth = MIN_REFERENCE_WIDTH;
        }
        else{
            buttonWidth = (referenceWidth - (numbOfButtons - 1) * HORIZONTAL_OFFSET) / numbOfButtons;
        }
        setFixedWidth(referenceWidth + 2 * HORIZONTAL_OFFSET);
        int horizontalOffset = (width() - numbOfButtons * buttonWidth ) / (numbOfButtons + 1);
        if(!titleLabel->text().isEmpty())
        {
            titleLabel->setGeometry(HORIZONTAL_OFFSET, VERTICAL_BORDER_OFFSET, referenceWidth, titleMetrics.boundingRect(0, 0, referenceWidth, MAX_TEST_RECT_HEIGHT, Qt::AlignHCenter | Qt::TextWordWrap, titleLabel->text()).height() + 5);
            titleLabel->setAlignment(Qt::AlignCenter);
            questionLabel->setAlignment(Qt::AlignCenter);
            questionLabel->setGeometry(HORIZONTAL_OFFSET, titleLabel->y() + titleLabel->height() + VERTICAL_OFFSET, referenceWidth, contentMetrics.boundingRect(0, 0, referenceWidth, MAX_TEST_RECT_HEIGHT, Qt::AlignHCenter | Qt::TextWordWrap, questionLabel->text()).height() + 5);
            firstOptionLabel->setAlignment(Qt::AlignCenter);
            firstOptionLabel->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
            secondOptionLabel->setAlignment(Qt::AlignCenter);
            secondOptionLabel->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
            thirdOptionLabel->setAlignment(Qt::AlignCenter);
            thirdOptionLabel->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
            switch(numbOfButtons){
            case 1:
                delete secondOptionLabel;
                secondOptionLabel = nullptr;
                delete thirdOptionLabel;
                thirdOptionLabel = nullptr;
                firstOptionLabel->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                break;
            case 2:
                delete thirdOptionLabel;
                thirdOptionLabel = nullptr;
                firstOptionLabel->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                secondOptionLabel->setGeometry(width() - horizontalOffset -  buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                break;
            case 3:
                firstOptionLabel->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                secondOptionLabel->setGeometry(2 * horizontalOffset + buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                thirdOptionLabel->setGeometry(width() - horizontalOffset - buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                break;
            }
            setFixedHeight(firstOptionLabel->y() + BUTTONS_HEIGHT + VERTICAL_BORDER_OFFSET);
        }else{
            delete titleLabel;
            titleLabel = nullptr;
            questionLabel->setAlignment(Qt::AlignCenter);
            questionLabel->setGeometry(HORIZONTAL_OFFSET, VERTICAL_BORDER_OFFSET, referenceWidth, contentMetrics.boundingRect(0, 0, referenceWidth, MAX_TEST_RECT_HEIGHT, Qt::AlignHCenter | Qt::TextWordWrap, questionLabel->text()).height() + 5);
            firstOptionLabel->setAlignment(Qt::AlignCenter);
            firstOptionLabel->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
            secondOptionLabel->setAlignment(Qt::AlignCenter);
            secondOptionLabel->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
            thirdOptionLabel->setAlignment(Qt::AlignCenter);
            thirdOptionLabel->setStyleSheet("border: 1px solid grey; background-color: rgba(219, 217, 217, 0.9); border-radius: 5px;");
            switch(numbOfButtons){
            case 1:
                delete secondOptionLabel;
                secondOptionLabel = nullptr;
                delete thirdOptionLabel;
                thirdOptionLabel = nullptr;
                firstOptionLabel->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                break;
            case 2:
                delete thirdOptionLabel;
                thirdOptionLabel = nullptr;
                firstOptionLabel->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                secondOptionLabel->setGeometry(width() - horizontalOffset -  buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                break;
            case 3:
                firstOptionLabel->setGeometry(horizontalOffset, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                secondOptionLabel->setGeometry(2 * horizontalOffset + buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                thirdOptionLabel->setGeometry(width() - horizontalOffset -  buttonWidth, questionLabel->y() + questionLabel->height() + VERTICAL_BORDER_OFFSET, buttonWidth, BUTTONS_HEIGHT);
                break;
            }
            setFixedHeight(firstOptionLabel->y() + BUTTONS_HEIGHT + VERTICAL_BORDER_OFFSET);
        }
        firstOptionLabel->installEventFilter(this);
        if(secondOptionLabel){
            secondOptionLabel->installEventFilter(this);
        }
        if(thirdOptionLabel){
            thirdOptionLabel->installEventFilter(this);
        }
}

void DialogQuestion::firstOptionLabelReleased(){
    done(FIRST_OPTION_RESULT);
}

void DialogQuestion::secondOptionLabelReleased(){
    done(SECOND_OPTION_RESULT);
}

void DialogQuestion::thirdOptionLabelReleased(){
    done(THIRD_OPTION_RESULT);
}

bool DialogQuestion::eventFilter(QObject* obj, QEvent* ev){
    switch(ev->type()){
    case QEvent::MouseButtonRelease:
    {
        if(firstOptionLabel == obj){
            firstOptionLabelReleased();
            return true;
        }
        if(secondOptionLabel == obj){
            secondOptionLabelReleased();
            return true;
        }
        if(thirdOptionLabel == obj){
            thirdOptionLabelReleased();
            return true;
        }
    }
        break;    
    default:
        break;
    }
    return Dialog::eventFilter(obj, ev);
}

