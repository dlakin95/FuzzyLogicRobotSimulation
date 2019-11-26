#ifndef DATABASESEARCHENGINE_HPP
#define DATABASESEARCHENGINE_HPP

// _INCLUDES_ DataBaseSearchEngine.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QObject>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"Enum/DataBaseFiles/databaseerror.hpp"
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"
#include"databaseobjecttype.hpp"
#include"databasesearchengineenums.hpp"
#include"databasesearchenginefilter.hpp"
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseSearchEngine.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObject;
class DataBase;
class GetParamRules;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

struct DataBaseSearchEngineInitializer{
    DataBaseSearchEngineFilter **filters = nullptr;
    uint numbOfFilters = 0;
    DataBaseSearchEngineInitializerError error = DATABASE_SEARCH_ENGINE_INITIALIZER_ERROR_UNINITIALIZED;
};

struct DataBaseSearchEngineResult{
    DataBaseObject** objects = nullptr;
    uint numbOfObjects = 0;
    DataBaseSearchEngineResultError error = DATABASE_SEARCH_ENGINE_RESULT_NO_ERROR;
};

// _CLASSDEF_ DataBaseSearchEngine -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseSearchEngine{
public:
    // _CONSTRUCTORS_ DataBaseSearchEngine.hpp
    DataBaseSearchEngine();
    // _DESTRUCTORS_ DataBaseSearchEngine.hpp
    ~DataBaseSearchEngine();

protected:
    // _PRIVATE_MEMBERS_ DataBaseSearchEngine.hpp
    DataBaseSearchEngineInitializer initializer;
    DataBaseSearchEngineResult result;

public:
    // _PUBLIC_MEMBERS_ DataBaseSearchEngine.hpp

protected:
    // _PRIVATE_METHODS_ DataBaseSearchEngine.hpp

public:
    // _PUBLIC_METHODS_ DataBaseSearchEngine.hpp
    GET_DECLARATION(DataBaseSearchEngineResult&, result)
    GET_DECLARATION(DataBaseSearchEngineInitializer&, initializer)

    void addFilter(DataBaseSearchEngineFilter*);  // Add Static table
    bool checkAddedFilter(DataBaseSearchEngineFilter*);
    void clearInitializer();
    void clearResult();

    void filter(DataBaseObject*);
    bool search(DataBaseObject*, bool clearInit = true);

    bool addSearchResult(DataBaseObject*);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASESEARCHENGINE_HPP
