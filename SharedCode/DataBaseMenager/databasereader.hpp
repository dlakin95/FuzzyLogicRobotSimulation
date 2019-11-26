#ifndef DATABASEREADER_HPP
#define DATABASEREADER_HPP
// _INCLUDES_ DataBaseReader.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include"GeneralPurposeMacros/filemenegmentmacros.hpp"
#include"Enum/DataBaseFiles/databasefileoperationstat.hpp"

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseReader.hpp --------------------------------------------------------------------------------------------------------------------------------------
class DataBase;
class DataBaseObject;
class DataBaseObjectParameterRules;
class QFile;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseReader -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseReader{
public:
    // _CONSTRUCTORS_ DataBaseReader.hpp
    DataBaseReader();
    // _DESTRUCTORS_ DataBaseReader.hpp
    ~DataBaseReader();

private:
    // _PRIVATE_MEMBERS_ DataBaseReader.hpp

public:
    // _PUBLIC_MEMBERS_ DataBaseReader.hpp

private:
    // _PRIVATE_METHODS_ DataBaseReader.hpp
   void prepareToRead(DataBase*);

public:
    // _PUBLIC_METHODS_ DataBaseReader.hpp
    bool readDataBase(DataBase*, QFile&);
    bool checkParameters(DataBaseObject*);

};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEREADER
