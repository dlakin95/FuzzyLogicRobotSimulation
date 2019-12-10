
// _INCLUDES_ DataBaseViewerList.cpp -------------------------------------------------------------------------------------------------------------------
#include "databaseviewerlist.hpp"
#include"databaseviewer.hpp"
#include"../DataBase/database.hpp"
#include"../GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"graphicalobjectsbasemenagerleyoutmacros.hpp"
#include"databaseviewerelement.hpp"
#include"databaseviewerelementlist.hpp"
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QDebug>
#include<QSize>
#include<QLineEdit>
#include"../DataBase/databasesearchengine.hpp"
#include"../DataBase/setparamrules.hpp"
#include"../DataBase/getparamrules.hpp"
#include"../DataBase/databaseobject.hpp"
#include"../SharedCode/App/app.hpp"
#include"../DataBase/databasecategory.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseViewerList -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseViewerList.cpp
DataBaseViewerList::DataBaseViewerList(DataBaseViewer* parent) : QWidget (parent), parent(parent)

{
  initalize();
}

// _DESTRUCTORS_ DataBaseViewerList.cpp
DataBaseViewerList::~DataBaseViewerList(){
    clearMemory();
}

// _PRIVATE_METHODS_ DataBaseViewerList.cpp
void DataBaseViewerList::initalize(){
    //createObjects();
    createLayout();
    connectEvents();
}

void DataBaseViewerList::createObjects(){

}

void DataBaseViewerList::createLayout(){

}

void DataBaseViewerList::connectEvents(){

}

void DataBaseViewerList::clearMemory(){
    clearElements();
}


// _PUBLIC_METHODS_ DataBaseViewerList.cpp
GET_DEFINITION(DataBaseViewerList, DataBaseViewer*, parent)
GET_DEFINITION(DataBaseViewerList, DataBaseViewerElement**, elements)
GET_DEFINITION(DataBaseViewerList, uint, numbOfElements)
GET_DEFINITION(DataBaseViewerList,DataBaseViewerElement*, currentElement)
GET_DEFINITION(DataBaseViewerList, DataBaseViewerElement*, elementAtEditMode)
GET_SET_NDO_DEFINITION(DataBaseViewerList, bool, newNameAccepted)
GET_SET_NDO_DEFINITION(DataBaseViewerList, bool, newObjectFlag)

bool DataBaseViewerList::addElement(DataBaseViewerElement *newElem){
     ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseViewerElement, elements, numbOfElements, newElem);
}

bool DataBaseViewerList::removeElement(DataBaseViewerElement *remElem){
    ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseViewerElement, elements, numbOfElements, remElem);
}

void DataBaseViewerList::clearElements(){
    ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

void DataBaseViewerList::reload(){
    for(uint i = 0; i < numbOfElements; i++)
        (*(elements + i))->reload();
}

bool DataBaseViewerList::load(DataBase *db){
    uint curHeight = 0;
    if(db){
        //uint tempNumbOfNewDBElements = db->get_numbOfDataBaseObjects();
        uint tempNumbOfElements = numbOfElements;
            // _PH_ Algorytm sprawdzania przekroczenia
            /* 1. Pobierz ilość obiektów bazy ktora chcesz dodac
             * 2. Pobierz aktulaną ilość obiektów listy
             * 3. Oblicz sumę obu licz podzielonych wczesniej przez 2
             * 4. Sprawdz czy ta suma jest mniejsza od maxa podzielonego przez 2
             * 5. Jak mniejsza to git
             * 6. Jak nie, to sprawdz czy równa
             * 7. Jeśli równa, to sprawdz czy suma obu liczb ale niepodzielonych jest równa max
             * 8. Jeśli jest, to jest git
             * 9. Jesli nie, to nie git
             */
            //uint sumOfHalfs = (tempNumbOfElements*0.5) + (tempNumbOfNewDBElements*0.5);
            //if(sumOfHalfs < static_cast<uint>(UINT_MAX*0.5) || (sumOfHalfs == static_cast<uint>(UINT_MAX*0.5) && ((tempNumbOfElements + tempNumbOfNewDBElements) == UINT_MAX))){
                //DataBaseObject** objects = db->get_dataBaseObjects();
                //DataBaseViewerElement** newElements = new DataBaseViewerElement*[numbOfElements + tempNumbOfNewDBElements];
                // Przepisz utworzone elementy
                uint i = 0;
                //for( ; i < numbOfElements; i++, newElements++, elements++){
                 //   (*newElements) = (*elements);
                 //   curHeight += (*elements)->get_curHeight();
                //}
                elements -= numbOfElements;
                //newElements -= numbOfElements;
                //SET_PTR_DOA(elements, newElements);
                elements += numbOfElements;
                //numbOfElements += tempNumbOfNewDBElements;
                //for( ; i < numbOfElements; i++, elements++, objects++){
                //    (*elements) = parent->createElement((*objects), nullptr);
                    curHeight += (*elements)->get_curHeight();
                //}
                elements -= numbOfElements;
                //}else{  // Gdy nie Git
                 //   resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
                  //  return false;
                //}
        }else{
            resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
            return false;
        }
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
    return true;
}

bool DataBaseViewerList::loadDBObject(DataBaseObject *dbObj){
    uint curHeight = 0;
    if(dbObj){
        if(numbOfElements + 1 > numbOfElements){
            DataBaseViewerElement** newElements = new DataBaseViewerElement*[numbOfElements + 1];
            DataBaseViewerElement** tempNewElements = newElements;
            for(uint i = 0; i < numbOfElements; i++, tempNewElements++, elements++){
                (*tempNewElements) = (*elements);
                curHeight += (*elements)->get_curHeight();
            }
            (*tempNewElements) = parent->createElement(dbObj, nullptr);
            curHeight += (*tempNewElements)->get_curHeight();
            elements -= numbOfElements;
            tempNewElements -= numbOfElements;
            SET_PTR_DOA(elements, tempNewElements);
            numbOfElements++;
            if(newObjectFlag){
                putElementAtEditMode((*(elements + numbOfElements - 1)));
            }
        }else{
            resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
            return false;
        }
    }else{
        resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
        return false;
    }
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
    return true;
}

void DataBaseViewerList::reallocateElements(DataBaseViewerElement* &caller){
    uint curHeight = 0;
    DataBaseViewerElement** tempElement = elements;
    static const uint level = 0;
    for(uint i = 0; i < numbOfElements; i++,tempElement++){
        if(caller == *tempElement) caller = nullptr;
        (*tempElement)->reallocateElements(caller);
        if(!caller){
            (*tempElement)->set_reallocationFlag(true);
            (*tempElement)->setGeometry(LO_DATABASE_VIEWER_LIST_ELEMENT_GEOMETRY(curHeight, (*tempElement)->get_curHeight()));
        }
        curHeight += (*tempElement)->get_curHeight();
        (*tempElement)->show();
    }
    reallocationFlag = true;
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
}



void DataBaseViewerList::putElementAtEditMode(DataBaseViewerElement *ele){
    elementAtEditMode = ele;
    if(newObjectFlag)
        newNameAccepted = false;
    else {
        newNameAccepted = true;
    }
    elementAtEditMode->repaint();        
    //elementAtEditMode->get_titleLE().installEventFilter(this);
}

void DataBaseViewerList::editModeAccept(){
    if(newNameAccepted){
        QString newName = elementAtEditMode->get_titleLE().text();
        if(newName.isEmpty()){
            newNameAccepted = false;
            elementAtEditMode->repaint();
            return;
        }
        DataBaseObject* refObj = elementAtEditMode->get_refObj();
        SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), UINT_MAX, SET_PARAM_ACTION_ADD};
        if(!refObj->setParam(&newName, spr)){
            newNameAccepted = false;
            elementAtEditMode->repaint();
            return;
        }
        if(newObjectFlag){
            if(!elementAtEditMode->get_parent()){    // DataBase element
                 DataBase* db = parent->get_parent()->get_parent()->get_dbMenager().get_dataBase();
                 if(db){
                     if(!db->addDataBaseObject(refObj)){
                         return;
                     }
                 }else{ // Internal App Error
                     return;
                 }
            }else{  // DataBaseCategory element
                DataBaseObject* refCat = elementAtEditMode->get_parent()->get_refObj();
                if(refCat && refCat->getObjectType() == DATABASE_OBJECT_CATEGORY){
                    SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseCategory, DATABASE_CATEGORY_OBJECTS), UINT_MAX, SET_PARAM_ACTION_ADD};
                    if(!refCat->setParam(&refObj, spr)){    // Error
                        return;
                    }
                }else{
                    // Internal App Error
                    return;
                }
            }
        }
        //elementAtEditMode->get_titleLE().removeEventFilter(this);
        newObjectFlag = false;
        elementAtEditMode = nullptr;
        newNameAccepted = false;
    }
}

void DataBaseViewerList::editModeCancel(){
    if(!newObjectFlag){
        QString oldName;
        DataBaseObject* refObj = elementAtEditMode->get_refObj();
        GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
        if(!refObj->getParam(&oldName, gpr)){
            newNameAccepted = false;
            elementAtEditMode->repaint();
            return;
        }
         elementAtEditMode->get_titleLE().setText(oldName);
    }else{
        if(!elementAtEditMode->get_parent()){    // DataBaseViewerList element
             if(!removeElement(elementAtEditMode)){
                 return;
             }
        }else{  // DataBaseViewerElementList element
            if(elementAtEditMode->get_parent() && elementAtEditMode->get_parent()->get_refObj()->getObjectType() == DATABASE_OBJECT_CATEGORY){
                if(!static_cast<DataBaseViewerElementList*>(elementAtEditMode->get_parent())->removeElement(elementAtEditMode)){
                    return;
                }
            }else{  // Internal App Error
                return;
            }
        }
        DataBaseViewerElement* tempPtr = nullptr;
        reallocateElements(tempPtr);
        newObjectFlag = false;
    }
    elementAtEditMode = nullptr;
    newNameAccepted = false;
}

void DataBaseViewerList::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setBrush(QColor(230,230,230, 200));
    p.setPen(pen);
    p.drawRoundedRect(QRect(QPoint(0,0), size() - QSize(1,1)), 5, 5);
}

void DataBaseViewerList::resizeEvent(QResizeEvent *ev){
    if(!reallocationFlag){
        DataBaseViewerElement* tempPtr = nullptr;
        reallocateElements(tempPtr);
    }
    reallocationFlag = false;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
