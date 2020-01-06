#ifndef SARECTPARAM_HPP
#define SARECTPARAM_HPP

#define SimulationAreaRect_PARAM_ID_REQUIRED (false)

// _SIMULATION_AREA_RECT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define SIMULATION_AREA_RECT_WIDTH_PARAM_NAME ("width")
#define SIMULATION_AREA_RECT_HEIGHT_PARAM_NAME ("height")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <SimulationAreaRectParameters Enum Name>_PARAM_NAME
// Example:For SIMULATION_AREA_RECT_NAME, type macro SIMULATION_AREA_RECT_NAME_PARAM_NAME
//
// ------------------------------------------

// _SIMULATION_AREA_RECT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define SIMULATION_AREA_RECT_WIDTH_PARAM_NAME_LENGTH (PARAM_LENGTH_5)
#define SIMULATION_AREA_RECT_HEIGHT_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <SimulationAreaRectParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For SIMULATION_AREA_RECT_NAME, type macro SIMULATION_AREA_RECT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_RECT_PARAM_OPTIONALITY_MACROS_
#define SIMULATION_AREA_RECT_WIDTH_PARAM_OPTIONALITY (false)
#define SIMULATION_AREA_RECT_HEIGHT_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <SimulationAreaRectParameters Enum Name>_PARAM_OPTIONALITY
// Example:For SIMULATION_AREA_RECT_NAME, type macro SIMULATION_AREA_RECT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_RECT_PARAM_PARAM_IS_OBJECT_MACROS_
#define SIMULATION_AREA_RECT_WIDTH_PARAM_PARAM_IS_OBJECT (false)
#define SIMULATION_AREA_RECT_HEIGHT_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <SimulationAreaRectParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For SIMULATION_AREA_RECT_NAME, type macro SIMULATION_AREA_RECT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ SimulationAreaRectParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum SimulationAreaRectParameters{
    SIMULATION_AREA_RECT_WIDTH,
    SIMULATION_AREA_RECT_HEIGHT,
    // All List Parameters Below vvvvvvvvvvvvv

    NUMB_OF_SIMULATION_AREA_RECT_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // SARECTPARAM_HPP
