#ifndef OBSTACLEPARAM_HPP
#define OBSTACLEPARAM_HPP

#define Obstacle_PARAM_ID_REQUIRED (false)

// _OBSTACLE_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define OBSTACLE_SHAPE_PARAM_NAME ("shape")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <ObstacleParameters Enum Name>_PARAM_NAME
// Example:For OBSTACLE_NAME, type macro OBSTACLE_NAME_PARAM_NAME
//
// ------------------------------------------

// _OBSTACLE_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define OBSTACLE_SHAPE_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <ObstacleParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For OBSTACLE_NAME, type macro OBSTACLE_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _OBSTACLE_PARAM_OPTIONALITY_MACROS_
#define OBSTACLE_SHAPE_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <ObstacleParameters Enum Name>_PARAM_OPTIONALITY
// Example:For OBSTACLE_NAME, type macro OBSTACLE_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _OBSTACLE_PARAM_PARAM_IS_OBJECT_MACROS_
#define OBSTACLE_SHAPE_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <ObstacleParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For OBSTACLE_NAME, type macro OBSTACLE_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ ObstacleParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum ObstacleParameters{

    // All List Parameters Below vvvvvvvvvvvvv
    OBSTACLE_SHAPE,

    NUMB_OF_OBSTACLE_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // OBSTACLEPARAM_HPP
