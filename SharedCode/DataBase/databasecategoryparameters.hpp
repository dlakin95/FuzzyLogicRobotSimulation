#ifndef DATABASECATEGORYPARAMETERS_HPP
#define DATABASECATEGORYPARAMETERS_HPP

#include"GeneralPurposeMacros/filemenegmentmacros.hpp"

#define DataBaseCategory_PARAM_ID_REQUIRED (true)

// _DATABASE_CATEGORY_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define DATABASE_CATEGORY_OBJECTS_PARAM_NAME ("objects")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <DatabaseGeneralInformationParameters Enum Name>_PARAM_NAME
// Example:For DATABASE_CATEGORY_NAME, type macro DATABASE_CATEGORY_NAME_PARAM_NAME
//
// ------------------------------------------

// _DATABASE_CATEGORY_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define DATABASE_CATEGORY_OBJECTS_PARAM_NAME_LENGTH (PARAM_LENGTH_7)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <DatabaseGeneralInformationParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For DATABASE_CATEGORY_NAME, type macro DATABASE_CATEGORY_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _DATABASE_CATEGORY_PARAM_OPTIONALITY_MACROS_
#define DATABASE_CATEGORY_OBJECTS_PARAM_OPTIONALITY (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <DatabaseGeneralInformationParameters Enum Name>_PARAM_OPTIONALITY
// Example:For DATABASE_CATEGORY_NAME, type macro DATABASE_CATEGORY_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _DATABASE_CATEGORY_PARAM_PARAM_IS_OBJECT_MACROS_
#define DATABASE_CATEGORY_OBJECTS_PARAM_PARAM_IS_OBJECT (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <DatabaseCategoryParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For DATABASE_OBJECT_NAME, type macro DATABASE_OBJECT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ DatabaseCategoryParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum DataBaseCategoryParameters{
    // All List Parameters Below vvvvvvvvvvvvv
    DATABASE_CATEGORY_OBJECTS,
    NUMB_OF_DATABASE_CATEGORY_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASECATEGORYPARAMETERS
