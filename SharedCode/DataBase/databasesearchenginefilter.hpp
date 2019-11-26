#ifndef DATABASESEARCHENGINEFILTER_HPP
#define DATABASESEARCHENGINEFILTER_HPP

// _INCLUDES_ DataBaseSearchEngineFilter.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QObject>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"Enum/DataBaseFiles/databaseerror.hpp"
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"
#include"databaseobjecttype.hpp"
#include"databasesearchengineenums.hpp"
#include"databasesearchenginefiltererror.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseSearchEngineFilter.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObject;
class DataBase;
class GetParamRules;
class DataBaseSearchEngine;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------


// _CLASSDEF_ DataBaseSearchEngineFilter -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseSearchEngineFilter{
public:
    // _CONSTRUCTORS_ DataBaseSearchEngineFilter.hpp
    DataBaseSearchEngineFilter();
    DataBaseSearchEngineFilter(bool retThis, uint type = UINT_MAX, uint param = UINT_MAX, void* value = nullptr);
    // _DESTRUCTORS_ DataBaseSearchEngineFilter.hpp
    ~DataBaseSearchEngineFilter();

protected:
    // _PRIVATE_MEMBERS_ DataBaseSearchEngineFilter.hpp
    uint type = UINT_MAX;
    uint param = UINT_MAX;
    void* value = nullptr;
    bool retThis = false;
    //uint deepCounter = 0;
    DataBaseSearchEngineFilterError error = DATABASE_SEARCH_ENGINE_FILTER_ERROR_UNITIALIZED;

public:
    DataBaseSearchEngineFilter* orFilter = nullptr;
    DataBaseSearchEngineFilter* andFilter = nullptr;
    DataBaseSearchEngineFilter* deepFilter = nullptr;
    // _PUBLIC_MEMBERS_ DataBaseSearchEngineFilter.hpp
    static DataBaseSearchEngine* curEngine;
protected:
    // _PRIVATE_METHODS_ DataBaseSearchEngineFilter.hpp

public:
    GET_DECLARATION(DataBaseSearchEngineFilterError, error);

    // _PUBLIC_METHODS_ DataBaseSearchEngineFilter.hpp
    bool initialize(bool retThis, uint type = UINT_MAX, uint param = UINT_MAX, void* value = nullptr);
    void addLinkedAndFilter(DataBaseSearchEngineFilter*);
    void addLinkedOrFilter(DataBaseSearchEngineFilter*);
    void addLinkedDeepFilter(DataBaseSearchEngineFilter*);

    bool filter(DataBaseObject*);
    bool filter(DataBaseObject*, GetParamRules&);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // DATABASESEARCHENGINEFILTER_HPP
