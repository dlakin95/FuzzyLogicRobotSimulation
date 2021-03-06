#ifndef ROBOTPARAMS_HPP
#define ROBOTPARAMS_HPP


#include"GeneralPurposeMacros/filemenegmentmacros.hpp"

#define SimulationAreaTemplateElementRobot_PARAM_ID_REQUIRED (false)

// _SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_OBJECTS_PARAM_NAME ("objects")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <SimulationAreaTemplateElementRobotParameters Enum Name>_PARAM_NAME
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME_PARAM_NAME
//
// ------------------------------------------

// _SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_OBJECTS_PARAM_NAME_LENGTH (PARAM_LENGTH_7)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <SimulationAreaTemplateElementRobotParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_PARAM_OPTIONALITY_MACROS_
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_OBJECTS_PARAM_OPTIONALITY (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <SimulationAreaTemplateElementRobotParameters Enum Name>_PARAM_OPTIONALITY
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_PARAM_PARAM_IS_OBJECT_MACROS_
#define SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_OBJECTS_PARAM_PARAM_IS_OBJECT (true)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <SimulationAreaTemplateElementRobotParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME, type macro SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ SimulationAreaTemplateElementRobotParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum SimulationAreaTemplateElementRobotParameters{
    // All List Parameters Below vvvvvvvvvvvvv

    NUMB_OF_SIMULATION_AREA_TEMPLATE_ELEMENT_ROBOT_PARAMETERS
};


#endif // ROBOTPARAMS_HPP
