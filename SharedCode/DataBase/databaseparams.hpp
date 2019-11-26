#ifndef DATABASEPARAMS_HPP
#define DATABASEPARAMS_HPP

#include"../GeneralPurposeMacros/filemenegmentmacros.hpp"

#define DataBase_PARAM_ID_REQUIRED (false)

// _DATABASE_PARAM_NAME_MACROS_ ---------------------------------------------------------
// CONTROL MACROS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define DATABASE_PARAM_NAME (QString("DB"))
//#define DATABASE_GENERAL_PARAM_NAME (QString("DBgeneral"))
#define DATABASE_CATEGORY_PARAM_NAME (QString("DB_C"))
#define DATABASE_RECORD_PARAM_NAME (QString("DB_R"))
#define DATABASE_END_OF_RECORD_PARAM_NAME (QString("DB_EOR"))
#define DATABASE_END_OF_CATEGORY_PARAM_NAME (QString("DB_EOC"))
//#define DATABASE_END_OF_GENERAL_PARAM_NAME (QString("DB_EOG"))
#define DATABASE_END_OF_BASE_PARAM_NAME (QString("DB_EOB"))
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// GENERAL INFORMATIONS
//#define DATABASE_NAME_PARAM_NAME (QString("DBname"))
//#define DATABASE_VERSION_PARAM_NAME (QString("DBversion"))
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <DatabaseParameters Enum Name>_PARAM_NAME
// Example:For DATABASE_VERSION, type macro DATABASE_VERSION_PARAM_NAME
//
// ------------------------------------------

// _DATABASE_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
// CONTROL MACROS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define DATABASE_PARAM_NAME_LENGTH (PARAM_LENGTH_2)
//#define DATABASE_GENERAL_PARAM_NAME_LENGTH (PARAM_LENGTH_9)
#define DATABASE_CATEGORY_PARAM_NAME_LENGTH (PARAM_LENGTH_4)
#define DATABASE_RECORD_PARAM_NAME_LENGTH (PARAM_LENGTH_4)
#define DATABASE_END_OF_RECORD_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
#define DATABASE_END_OF_CATEGORY_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
//#define DATABASE_END_OF_GENERAL_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
#define DATABASE_END_OF_BASE_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// _DATABASE_PARAM_NAME_MACROS_ ---------------------------------------------------------
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <DatabaseParameters Enum Name>_PARAM_NAME
// Example:For DATABASE_NAME, type macro DATABASE_NAME_PARAM_NAME
//
// ------------------------------------------

// _DATABASE_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <DatabaseParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For DATABASE_NAME, type macro DATABASE_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _DATABASE_PARAM_OPTIONALITY_MACROS_

// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <DatabaseParameters Enum Name>_PARAM_OPTIONALITY
// Example:For DATABASE_NAME, type macro DATABASE_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _DATABASE_PARAM_PARAM_IS_OBJECT_MACROS_

// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_OBJECT_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <DatabaseParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For DATABASE_NAME, type macro DATABASE_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ DatabaseParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum DatabaseParameters{
    NUMB_OF_DATABASE_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEPARAMS_HPP
