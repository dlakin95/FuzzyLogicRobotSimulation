
// _INCLUDES_ ComponentList.cpp -------------------------------------------------------------------------------------------------------------------
#include "componentlist.hpp"
#include"componentlistpanel.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"../appwindowlayoutmacros.hpp"
#include"componentlistelement.hpp"
#include"componentlistelementlist.hpp"
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QDebug>
#include<QSize>
#include<QLineEdit>
#include"App/FLRS_DB/SimulationAreaTemplate/simulationareatemplate.hpp"
//#include"../SharedCode/App/app.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ ComponentList -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ ComponentList.cpp
ComponentList::ComponentList(ComponentListPanel* parent) : QWidget (parent), parent(parent)

{
  initalize();
}

// _DESTRUCTORS_ ComponentList.cpp
ComponentList::~ComponentList(){
    clearMemory();
}

// _PRIVATE_METHODS_ ComponentList.cpp
void ComponentList::initalize(){
    //createObjects();
    createLayout();
    connectEvents();
}

void ComponentList::createObjects(){

}

void ComponentList::createLayout(){

}

void ComponentList::connectEvents(){

}

void ComponentList::clearMemory(){
    clearElements();
}


// _PUBLIC_METHODS_ ComponentList.cpp
GET_DEFINITION(ComponentList, ComponentListPanel*, parent)
GET_DEFINITION(ComponentList, ComponentListElement**, elements)
GET_DEFINITION(ComponentList, uint, numbOfElements)
GET_DEFINITION(ComponentList,ComponentListElement*, currentElement)
GET_DEFINITION(ComponentList, ComponentListElement*, elementAtEditMode)
GET_SET_NDO_DEFINITION(ComponentList, bool, newNameAccepted)
GET_SET_NDO_DEFINITION(ComponentList, bool, newObjectFlag)

bool ComponentList::addElement(ComponentListElement *newElem){
     ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(ComponentListElement, elements, numbOfElements, newElem);
}

bool ComponentList::removeElement(ComponentListElement *remElem){
    ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(ComponentListElement, elements, numbOfElements, remElem);
}

void ComponentList::clearElements(){
    ARRAY_CLEAR_PTR_WITH_TEMP_PTR(elements, numbOfElements);
}

void ComponentList::reload(){
    for(uint i = 0; i < numbOfElements; i++)
        (*(elements + i))->reload();
}

bool ComponentList::load(SimulationAreaTemplate *db){
    uint curHeight = 0;
    if(db){
        //uint tempNumbOfNewDBElements = db->get_numbOfDataBaseObjects();
        //uint tempNumbOfElements = numbOfElements;
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
                //ComponentListElement** newElements = new ComponentListElement*[numbOfElements + tempNumbOfNewDBElements];
                // Przepisz utworzone elementy
                //uint i = 0;
                //for( ; i < numbOfElements; i++, newElements++, elements++){
                 //   (*newElements) = (*elements);
                 //   curHeight += (*elements)->get_curHeight();
                //}
                //elements -= numbOfElements;
                //newElements -= numbOfElements;
                //SET_PTR_DOA(elements, newElements);
                //elements += numbOfElements;
                //numbOfElements += tempNumbOfNewDBElements;
                //for( ; i < numbOfElements; i++, elements++, objects++){
                //    (*elements) = parent->createElement((*objects), nullptr);
                //    curHeight += (*elements)->get_curHeight();
                //}
                //elements -= numbOfElements;
                //}else{  // Gdy nie Git
                 //   resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
                  //  return false;
                //}
            loadDBObject(db);
        }else{
            resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
            return false;
        }
    resize(width(), LO_DATABASE_VIEWER_LIST_HEIGHT(curHeight));
    return true;
}


bool ComponentList::loadDBObject(SimulationAreaTemplate *dbObj){
    uint curHeight = 0;
    if(dbObj){
        if(numbOfElements + 1 > numbOfElements){
            ComponentListElement** newElements = new ComponentListElement*[numbOfElements + 1];
            ComponentListElement** tempNewElements = newElements;
            for(uint i = 0; i < numbOfElements; i++, tempNewElements++, elements++){
                (*tempNewElements) = (*elements);
                curHeight += (*elements)->get_curHeight();
            }
            if(!((*tempNewElements) = parent->createElement(dbObj, nullptr))){
                return false;
            }
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


void ComponentList::reallocateElements(ComponentListElement* &caller){
    uint curHeight = 0;
    ComponentListElement** tempElement = elements;
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



void ComponentList::putElementAtEditMode(ComponentListElement *ele){
    elementAtEditMode = ele;
    if(newObjectFlag)
        newNameAccepted = false;
    else {
        newNameAccepted = true;
    }
    elementAtEditMode->repaint();
    //elementAtEditMode->get_titleLE().installEventFilter(this);
}

void ComponentList::editModeAccept(){
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
        /*if(newObjectFlag){
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
        }*/
        //elementAtEditMode->get_titleLE().removeEventFilter(this);
        newObjectFlag = false;
        elementAtEditMode = nullptr;
        newNameAccepted = false;
    }
}

void ComponentList::editModeCancel(){
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
        if(!elementAtEditMode->get_parent()){    // ComponentList element
             if(!removeElement(elementAtEditMode)){
                 return;
             }
        }else{  // DataBaseViewerElementList element
            if(elementAtEditMode->get_parent() && elementAtEditMode->get_parent()->get_refObj()->getObjectType() == DATABASE_OBJECT_CATEGORY){
                if(!static_cast<ComponentListElementList*>(elementAtEditMode->get_parent())->removeElement(elementAtEditMode)){
                    return;
                }
            }else{  // Internal App Error
                return;
            }
        }
        ComponentListElement* tempPtr = nullptr;
        reallocateElements(tempPtr);
        newObjectFlag = false;
    }
    elementAtEditMode = nullptr;
    newNameAccepted = false;
}

void ComponentList::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    QPen pen(QColor(0,0,0));
    p.setBrush(QColor(230,230,230, 200));
    p.setPen(pen);
    p.drawRoundedRect(QRect(QPoint(0,0), size() - QSize(1,1)), 5, 5);
}

void ComponentList::resizeEvent(QResizeEvent *ev){
    if(!reallocationFlag){
        ComponentListElement* tempPtr = nullptr;
        reallocateElements(tempPtr);
    }
    reallocationFlag = false;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
