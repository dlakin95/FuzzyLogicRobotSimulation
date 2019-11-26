#ifndef DATABASEOBJECTPARAMETERS_HPP
#define DATABASEOBJECTPARAMETERS_HPP

#include"../GeneralPurposeMacros/filemenegmentmacros.hpp"

// General Macros
#define DB_OBJECT_MACRO_ACCESS(param, macro) param##_PARAM_##macro
#define DB_OBJECT_MACRO_ACCESS_NAME(param) DB_OBJECT_MACRO_ACCESS(param, NAME)
#define DB_OBJECT_MACRO_ACCESS_NAME_LENGTH(param) DB_OBJECT_MACRO_ACCESS(param, NAME_LENGTH)
#define DB_OBJECT_MACRO_ACCESS_OPTIONALITY(param) DB_OBJECT_MACRO_ACCESS(param, OPTIONALITY)
#define DB_OBJECT_MACRO_ACCESS_PARAM_IS_OBJECT(param) DB_OBJECT_MACRO_ACCESS(param, PARAM_IS_OBJECT)

#define DB_OBJECT_MACRO_ACCESS_PARAM_ID_REQUIRED(type) DB_OBJECT_MACRO_ACCESS(type, ID_REQUIRED)

// _DATABASE_OBJECT_PARAM_ID_REQUIRED
#define DataBaseObject_PARAM_ID_REQUIRED (false)

// _DATABASE_OBJECT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define DATABASE_OBJECT_NAME_PARAM_NAME (QString("name"))
#define DATABASE_OBJECT_VERSION_PARAM_NAME (QString("objVer"))
#define DATABASE_OBJECT_TYPE_PARAM_NAME (QString("type"))
#define DATABASE_OBJECT_PARAM_OBJECT_ID_PARAM_NAME (QString("paramId"))
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <DatabaseObjectParameters Enum Name>_PARAM_NAME
// Example:For DATABASE_OBJECT_NAME, type macro DATABASE_OBJECT_NAME_PARAM_NAME
//
// ------------------------------------------

// _DATABASE_OBJECT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define DATABASE_OBJECT_NAME_PARAM_NAME_LENGTH (PARAM_LENGTH_4)
#define DATABASE_OBJECT_VERSION_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
#define DATABASE_OBJECT_TYPE_PARAM_NAME_LENGTH (PARAM_LENGTH_4)
#define DATABASE_OBJECT_PARAM_OBJECT_ID_PARAM_NAME_LENGTH (PARAM_LENGTH_7)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <DatabaseObjectParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For DATABASE_OBJECT_NAME, type macro DATABASE_OBJECT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _DATABASE_OBJECT_PARAM_OPTIONALITY_MACROS_
#define DATABASE_OBJECT_NAME_PARAM_OPTIONALITY (false)
#define DATABASE_OBJECT_VERSION_PARAM_OPTIONALITY (false)
#define DATABASE_OBJECT_TYPE_PARAM_OPTIONALITY (false)
#define DATABASE_OBJECT_PARAM_OBJECT_ID_PARAM_OPTIONALITY (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <DatabaseObjectParameters Enum Name>_PARAM_OPTIONALITY
// Example:For DATABASE_OBJECT_NAME, type macro DATABASE_OBJECT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _DATABASE_OBJECT_PARAM_PARAM_IS_OBJECT_MACROS_
#define DATABASE_OBJECT_NAME_PARAM_PARAM_IS_OBJECT (false)
#define DATABASE_OBJECT_VERSION_PARAM_PARAM_IS_OBJECT (false)
#define DATABASE_OBJECT_TYPE_PARAM_PARAM_IS_OBJECT (false)
#define DATABASE_OBJECT_PARAM_OBJECT_ID_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <DatabaseObjectParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For DATABASE_OBJECT_NAME, type macro DATABASE_OBJECT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ DatabaseObjectParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum DatabaseObjectParameters{
    DATABASE_OBJECT_NAME,
    DATABASE_OBJECT_VERSION,    
    DATABASE_OBJECT_PARAM_OBJECT_ID,
    DATABASE_OBJECT_TYPE,   // ALWAYS AT END -- IMPORTANT --
    NUMB_OF_DATABASE_OBJECT_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEOBJECTPARAMETERS
