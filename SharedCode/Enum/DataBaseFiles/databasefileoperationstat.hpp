#ifndef DATABASEFILEOPERATIONSTAT_HPP
#define DATABASEFILEOPERATIONSTAT_HPP

// _ENUM_ Databasefileoperationstat -----------------------------------------------------------------------------------------------------------------------------------------------
enum DataBaseFileOperationStat{
    DATABASE_FILE_OPERATION_INITIALIZATION,
    //DATABASE_FILE_OPERATION_DB_GENERAL,
    //DATABASE_FILE_OPERATION_DB_END_GENERAL,
    DATABASE_FILE_OPERATION_DB_INIT,
    DATABASE_FILE_OPERATION_DB_PROCESSING,
    DATABASE_FILE_OPERATION_DB_CHANGE_OBJECT_TYPE,
    DATABASE_FILE_OPERATION_DB_END_BASE,
    DATABASE_FILE_OPERATION_DB_CATEGORY,
    DATABASE_FILE_OPERATION_DB_END_CATEGORY,
    DATABASE_FILE_OPERATION_DB_RECORD,
    DATABASE_FILE_OPERATION_DB_END_RECORD,        
    NUMB_OF_DATABASE_FILE_OPERATIONS
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // DATABASEFILEOPERATIONSTAT
