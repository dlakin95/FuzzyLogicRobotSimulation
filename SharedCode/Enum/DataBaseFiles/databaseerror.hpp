#ifndef DATABASEERROR_HPP
#define DATABASEERROR_HPP

// _ENUM_ DataBaseError -----------------------------------------------------------------------------------------------------------------------------------------------
enum DataBaseError{
    DATABASE_NO_ERROR,
    DATABASE_CREATE_OR_PUSH_TO_CONTAINER_ERROR,
    DATABASE_NOT_COMPLETE_OBJECT,
    DATABASE_PULL_FROM_CONTAINER_ERROR,
    DATABASE_ADDING_NEW_OBJECT_ERROR,
    DATABASE_UNKNOWN_PARAMETER_ERROR,
    DATABASE_CHANGE_OBJECT_TYPE_ERROR,
    DATABASE_NUMB_OF_ERRORS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEERROR
