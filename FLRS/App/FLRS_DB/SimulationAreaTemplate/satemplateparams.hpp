#ifndef SIMULATIONAREATEMPLATEPARAMETERS_HPP
#define SIMULATIONAREATEMPLATEPARAMETERS_HPP

#include"GeneralPurposeMacros/filemenegmentmacros.hpp"

// _SIMULATION_AREA_TEMPLATE_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define SIMULATION_AREA_TEMPLATE_ELEMENTS_PARAM_NAME ("elements")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <SimulationAreaTemplateParameters Enum Name>_PARAM_NAME
// Example:For SIMULATION_AREA_TEMPLATE_NAME, type macro SIMULATION_AREA_TEMPLATE_NAME_PARAM_NAME
//
// ------------------------------------------

#define SimulationAreaTemplate_PARAM_ID_REQUIRED (true)

// _SIMULATION_AREA_TEMPLATE_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define SIMULATION_AREA_TEMPLATE_ELEMENTS_PARAM_NAME_LENGTH (PARAM_LENGTH_7)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <SimulationAreaTemplateParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For SIMULATION_AREA_TEMPLATE_NAME, type macro SIMULATION_AREA_TEMPLATE_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_TEMPLATE_PARAM_OPTIONALITY_MACROS_
#define SIMULATION_AREA_TEMPLATE_ELEMENTS_PARAM_OPTIONALITY (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <SimulationAreaTemplateParameters Enum Name>_PARAM_OPTIONALITY
// Example:For SIMULATION_AREA_TEMPLATE_NAME, type macro SIMULATION_AREA_TEMPLATE_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_TEMPLATE_PARAM_PARAM_IS_OBJECT_MACROS_
#define SIMULATION_AREA_TEMPLATE_ELEMENTS_PARAM_PARAM_IS_OBJECT (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <SimulationAreaTemplateParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For SIMULATION_AREA_TEMPLATE_NAME, type macro SIMULATION_AREA_TEMPLATE_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ SimulationAreaTemplateParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum SimulationAreaTemplateParameters{
    // All List Parameters Below vvvvvvvvvvvvv
    //SIMULATION_AREA_TEMPLATE_BASIC_CONFIG,
    SIMULATION_AREA_TEMPLATE_ELEMENTS,
    NUMB_OF_SIMULATION_AREA_TEMPLATE_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // SIMULATIONAREATEMPLATEPARAMETERS_HPP
