
// _INCLUDES_ DataBaseGeneralInformation.cpp -------------------------------------------------------------------------------------------------------------------
#include"databasesearchenginefilter.hpp"
#include"databaseobject.hpp"
#include"getparamrules.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include"DataBase/databasesearchengine.hpp"
// -------------------------------------------------------------------------------------------------------------------------------


// _CLASSIMP_ DataBaseGeneralInformation -----------------------------------------------------------------------------------------------------------------------------------------------

DataBaseSearchEngine* DataBaseSearchEngineFilter::curEngine = nullptr;

// _CONSTRUCTORS_ DataBaseGeneralInformation.cpp
DataBaseSearchEngineFilter::DataBaseSearchEngineFilter(){

}

DataBaseSearchEngineFilter::DataBaseSearchEngineFilter(bool retThis, uint type, uint param, void* value){
    initialize(retThis, type, param, value);
}

// _DESTRUCTORS_ DataBaseGeneralInformation.cpp
DataBaseSearchEngineFilter::~DataBaseSearchEngineFilter(){

}

// _PRIVATE_METHODS_ DataBaseGeneralInformation.cpp


// _PUBLIC_METHODS_ DataBaseGeneralInformation.cpp
GET_DEFINITION(DataBaseSearchEngineFilter, DataBaseSearchEngineFilterError, error);

bool DataBaseSearchEngineFilter::initialize(bool retThis, uint type, uint param, void *value){
    this->retThis = retThis;
    if(type != UINT_MAX){
        error = DATABASE_SEARCH_ENGINE_FILTER_NO_ERROR;
        this->type = type;
        if(param != UINT_MAX){
            this->param = param;
            this->value = value;
        }
    }else{
        if((param < NUMB_OF_DATABASE_OBJECT_PARAMETERS && value) || param == UINT_MAX){
            error = DATABASE_SEARCH_ENGINE_FILTER_NO_ERROR;
            this->param = param;
            this->value = value;
        }else{
            error = DATABASE_SEARCH_ENGINE_FILTER_ERROR_UNITIALIZED;
        }
    }
    return (error == DATABASE_SEARCH_ENGINE_FILTER_NO_ERROR);
}

void DataBaseSearchEngineFilter::addLinkedAndFilter(DataBaseSearchEngineFilter *filter){
    SET_PTR_DO(andFilter, filter);
}

void DataBaseSearchEngineFilter::addLinkedOrFilter(DataBaseSearchEngineFilter *filter){
    SET_PTR_DO(orFilter, filter);
}

void DataBaseSearchEngineFilter::addLinkedDeepFilter(DataBaseSearchEngineFilter *filter){
    SET_PTR_DO(deepFilter, filter);
}

bool DataBaseSearchEngineFilter::filter(DataBaseObject *dbObj){

    // Filter This Object
    bool ret = false;
    GetParamRules gpr;
    DataBaseObject* tmpObj = nullptr;
    /*
    if(type != UINT_MAX){
        if(dbObj->getObjectType() == type){
            if(param != UINT_MAX){
                gpr = {param, 0};
                if(!dbObj->isParamObject(param)){
                    if(value){
                        ret = dbObj->compareParams(value, gpr);
                        if(!gpr.compared){  // _PH_ Error
                            ret = false;
                        }else{
                            if(ret && andFilter)
                                ret = andFilter->filter(dbObj);
                        }
                    }
                }else{
                    if(!value){
                        do{
                            tmpObj = nullptr;
                            gpr = {param, gpr.index};
                            if(dbObj->getParam(&tmpObj, gpr) && tmpObj){
                                ret = filter(tmpObj);
                                if(ret && andFilter)
                                    ret = andFilter->filter(tmpObj);
                            }
                        }while(gpr.nextAvailable);
                    }
                }
            }else{
                if(andFilter)
                    ret = andFilter->filter(dbObj);
                else {
                    ret = true;
                }
            }
        }
        }else{
            ret = true;
            uint index = 0;
            uint numbOfParams = dbObj->getNumbOfParameters();
            if(param == UINT_MAX){
                // Check Obj with And Filter and others
                if(deepFilter){
                    ret = deepFilter->filter(dbObj);
                }else{
                    if(ret && andFilter){
                        ret = andFilter->filter(dbObj);
                    }
                }
                if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                    curEngine->addSearchResult(tmpObj);
                }
                for(uint i = NUMB_OF_DATABASE_OBJECT_PARAMETERS; i < numbOfParams; i++){
                    if(dbObj->isParamObject(i)){
                        index = 0;
                        do{
                            tmpObj = nullptr;
                            gpr = {i, index++};
                            if(dbObj->getParam(&tmpObj, gpr)){
                                ret = ((deepFilter)? deepFilter->filter(tmpObj) : filter(tmpObj));
                                if(ret && andFilter){
                                    ret = andFilter->filter(tmpObj);
                                }
                                if((ret || (orFilter && orFilter->filter(tmpObj))) && retThis){
                                    curEngine->addSearchResult(tmpObj);
                                }
                            }
                        }while(gpr.nextAvailable);
                    }
                }
            }else{  // Less then NUMB_OF_DATABASE_OBJECT_PARAMETERS and value != nullptr
                gpr = {param, 0};
                ret = dbObj->compareParams(value, gpr);
                if(!gpr.compared){  // _PH_ Error
                    ret = false;
                }else{
                    if(ret && andFilter)
                        ret = andFilter->filter(dbObj);
                }
                if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                    curEngine->addSearchResult(tmpObj);
                }
                index = 0;

            }            
        }
        */
    if(type != UINT_MAX){
        if(type == dbObj->getObjectType()){
            if(param != UINT_MAX){
                gpr = {param, 0};
                if(value){
                    if(!dbObj->isParamObject(param)){
                        ret = dbObj->compareParams(value, gpr);
                        if(gpr.compared){
                            if(ret && andFilter)
                                ret = andFilter->filter(dbObj);                            
                        }
                    }else{
                        do{
                            tmpObj = nullptr;
                            gpr = {param, gpr.index};
                            if(dbObj->getParam(&tmpObj, gpr) && tmpObj){
                                if(deepFilter)
                                    ret = deepFilter->filter(tmpObj);
                            }
                            if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                                curEngine->addSearchResult(dbObj);
                            }
                            gpr.index++;
                        }while(gpr.nextAvailable);

                    }
                    return ret;
                }else{
                    // Check Obj with And Filter and others
                    if(deepFilter){
                        ret = deepFilter->filter(dbObj);
                    }else{
                        if(ret && andFilter){
                            ret = andFilter->filter(dbObj);
                        }
                    }
                    if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                        curEngine->addSearchResult(tmpObj);
                    }
                    if(dbObj->isParamObject(param)){
                        do{
                            tmpObj = nullptr;
                            gpr = {param, gpr.index};
                            if(dbObj->getParam(&tmpObj, gpr) && tmpObj){
                                if(deepFilter)
                                    ret = deepFilter->filter(tmpObj);
                            }
                            if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                                curEngine->addSearchResult(dbObj);
                            }
                            gpr.index++;
                        }while(gpr.nextAvailable);
                    }
                }
            }else{
                if(deepFilter){
                    ret = deepFilter->filter(dbObj);
                }
                if(ret && andFilter){
                    ret = andFilter->filter(dbObj);
                }
            }
        }
    }else{
        if(param != UINT_MAX){
            gpr = {param};
            ret = dbObj->compareParams(value, gpr);
            if(gpr.compared){
                if(ret  && andFilter)
                    ret = andFilter->filter(dbObj);
                if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                    curEngine->addSearchResult(dbObj);
                }
            }
            if(ret){
                uint numbOfParams = dbObj->getNumbOfParameters();
                for(uint i = NUMB_OF_DATABASE_OBJECT_PARAMETERS; i < numbOfParams; i++){
                    if(dbObj->isParamObject(i)){
                        gpr.index = 0;
                        do{
                            tmpObj = nullptr;
                            gpr = {i, gpr.index};
                            if(dbObj->getParam(&tmpObj, gpr)){
                                ret = ((deepFilter)? deepFilter->filter(tmpObj) : filter(tmpObj));
                                if(ret && andFilter){
                                    ret = andFilter->filter(tmpObj);
                                }
                                if((ret || (orFilter && orFilter->filter(tmpObj))) && retThis){
                                    curEngine->addSearchResult(tmpObj);
                                }
                            }
                            gpr.index++;
                        }while(gpr.nextAvailable);
                    }
                }
            }
            return ret;
        }else{
            // Check Obj with And Filter and others
            if(deepFilter){
                ret = deepFilter->filter(dbObj);
            }else{
                if(ret && andFilter){
                    ret = andFilter->filter(dbObj);
                }
            }
            if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
                curEngine->addSearchResult(tmpObj);
            }
            uint numbOfParams = dbObj->getNumbOfParameters();
            for(uint i = NUMB_OF_DATABASE_OBJECT_PARAMETERS; i < numbOfParams; i++){
                if(dbObj->isParamObject(i)){
                    gpr.index = 0;
                    do{
                        tmpObj = nullptr;
                        gpr = {i, gpr.index};
                        if(dbObj->getParam(&tmpObj, gpr)){
                            ret = ((deepFilter)? deepFilter->filter(tmpObj) : filter(tmpObj));
                            /*if(ret && andFilter){
                                ret = andFilter->filter(tmpObj);
                            }*/
                            if((ret || (orFilter && orFilter->filter(tmpObj))) && retThis){
                                curEngine->addSearchResult(tmpObj);
                            }
                        }
                        gpr.index++;
                    }while(gpr.nextAvailable);
                }
            }
            return  ret;
        }
    }
    if((ret || (orFilter && orFilter->filter(dbObj))) && retThis){
        curEngine->addSearchResult(dbObj);
    }
    return ret;

}

bool DataBaseSearchEngineFilter::filter(DataBaseObject *dbObj, GetParamRules& gpr){
    /*if(dbObj->getObjectType() == type){
        if(param != UINT_MAX){
            if(!dbObj->compareParams(value, gpr) && gpr.compared)
                return false;
        }
        return (linkedLogicAndFilter)? linkedLogicAndFilter->filter(dbObj) : true;
    }else{
        return false;
    }*/
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
