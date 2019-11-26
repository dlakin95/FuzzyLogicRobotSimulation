#ifndef DATABASEOBJECTSREADFILECONTAINER_HPP
#define DATABASEOBJECTSREADFILECONTAINER_HPP
// _INCLUDES_ DataBaseObjectsReadFileContainer.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QObject>
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseObjectsReadFileContainer.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObject;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
struct DataBaseObjectsReadFileStat{
    DataBaseObject* dbObj = nullptr;
    uint lastReadedParam = UINT_MAX;
};

// _CLASSDEF_ DataBaseObjectsReadFileContainer -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObjectsReadFileContainer{
public:
    // _CONSTRUCTORS_ DataBaseObjectsReadFileContainer.hpp
    DataBaseObjectsReadFileContainer();
    // _DESTRUCTORS_ DataBaseObjectsReadFileContainer.hpp
    ~DataBaseObjectsReadFileContainer();

private:
    // _PRIVATE_MEMBERS_ DataBaseObjectsReadFileContainer.hpp
    DataBaseObjectsReadFileStat** readFileStats = nullptr;
    uint numbOfObjects = 0;
public:
    // _PUBLIC_MEMBERS_ DataBaseObjectsReadFileContainer.hpp

private:
    // _PRIVATE_METHODS_ DataBaseObjectsReadFileContainer.hpp

public:
    // _PUBLIC_METHODS_ DataBaseObjectsReadFileContainer.hpp
    DataBaseObjectsReadFileStat* getSecondLastObject();
    DataBaseObjectsReadFileStat* getLastObject();
    bool checkLastObjectReadedProperly();
    bool push(DataBaseObject*);
    bool changeObjectType(DataBaseObject*);
    DataBaseObject* pull();
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEOBJECTSREADFILECONTAINER
