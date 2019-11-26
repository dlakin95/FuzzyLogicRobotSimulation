#ifndef FILEREADERROR_HPP
#define FILEREADERROR_HPP

// _ENUM_ FileReadError -----------------------------------------------------------------------------------------------------------------------------------------------
enum FileReadError{
    FILE_READ_NO_ERROR,
    FILE_READ_ERROR_EOF_WHILE_READING,
    FILE_READ_ERROR_EOF_WHILE_SEARCHING_PARAM_NAME,
    FILE_READ_ERROR_SPECIAL_CHARACKTER_WRONG_POSITION,

    NUMB_OF_FILE_READ_ERRORS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // FILEREADERROR
