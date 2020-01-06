#ifndef SIMAREAPARAM_HPP
#define SIMAREAPARAM_HPP

#include"GeneralPurposeMacros/filemenegmentmacros.hpp"

#define SimulationArea_PARAM_ID_REQUIRED (false)

// _SIMULATION_AREA_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define SIMULATION_AREA_OBJECTS_PARAM_NAME ("objects")
#define SIMULATION_AREA_SHAPE_PARAM_NAME ("shape")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <SimulationAreaParameters Enum Name>_PARAM_NAME
// Example:For SIMULATION_AREA_NAME, type macro SIMULATION_AREA_NAME_PARAM_NAME
//
// ------------------------------------------

// _SIMULATION_AREA_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define SIMULATION_AREA_OBJECTS_PARAM_NAME_LENGTH (PARAM_LENGTH_7)
#define SIMULATION_AREA_SHAPE_PARAM_NAME_LENGTH (PARAM_LENGTH_5)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <SimulationAreaParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For SIMULATION_AREA_NAME, type macro SIMULATION_AREA_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_PARAM_OPTIONALITY_MACROS_
#define SIMULATION_AREA_OBJECTS_PARAM_OPTIONALITY (true)
#define SIMULATION_AREA_SHAPE_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <SimulationAreaParameters Enum Name>_PARAM_OPTIONALITY
// Example:For SIMULATION_AREA_NAME, type macro SIMULATION_AREA_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_PARAM_PARAM_IS_OBJECT_MACROS_
#define SIMULATION_AREA_OBJECTS_PARAM_PARAM_IS_OBJECT (true)
#define SIMULATION_AREA_SHAPE_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <SimulationAreaParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For SIMULATION_AREA_NAME, type macro SIMULATION_AREA_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ SimulationAreaParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum SimulationAreaParameters{

    // All List Parameters Below vvvvvvvvvvvvv

    NUMB_OF_SIMULATION_AREA_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // SIMAREAPARAM_HPP
