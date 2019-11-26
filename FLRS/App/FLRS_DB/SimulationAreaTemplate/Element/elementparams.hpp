#ifndef LEDMATRIXPICTUREELEMENTPARAMETERS_HPP
#define LEDMATRIXPICTUREELEMENTPARAMETERS_HPP

#include"GeneralPurposeMacros/filemenegmentmacros.hpp"

// _SIMULATION_AREA_TEMPLATE_ELEMENT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define SIMULATION_AREA_TEMPLATE_ELEMENT_X_PARAM_NAME ("x")
#define SIMULATION_AREA_TEMPLATE_ELEMENT_Y_PARAM_NAME ("y")
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION_PARAM_NAME ("rotation")
#define SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_PARAM_NAME ("elemType")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <SimulationAreaTemplateElementParameters Enum Name>_PARAM_NAME
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_NAME_PARAM_NAME
//
// ------------------------------------------

#define SimulationAreaTemplateElement_PARAM_ID_REQUIRED (false)

// _SIMULATION_AREA_TEMPLATE_ELEMENT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define SIMULATION_AREA_TEMPLATE_ELEMENT_X_PARAM_NAME_LENGTH (PARAM_LENGTH_1)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_Y_PARAM_NAME_LENGTH (PARAM_LENGTH_1)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION_PARAM_NAME_LENGTH (PARAM_LENGTH_8)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_PARAM_NAME_LENGTH (PARAM_LENGTH_8)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <SimulationAreaTemplateElementParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_TEMPLATE_ELEMENT_PARAM_OPTIONALITY_MACROS_
#define SIMULATION_AREA_TEMPLATE_ELEMENT_X_PARAM_OPTIONALITY (false)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_Y_PARAM_OPTIONALITY (false)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION_PARAM_OPTIONALITY (true)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <SimulationAreaTemplateElementParameters Enum Name>_PARAM_OPTIONALITY
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_TEMPLATE_ELEMENT_PARAM_PARAM_IS_OBJECT_MACROS_
#define SIMULATION_AREA_TEMPLATE_ELEMENT_X_PARAM_PARAM_IS_OBJECT (false)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_Y_PARAM_PARAM_IS_OBJECT (false)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION_PARAM_PARAM_IS_OBJECT (false)
#define SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <SimulationAreaTemplateElementParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ SimulationAreaTemplateElementParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum SimulationAreaTemplateElementParameters{
    SIMULATION_AREA_TEMPLATE_ELEMENT_TYPE,    // if not set, any other param cant be set (return false)
    // All List Parameters Below vvvvvvvvvvvvv
    SIMULATION_AREA_TEMPLATE_ELEMENT_X,
    SIMULATION_AREA_TEMPLATE_ELEMENT_Y,
    SIMULATION_AREA_TEMPLATE_ELEMENT_ROTATION,

    NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // LEDMATRIXPICTUREELEMENTPARAMETERS_HPP
