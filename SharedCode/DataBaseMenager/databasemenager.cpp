// _INCLUDES_ DataBaseMenager.cpp -------------------------------------------------------------------------------------------------------------------
#include"databasemenager.hpp"
#include<QTextCodec>
#include"GeneralPurposeMacros/memorymenegementmacros.hpp"
#include<QFileDialog>
#include"DataBase/getparamrules.hpp"
#include"DataBase/databasesearchengine.hpp"
#include"Dialog/dialogquestion.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ DataBaseMenager -----------------------------------------------------------------------------------------------------------------------------------------------
constexpr bool DataBaseMenager::optionality[];
constexpr bool DataBaseMenager::paramIsObject[];

// _CONSTRUCTORS_ DataBaseMenager.cpp
DataBaseMenager::DataBaseMenager() : DataBaseObject(DATABASE_OBJECT_MENAGER, NUMB_OF_DATABASE_MENAGER_PARAMETERS){
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

// _DESTRUCTORS_ DataBaseMenager.cpp
DataBaseMenager::~DataBaseMenager(){
    for(uint i = 0; i < numbOfDataBasesInfo; i++, dataBaseInfo++)
    {
        SET_PTR_DO((*dataBaseInfo)->dataBase, nullptr);
        SET_PTR_DO((*dataBaseInfo), nullptr);
    }
    dataBaseInfo -= numbOfDataBasesInfo;
    numbOfDataBasesInfo = 0;
    SET_PTR_DOA(dataBaseInfo, nullptr);
}

// _PRIVATE_METHODS_ DataBaseMenager.cpp
uint8_t DataBaseMenager::restoreDataBaseFile(){
    if(!dataBaseFileBU.exists())
        return 1;   // No BackUp
    uint counter = 0;
    // Próba skopiowania backupu i zmiany nazwy
    if(dataBaseFile.exists())
        dataBaseFile.remove();
    while(!dataBaseFileBU.copy(dataBaseFile.fileName())){
        if(counter < 100)
            counter++;
        else
            return 2;   // Open File Error
        }
    return 0;
}

bool DataBaseMenager::createDataBaseFile(){
    if(dataBaseFile.exists())
        dataBaseFile.remove();
    if(!dataBaseFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }else{
        dataBaseFile.close();
    }
    return true;
}

bool DataBaseMenager::createDataBaseFileBackUp(){
  if(dataBaseFileBU.exists())
        dataBaseFileBU.remove();
  if(!dataBaseFile.copy(dataBaseFileBU.fileName()))
  {
      return false;
  }
  return true;
}

bool DataBaseMenager::removeDataBase(DataBaseInfo* db){
    if(db){
        switch(numbOfDataBasesInfo){
        case 1:
        {
            if(db == *dataBaseInfo){
                delete db;
                delete [] dataBaseInfo;
                dataBaseInfo = nullptr;
            }else{
                return false;
            }
        }
            break;
        case 0:
            return false;
        default:
        {
            DataBaseInfo** newElems = new DataBaseInfo*[numbOfDataBasesInfo - 1];
            DataBaseInfo** tempNewElem = newElems;
            for(uint i = 0; i < numbOfDataBasesInfo; i++, dataBaseInfo++, tempNewElem++){
                if(*dataBaseInfo == db){
                    SET_PTR_DO(db->dataBase, nullptr);
                    SET_PTR_DO(db, nullptr);
                    tempNewElem--;
                }else{
                    *tempNewElem = *dataBaseInfo;
                }
            }
            dataBaseInfo -= numbOfDataBasesInfo;
            delete [] dataBaseInfo;
            dataBaseInfo = newElems;
        }
            break;
        }
        numbOfDataBasesInfo--;
        return true;
    }else{
        return false;
    }
}


// _PUBLIC_METHODS_ DataBaseMenager.cpp

QString DataBaseMenager::getCurrentDataBaseVersion(){
    return QString("1.0");
}

bool DataBaseMenager::createDataBase(DataBase &setDb){
    //SET_PTR_DO(dataBase, setDb);
    QString dataBaseDirectoryPath = QFileDialog::getExistingDirectory();
    if(dataBaseDirectoryPath.isEmpty()){
        return false;
    }
    QDir dataBaseDir(dataBaseDirectoryPath);
    // Get DataBaseName
    // Try to Create New Directory
    QString dbName;
    GetParamRules gpr = {DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME)};
    if(!setDb.getParam(&dbName, gpr) || ((dataBaseDir.mkdir(dbName))? false: false) || !dataBaseDir.cd(dbName)){
        return false;
    }
    SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseMenager, DATABASE_MENAGER_OBJECTS), UINT_MAX, SET_PARAM_ACTION_ADD};
    DataBaseInfo* dbInfo = new DataBaseInfo{&setDb, DATABASE_FILE_NAME_GENERATOR(dataBaseDir.path() + QString("/") + dbName), DATABASE_BU_FILE_NAME_GENERATOR(dataBaseDir.path() + QString("/") + dbName)};
    if(!setParam(&dbInfo, spr) || !writeDataBase(*(*(dataBaseInfo + numbOfDataBasesInfo - 1)))){ // Error
        SET_PTR_DO(dbInfo, nullptr);
        return false;
    }
    // Everything is Fine
    return true;
}

bool DataBaseMenager::openDataBase(DataBase& db){   // _PH_ As argument put database object needed in the app (static binding) . Take care of fail event and destroy memory of object when fail event occur.
    QString dataBaseDirectoryPath = QFileDialog::getExistingDirectory();
    if(dataBaseDirectoryPath.isEmpty()){
        return false;
    }
    QString tempStr;
    QDir directory;
    // Get Directory Name
    directory.setPath(dataBaseDirectoryPath);
    tempStr = directory.dirName();
    if(tempStr.isEmpty()){
        return false;
    }
    // Check its open
    DataBaseSearchEngineFilter* filter = nullptr;
    filter = new DataBaseSearchEngineFilter(false, DATABASE_OBJECT_MENAGER, DB_GET_REAL_PARAM(DataBaseMenager, DATABASE_MENAGER_OBJECTS));
    DataBaseSearchEngineFilter* nameDeepFilter = new DataBaseSearchEngineFilter(true, UINT_MAX, DB_GET_REAL_PARAM(DataBaseObject, DATABASE_OBJECT_NAME), &tempStr);
    filter->addLinkedDeepFilter(nameDeepFilter);
    DataBaseSearchEngine dbSearchEngine;
    dbSearchEngine.addFilter(filter);
    if(dbSearchEngine.search(this)){   // Success
        if(dbSearchEngine.get_result().numbOfObjects > 0){  // Category with the same name exist
            // Data Base Open already
            // _PH_
            DialogQuestion dlg(QString("Open Data Base Info"), QString("Database is already open."),nullptr, QString("Ok"));
            dlg.exec();
            // ---
            return true;
        }
    }else{  // Search Engine Fail
        return false;
    }
    // Check Directory Content (Only DatabaseFile, DataBaseFileBU)
    QFileInfoList fileInfoList = directory.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    uint numbOfFiles = static_cast<uint>(fileInfoList.count());
    if(numbOfFiles != DATABASE_DIR_NUMB_OF_FILES){
        return false;
    }
    {
        const QString databaseDirFileNames[DATABASE_DIR_NUMB_OF_FILES] = {
            DATABASE_FILE_NAME_GENERATOR(tempStr),
            DATABASE_BU_FILE_NAME_GENERATOR(tempStr)
        };
        for(uint i = 0; i < numbOfFiles; i++){
            QFileInfo tempFileInfo = fileInfoList.at(i);
            if(!tempFileInfo.isFile())   // Its not a file - Failed
            {
                return false;
            }
            uint j = 0;
            for( ; j < DATABASE_DIR_NUMB_OF_FILES; j++)
                if(tempFileInfo.fileName() == databaseDirFileNames[i])  // Found - Failed
                    break;
            if(j == DATABASE_DIR_NUMB_OF_FILES){ // Not Found - Failed
                return false;
            }
        }
    }    
    // Try to Read
    DataBaseInfo* newDbInfo = new DataBaseInfo{&db, DATABASE_FILE_NAME_GENERATOR(dataBaseDirectoryPath + QString("//") + tempStr), DATABASE_BU_FILE_NAME_GENERATOR(dataBaseDirectoryPath + QString("//") + tempStr)};
    SetParamRules spr = {DB_GET_REAL_PARAM(DataBaseMenager, DATABASE_MENAGER_OBJECTS), UINT_MAX, SET_PARAM_ACTION_ADD};
    if(!readDataBase(*newDbInfo) || !setParam(&newDbInfo, spr)){
        SET_PTR_DO(newDbInfo, nullptr);
        return false;
    }
    // Everything is Fine
    // Setup DB
    return true;
}

bool DataBaseMenager::readDataBase(DataBaseInfo& dbInfo){
    //if(!ready || !dataBase)
        //return false;
    dataBaseFile.setFileName(dbInfo.dataBaseFile);
    dataBaseFileBU.setFileName(dbInfo.dataBaseFileBU);
    bool ret = false;
    bool backupRead = false;    
    if(!dataBaseFile.exists()){
        switch(restoreDataBaseFile()){
        case 1: // No BackUp
            if(!createDataBaseFile()) // Creating Error
                return false;
            break;
        case 2: // Open File Error
            return false;
        default:    // Restored File
            backupRead = true;
            break;
        }
    }
    if(!dataBaseFile.open(QIODevice::ReadOnly | QIODevice::Text)){  // File Not Open Error
        return false;
    }
    ret = dataBaseReader.readDataBase(dbInfo.dataBase, dataBaseFile);
    dataBaseFile.close();
    if(!backupRead && !ret){
        switch(restoreDataBaseFile()){
        case 1: // No BackUp
            if(!createDataBaseFile()) // Creating Error
                return false;
            break;
        case 2: // Open File Error
            return false;
        default:    // Restored File
            backupRead = true;
            break;
        }
        if(!dataBaseFile.open(QIODevice::ReadOnly | QIODevice::Text)){  // File Not Open Error
            return false;
        }
        ret = dataBaseReader.readDataBase(dbInfo.dataBase, dataBaseFile);
        dataBaseFile.close();
    }
    return ret;
}


#if DATABASE_MENAGER_READ_ONLY == false
bool DataBaseMenager::writeDataBase(DataBaseInfo& dbInfo){
    //if(!ready)
    //    return false;
    dataBaseFile.setFileName(dbInfo.dataBaseFile);
    dataBaseFileBU.setFileName(dbInfo.dataBaseFileBU);
    QFile tempFile("db.tmp");
    if(tempFile.exists())
        tempFile.remove();
    if(!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)){  // File Not Open Error
        return false;
    }
    // Write
    dataBaseWriter.writeDataBase(dbInfo.dataBase, tempFile);
    tempFile.close();
    dataBaseFile.remove();
    tempFile.rename(dataBaseFile.fileName());
    if(!createDataBaseFileBackUp()){
        return false;
    }
    return true;
}

bool DataBaseMenager::saveDataBase(DataBaseInfo& dbInfo){
    // 1.
    if(writeDataBase(dbInfo)){    // Success

        return true;
    }
    return false;
}

bool DataBaseMenager::saveAsDataBase(DataBaseInfo& dbInfo){
    QString tempStr = QFileDialog::getOpenFileName(nullptr, QString("Open DataBase File"));
    if(tempStr.isEmpty()){
        return false;
    }
    if(writeDataBase(dbInfo)){    // Success
        return true;
    }
    return false;
}

bool DataBaseMenager::saveAllDataBases(){
    for(uint i = 0; i < numbOfDataBasesInfo; i++){
        if(!saveDataBase(*(*(dataBaseInfo + i))))
            return false;
    }
    return true;
}
#endif

bool DataBaseMenager::safeCloseDB(DataBaseInfo& dbInfo){
    if(writeDataBase(dbInfo)){    // Success
        ready = false;
        return true;
    }
    return false;
}


const QString DataBaseMenager::getParamName(uint param){
    DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, DataBaseMenager, DataBaseObject);
    switch(static_cast<DataBaseMenagerParameters>(param)){
    DB_GET_PARAM_NAME(DATABASE_MENAGER_OBJECTS)
    default:
        return QString();
    }
}

QString DataBaseMenager::getParam(GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules,DataBaseMenager, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_QSTRING(DataBaseMenager);
    switch (static_cast<DataBaseMenagerParameters>(paramRules.param)) {
    default:
        return QString();
    }
}

bool DataBaseMenager::getParam(void *value, GetParamRules& paramRules){
    DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, DataBaseMenager, DataBaseObject);
    DB_OBJECT_IS_INITIALIZED_BOOL(DataBaseMenager);
    switch (static_cast<DataBaseMenagerParameters>(paramRules.param)) {
    case DATABASE_MENAGER_OBJECTS:
    {
        if(paramRules.index < numbOfDataBasesInfo){
            if(paramRules.index + 1 < numbOfDataBasesInfo)
                paramRules.nextAvailable = true;
            *static_cast<DataBase**>(value) = (*(dataBaseInfo + paramRules.index))->dataBase;
            break;
        }
        return false;
    }
    default:
        return false;
    }
    return true;
}

bool DataBaseMenager::setParam(void *value, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value,DataBaseMenager, DataBaseObject);
    bool ret = false;
    switch (static_cast<DataBaseMenagerParameters>(paramRules.param)) {
    case DATABASE_MENAGER_OBJECTS:
    {
        switch(paramRules.action){
        case SET_PARAM_ACTION_ADD:
        {
            ret = addDataBase(*static_cast<DataBaseInfo**>(value));
        }
            break;
        default:
            break;
        }
    }
        break;
   // For Parameters with SetParamRules
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBaseMenager);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBaseMenager);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
    return true;
}

bool DataBaseMenager::setParam(QString &str, SetParamRules& paramRules){
    DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, str,DataBaseMenager, DataBaseObject);
    bool ret = false;
    switch (static_cast<DataBaseMenagerParameters>(paramRules.param)) {
    default:
        return false;
    }
    // Initialized Settings
    switch(paramRules.action){
    case SET_PARAM_ACTION_ADD:
        if(ret)
            SET_PARAM_RULES_SET_INIT(paramRules, DataBaseMenager);
        break;
    case SET_PARAM_ACTION_CLEAR:
        if(ret)
            SET_PARAM_RULES_CLEAR_INIT(paramRules, DataBaseMenager);
        break;
    case SET_PARAM_ACTION_REMOVE:   // Check in param switch
    case SET_PARAM_ACTION_REPLACE:
    case SET_PARAM_ACTION_NO_ACTION:
    default:
        return false;
    }
     return true;
}

bool DataBaseMenager::compareParams(void *value, GetParamRules &rules){
    DB_OBJECT_COMPARE_PARAMS_CALL_BASE(rules, value, DataBaseMenager, DataBaseObject);
    bool ret = false;
    switch (static_cast<DataBaseMenagerParameters>(rules.param)) {
        default:
            return false;
    }
    rules.compared = true;
    return ret;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------



