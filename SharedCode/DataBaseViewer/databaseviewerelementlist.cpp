
// _INCLUDES_ DataBaseViewerElementList.cpp -------------------------------------------------------------------------------------------------------------------
#include "databaseviewerelementlist.hpp"
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
#include"../SharedCode/DataBase/databaseobject.hpp"
#include"databaseviewer.hpp"
#include"../SharedCode/DataBase/getparamrules.hpp"
#include"../GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QDebug>
#include<QSize>
#include<QMenu>
#include<QAction>
#include<QMouseEvent>
#include"../SharedCode/DataBase/databasecategory.hpp"
#include"dialogdatabasevieweraddcategory.hpp"
#include"databaseviewer.hpp"
#include"../SharedCode/App/app.hpp"
#include"../SharedCode/AppWindow/appwindow.hpp"
#include"../SharedCode/DataBase/setparamrules.hpp"
#include<QPainter>
#include<QPen>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseViewerElementList -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseViewerElementList.cpp
DataBaseViewerElementList::DataBaseViewerElementList(DataBaseViewerList* mainListParent, DataBaseObject* refObj, DataBaseViewerElement* refListParent) :
    DataBaseViewerElement (mainListParent, refObj, refListParent), expandButton(this)
{
    initalize();
}

// _DESTRUCTORS_ DataBaseViewerElementList.cpp
DataBaseViewerElementList::~DataBaseViewerElementList(){
    clearMemory();
    clearElements();
}

// _PRIVATE_METHODS_ DataBaseViewerElementList.cpp
void DataBaseViewerElementList::createObjects(){
    if(refObj)
        load();
}

void DataBaseViewerElementList::createLayout(){
    if(numbOfElements > 0){
        expandButton.show();
        expandButton.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_EXPAND_BUTTON_GEOMETRY);
        checkBox.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_CHECK_BOX_GEOMETRY);
        titleLE.setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_LIST_TEXT_LABEL_GEOMETRY);
    }else{
      expandButton.hide();
    }

}

void DataBaseViewerElementList::clearMemory(){
  clearElements();
}

void DataBaseViewerElementList::generateText(){

}

void DataBaseViewerElementList::reload(){
    for(uint i = 0; i < numbOfElements; i++)
        (*(elements + i))->reload();
}

bool DataBaseViewerElementList::addElement(DataBaseViewerElement *newElem){
    ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseViewerElement, elements, numbOfElements, newElem);
}

bool DataBaseViewerElementList::removeElement(DataBaseViewerElement *remElem){
    ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseViewerElement, elements, numbOfElements, remElem);
}


bool DataBaseViewerElementList::addListElement(DataBaseViewerElement *newObj){
    addElement(newObj);
    mainListParent->reallocateElements(parent);
}

void DataBaseViewerElementList::reallocateElements(DataBaseViewerElement* &caller){
    static uint level = 0;
    level++;
    DataBaseViewerElement* tempElement = nullptr;
    if(!caller){
        curHeight = LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT;
        for(uint i = 0; i < numbOfElements; i++){
            tempElement = (*(elements + i));
            if(expandButton.get_expanded()){
                tempElement->reallocateElements(caller);
                reallocationFlag = true;
                tempElement->set_reallocationFlag(true);
                tempElement->setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curHeight, tempElement->get_curHeight()));
                curHeight += tempElement->get_curHeight();
                tempElement->show();
            }else{
                tempElement->hide();
            }
        }
    }else{
        for(uint i = 0; i < numbOfElements; i++){
            tempElement = (*(elements + i));
            if(caller == tempElement)  {curHeight -= tempElement->get_curHeight(); caller = nullptr;}
            tempElement->reallocateElements(caller);
            if(!caller){
                if(expandButton.get_expanded()){
                    tempElement->set_reallocationFlag(true);
                    tempElement->setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curHeight, tempElement->get_curHeight()));
                    curHeight += tempElement->get_curHeight();
                    tempElement->show();
                }else{
                    tempElement->hide();
                }
            }
        }
    }
    level--;
    if(!caller){
        reallocationFlag = true;
        resize(LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight));
    }

}


void DataBaseViewerElementList::load(){
    static uint level = 0;
    curHeight = LO_DATABASE_VIEWER_ELEMENT_LIST_MINIMIZED_HEIGHT;
    if(refObj){
        // Find All objects
        uint numbOfParameters = refObj->getNumbOfParameters();
        DataBaseObject* tempObj = nullptr;
        GetParamRules getParamRules;
        for(uint i = 0; i < numbOfParameters; i++){
            if(refObj->isParamObject(i)){                
                getParamRules.index = 0;
                while(true){
                    getParamRules.param = i;
                    getParamRules.initialized = false;
                    getParamRules.nextAvailable = false;
                    if(!refObj->getParam(&tempObj, getParamRules) && !getParamRules.initialized){
                        // Error
                    }
                    if(tempObj){                        
                            // Add Element
                            if(!addElement(mainListParent->get_parent()->createElement(tempObj, this))){
                                // Error
                            }
                            curHeight += (*(elements + numbOfElements -1))->get_curHeight();
                            (*(elements + numbOfElements - 1))->hide();
                    }else{
                        // Error
                    }
                    if(getParamRules.nextAvailable){
                        getParamRules.index++;
                    }else{
                        break;
                    }
                }
            }
        }

    }
    resize(LO_DATABASE_VIEWER_LIST_ELEMENT_SIZE(curHeight));
}
void DataBaseViewerElementList::addNewDbObj(DataBaseObject* dbObj){
    if(!dbObj)   return;
    if(!expandButton.get_expanded())   expandButton.expand();
    mainListParent->set_newObjectFlag(true);
    addListElement(mainListParent->get_parent()->createElement(dbObj, this));
    mainListParent->putElementAtEditMode(*(elements + numbOfElements - 1));
}
void DataBaseViewerElementList::createContextMenu(QAction *actions){
    // Action 1 (0) Add Test Group
    (actions + 0)->setText("Add Category");
    (actions + 0)->setParent(this);
    (actions + 1)->setText("Add Graphical Object");
    (actions + 1)->setParent(this);
    (actions + 2)->setText("Change Name");
    (actions + 2)->setParent(this);
}

void DataBaseViewerElementList::execContextMenu(QPoint& eventPos){
    QMenu menu;
    QAction action[3];
    createContextMenu(action);
    uint i = 0;
    for( ; i < 3; i++){
        menu.addAction(action + i);
    }
    QAction* at = nullptr;
    at = menu.exec(eventPos);
    for(i = 0; i < 3; i++){
        if(at == action + i)
            break;
    }
    switch(i){
    case 0:
    {

        addNewDbObj(new DataBaseCategory());
        //parent->get_parent()->get_dbMenager().get_dataBase()->addDataBaseObject(newDbCategory);
    }
        break;
    case 1:
    {
        addNewDbObj(new GraphicalObject());
    }
        break;
    case 2:
    {
        mainListParent->putElementAtEditMode(this);
    }
        break;
    default:
        break;
    }
}

// _PUBLIC_METHODS_ DataBaseViewerElementList.cpp
    GET_DEFINITION(DataBaseViewerElementList, DataBaseViewerElement**, elements);
    GET_DEFINITION(DataBaseViewerElementList, uint, numbOfElements);

void DataBaseViewerElementList::paintEvent(QPaintEvent *ev){
    DataBaseViewerElement::paintEvent(ev);
    DataBaseViewerElementList::createLayout();
}

void DataBaseViewerElementList::resizeEvent(QResizeEvent *ev){    
    if(!reallocationFlag){
        DataBaseViewerElement* tempPtr = nullptr;
        mainListParent->reallocateElements(tempPtr);
    }
    reallocationFlag = false;
}

bool DataBaseViewerElementList::eventFilter(QObject *obj, QEvent *ev){
    switch(ev->type()){
    case QEvent::MouseButtonDblClick:
    {
        return true;
    }
        break;
    case QEvent::MouseButtonPress:
    {
        if(obj == this)
        return true;
    }
        break;
    case QEvent::MouseButtonRelease:
    {
        if(!mainListParent->get_elementAtEditMode()){
            if(obj == this){
                if(static_cast<QMouseEvent*>(ev)->button() == Qt::RightButton){
                    QPoint point = static_cast<QMouseEvent*>(ev)->globalPos();
                    execContextMenu(point);
                    return true;
                }
            }
            if(obj == &expandButton){
                expandButton.toggle();
                DataBaseViewerElement* tempPtr = this;
                mainListParent->reallocateElements(tempPtr);
                return true;
            }
        }
    }
        break;
    default:
        break;
    }
    return DataBaseViewerElement::eventFilter(obj, ev);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
