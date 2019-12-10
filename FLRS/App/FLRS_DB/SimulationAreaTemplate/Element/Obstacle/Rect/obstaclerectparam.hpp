#ifndef ORPARAM_HPP
#define ORPARAM_HPP

#define ObstacleRect_PARAM_ID_REQUIRED (false)

// _OBSTACLE_RECT_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define OBSTACLE_RECT_WIDTH_PARAM_NAME ("width")
#define OBSTACLE_RECT_HEIGHT_PARAM_NAME ("height")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <ObstacleRectParameters Enum Name>_PARAM_NAME
// Example:For OBSTACLE_RECT_NAME, type macro OBSTACLE_RECT_NAME_PARAM_NAME
//
// ------------------------------------------

// _OBSTACLE_RECT_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define OBSTACLE_RECT_WIDTH_PARAM_NAME_LENGTH (PARAM_LENGTH_5)
#define OBSTACLE_RECT_HEIGHT_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <ObstacleRectParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For OBSTACLE_RECT_NAME, type macro OBSTACLE_RECT_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _OBSTACLE_RECT_PARAM_OPTIONALITY_MACROS_
#define OBSTACLE_RECT_WIDTH_PARAM_OPTIONALITY (false)
#define OBSTACLE_RECT_HEIGHT_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <ObstacleRectParameters Enum Name>_PARAM_OPTIONALITY
// Example:For OBSTACLE_RECT_NAME, type macro OBSTACLE_RECT_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _OBSTACLE_RECT_PARAM_PARAM_IS_OBJECT_MACROS_
#define OBSTACLE_RECT_WIDTH_PARAM_PARAM_IS_OBJECT (false)
#define OBSTACLE_RECT_HEIGHT_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <ObstacleRectParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For OBSTACLE_RECT_NAME, type macro OBSTACLE_RECT_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ ObstacleRectParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum ObstacleRectParameters{
    OBSTACLE_RECT_WIDTH,
    OBSTACLE_RECT_HEIGHT,
    // All List Parameters Below vvvvvvvvvvvvv

    NUMB_OF_OBSTACLE_RECT_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------



#endif // ORPARAM_HPP
