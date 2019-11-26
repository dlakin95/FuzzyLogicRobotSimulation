

// _INCLUDES_ DataBaseObjectsReadFileContainer.cpp -------------------------------------------------------------------------------------------------------------------
#include "databaseobjectsreadfilecontainer.hpp"
#include"databaseobject.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseObjectsReadFileContainer -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseObjectsReadFileContainer.cpp
DataBaseObjectsReadFileContainer::DataBaseObjectsReadFileContainer(){

}

// _DESTRUCTORS_ DataBaseObjectsReadFileContainer.cpp
DataBaseObjectsReadFileContainer::~DataBaseObjectsReadFileContainer(){

}

// _PRIVATE_METHODS_ DataBaseObjectsReadFileContainer.cpp


// _PUBLIC_METHODS_ DataBaseObjectsReadFileContainer.cpp
DataBaseObjectsReadFileStat* DataBaseObjectsReadFileContainer::getLastObject(){
    if(numbOfObjects > 0){
        return (*(readFileStats + numbOfObjects - 1));
    }else {
        return nullptr;
    }
}

DataBaseObjectsReadFileStat* DataBaseObjectsReadFileContainer::getSecondLastObject(){
    if(numbOfObjects > 1){
        return (*(readFileStats + numbOfObjects - 2));
    }else {
        return nullptr;
    }
}

bool DataBaseObjectsReadFileContainer::checkLastObjectReadedProperly(){
    if(readFileStats && numbOfObjects > 0){
        DataBaseObject* testObj =  (*(readFileStats + numbOfObjects - 1))->dbObj;
        if(testObj){
            uint numbOfParams = testObj->getNumbOfParameters();
            for(uint i = 0; i < numbOfParams; i++){
                if(!testObj->isParameterInitialized(i) && !testObj->isParamOptional(i))
                    return false;
            }
            return true;
        }
    }
    return false;
}

bool DataBaseObjectsReadFileContainer::push(DataBaseObject *newObj){
    if(newObj){
        if(numbOfObjects + 1 > numbOfObjects){
            DataBaseObjectsReadFileStat** newElements = new DataBaseObjectsReadFileStat*[numbOfObjects + 1];
            DataBaseObjectsReadFileStat** newTempElement = newElements;
            for(uint i = 0; i < numbOfObjects; i++, readFileStats++, newTempElement++)
                SET_PTR_NDO((*newTempElement), (*readFileStats));
            SET_PTR_NDO((*newTempElement), new DataBaseObjectsReadFileStat);
            SET_PTR_NDO((*newTempElement)->dbObj, newObj);
            readFileStats -= numbOfObjects;
            SET_PTR_DOA(readFileStats, newElements);
            numbOfObjects++;
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool DataBaseObjectsReadFileContainer::changeObjectType(DataBaseObject *newObj){
    if(numbOfObjects > 0 && newObj){
        SET_PTR_DO((*(readFileStats + numbOfObjects - 1))->dbObj, newObj);
        return true;
    }
    return false;
}

DataBaseObject* DataBaseObjectsReadFileContainer::pull(){
    DataBaseObject* retObj = nullptr;
    if(numbOfObjects > 0){
        if(numbOfObjects > 1){
            numbOfObjects--;
            DataBaseObjectsReadFileStat** newElements = new DataBaseObjectsReadFileStat*[numbOfObjects];
            DataBaseObjectsReadFileStat** newTempElement = newElements;
            for(uint i = 0; i < numbOfObjects; i++, readFileStats++, newTempElement++)
                SET_PTR_NDO((*newTempElement), (*readFileStats));
            SET_PTR_NDO(retObj, (*readFileStats)->dbObj);
            SET_PTR_DO((*readFileStats), nullptr);
            readFileStats -= numbOfObjects;
            SET_PTR_DOA(readFileStats, newElements);
        }else{
            SET_PTR_NDO(retObj, (*readFileStats)->dbObj);
            SET_PTR_DO((*readFileStats), nullptr);
            SET_PTR_DOA(readFileStats, nullptr);
            numbOfObjects--;
        }
        return retObj;
    }else{
        return retObj;
    }
}



// ----------------------------------------------------------------------------------------------------------------------------------------------
