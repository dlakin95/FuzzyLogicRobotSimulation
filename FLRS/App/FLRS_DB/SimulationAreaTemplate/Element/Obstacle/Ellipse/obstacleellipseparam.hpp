#ifndef OBSTACLEELLIPSEPARAM_HPP
#define OBSTACLEELLIPSEPARAM_HPP

#define ObstacleEllipse_PARAM_ID_REQUIRED (false)

// _OBSTACLE_ELLIPSE_PARAM_NAME_MACROS_ ---------------------------------------------------------
#define OBSTACLE_ELLIPSE_WIDTH_PARAM_NAME ("width")
#define OBSTACLE_ELLIPSE_HEIGHT_PARAM_NAME ("height")
// ---------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_MACRO_ STEP.Nr.
//
// Use Pattern: <ObstacleEllipseParameters Enum Name>_PARAM_NAME
// Example:For OBSTACLE_ELLIPSE_NAME, type macro OBSTACLE_ELLIPSE_NAME_PARAM_NAME
//
// ------------------------------------------

// _OBSTACLE_ELLIPSE_PARAM_NAME_LENGTH_MACROS_   !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
#define OBSTACLE_ELLIPSE_WIDTH_PARAM_NAME_LENGTH (PARAM_LENGTH_5)
#define OBSTACLE_ELLIPSE_HEIGHT_PARAM_NAME_LENGTH (PARAM_LENGTH_6)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_NAME_LENGTH_MACRO_      !!!WARNING!!! Use only param length macros defined in FileMenegmentMacros Header File !!!
//
// Use Pattern: <ObstacleEllipseParameters Enum Name>_PARAM_NAME_LENGTH
// Example:For OBSTACLE_ELLIPSE_NAME, type macro OBSTACLE_ELLIPSE_NAME_PARAM_NAME_LENGTH
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _OBSTACLE_ELLIPSE_PARAM_OPTIONALITY_MACROS_
#define OBSTACLE_ELLIPSE_WIDTH_PARAM_OPTIONALITY (false)
#define OBSTACLE_ELLIPSE_HEIGHT_PARAM_OPTIONALITY (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_OPTIONALITY_MACRO_

// Use Pattern: <ObstacleEllipseParameters Enum Name>_PARAM_OPTIONALITY
// Example:For OBSTACLE_ELLIPSE_NAME, type macro OBSTACLE_ELLIPSE_NAME_PARAM_OPTIONALITY
//
// -----------------------------------------------------------------------------------------------------------------------------------------

// _OBSTACLE_ELLIPSE_PARAM_PARAM_IS_OBJECT_MACROS_
#define OBSTACLE_ELLIPSE_WIDTH_PARAM_PARAM_IS_OBJECT (false)
#define OBSTACLE_ELLIPSE_HEIGHT_PARAM_PARAM_IS_OBJECT (false)
// ---------------------------------------------------------------------------------------------------------------------------------------
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_DB_CATEGORY_PARAM_PARAM_IS_OBJECT_MACRO_

// Use Pattern: <ObstacleEllipseParameters Enum Name>_PARAM_PARAM_IS_OBJECT
// Example:For OBSTACLE_ELLIPSE_NAME, type macro OBSTACLE_ELLIPSE_NAME_PARAM_PARAM_IS_OBJECT
//
// -----------------------------------------------------------------------------------------------------------------------------------------


// _ENUM_ ObstacleEllipseParameters -----------------------------------------------------------------------------------------------------------------------------------------------
enum ObstacleEllipseParameters{

    OBSTACLE_ELLIPSE_WIDTH,
    OBSTACLE_ELLIPSE_HEIGHT,
    // All List Parameters Below vvvvvvvvvvvvv

    NUMB_OF_OBSTACLE_ELLIPSE_PARAMETERS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------



#endif // OBSTACLEELLIPSEPARAM_HPP
