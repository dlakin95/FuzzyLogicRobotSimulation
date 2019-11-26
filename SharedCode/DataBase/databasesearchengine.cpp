// _INCLUDES_ DataBaseSearchEngine.cpp -------------------------------------------------------------------------------------------------------------------
#include"databasesearchengine.hpp"
#include"database.hpp"
#include"databasesearchengineenums.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"databaseobject.hpp"
#include"getparamrules.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseSearchEngine -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseSearchEngine.cpp
DataBaseSearchEngine::DataBaseSearchEngine(){
    initializer.error = DATABASE_SEARCH_ENGINE_INITIALIZER_ERROR_UNINITIALIZED;
}

// _DESTRUCTORS_ DataBaseSearchEngine.cpp
DataBaseSearchEngine::~DataBaseSearchEngine(){
    clearInitializer();
    clearResult();
}

// _PRIVATE_METHODS_ DataBaseSearchEngine.cpp

// _PUBLIC_METHODS_ DataBaseSearchEngine.cpp
GET_DEFINITION(DataBaseSearchEngine, DataBaseSearchEngineResult&, result)
GET_DEFINITION(DataBaseSearchEngine, DataBaseSearchEngineInitializer&, initializer)

void DataBaseSearchEngine::addFilter(DataBaseSearchEngineFilter *filter){
    if(!checkAddedFilter(filter)){
        initializer.error = DATABASE_SEARCH_ENGINE_INITIALIZER_ERROR_UNINITIALIZED;
        return;
    }
    bool error = false;
    ARRAY_ADD_PTR_WITH_TEMP_PTR_BOOL_ERROR(DataBaseSearchEngineFilter, initializer.filters, initializer.numbOfFilters, filter, error);
    if(!error)
        initializer.error = DATABASE_SEARCH_ENGINE_INITIALIZER_NO_ERROR;
}

bool DataBaseSearchEngine::checkAddedFilter(DataBaseSearchEngineFilter *newFilter){
    if(newFilter && !newFilter->get_error()){
        if(newFilter->andFilter)
            if(!(checkAddedFilter(newFilter->andFilter)))
                return false;
        if(newFilter->orFilter)
            if(!checkAddedFilter(newFilter->orFilter))
                return false;
        if(newFilter->deepFilter)
            if(!checkAddedFilter(newFilter->deepFilter))
                return false;
        return true;
    }
    return false;
}

void DataBaseSearchEngine::clearInitializer(){
    SET_PTR_DOA(initializer.filters, nullptr);
    initializer.numbOfFilters = 0;
    initializer.error = DATABASE_SEARCH_ENGINE_INITIALIZER_ERROR_UNINITIALIZED;
}

void DataBaseSearchEngine::clearResult(){
    SET_PTR_DOA(result.objects, nullptr);
    result.numbOfObjects = 0;
    result.error = DATABASE_SEARCH_ENGINE_RESULT_NO_ERROR;
}

void DataBaseSearchEngine::filter(DataBaseObject *obj){
    for(uint i = 0; i < initializer.numbOfFilters; i++){
        (*(initializer.filters + i))->filter(obj);
    }    
}
bool DataBaseSearchEngine::search(DataBaseObject *dbObj, bool clearInit){    
    clearResult();
    DataBaseSearchEngineFilter::curEngine = this;
    if(initializer.error != DATABASE_SEARCH_ENGINE_INITIALIZER_NO_ERROR){
        return false;
    }
    filter(dbObj);
    if(clearInit)  return clearInit;
    return true;
}

bool DataBaseSearchEngine::addSearchResult(DataBaseObject *dbObj){
    ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(DataBaseObject, result.objects, result.numbOfObjects, dbObj);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
