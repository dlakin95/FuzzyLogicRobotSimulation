#include "databasereader.hpp"

// _INCLUDES_ DataBaseReader.cpp -------------------------------------------------------------------------------------------------------------------
#include"DataBase/database.hpp"
#include"DataBase/databaseobject.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QFile>
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseReader -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ DataBaseReader.cpp
DataBaseReader::DataBaseReader(){

}

// _DESTRUCTORS_ DataBaseReader.cpp
DataBaseReader::~DataBaseReader(){

}

// _PRIVATE_METHODS_ DataBaseReader.cpp


// _PUBLIC_METHODS_ DataBaseReader.cpp
bool DataBaseReader::readDataBase(DataBase* dataBase, QFile& file){
    // Initialization
    //prepareToRead(dataBase);

    // File Read Block --------------
    dataBase->readDataBaseFile(file);
    // Error Occurred or End of Base - Check error parameter of dataBase
    if(dataBase->get_error() != DATABASE_NO_ERROR)// __ IF dataBase->error != NO_ERROR -- It means that error occurred
        return false;
    return true;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
