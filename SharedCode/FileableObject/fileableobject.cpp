#include "fileableobject.hpp"

// _INCLUDES_ Fileableobject.cpp -------------------------------------------------------------------------------------------------------------------
#include"../SharedCode/Enum/FilesMenegment/filereadingstat.hpp"
#include<QFile>
#include"DataBase/getparamrules.hpp"
#include"GeneralPurposeMacros/programcontrolmenegment.hpp"
// -------------------------------------------------------------------------------------------------------------------------------

// _CLASSIMP_ Fileableobject -----------------------------------------------------------------------------------------------------------------------------------------------

// _CONSTRUCTORS_ Fileableobject.cpp
FileableObject::FileableObject(){

}

// _DESTRUCTORS_ Fileableobject.cpp
FileableObject::~FileableObject(){

}

// _PRIVATE_METHODS_ Fileableobject.cpp


// _PUBLIC_METHODS_ Fileableobject.cpp
FileReadError FileableObject::readParameter(QString &param, QString &value, QFile &file){
    QString tempChar;
    QString tempStr;
    FileReadingStat frs = FILE_READING_SEARCHING;
    // Find next parameter
    INFINITE_LOOP{
        if(file.atEnd()){ // CANT BE AT END IN THIS FUNCTION (FILE IS CORRUPTED, SERVER INTERNAL ERROR, SERVER PAUSE WORK)
            //SERVER_MSG("___CRITICAL INTERNAL SERVER ERROR___");
            //SERVER_MSG("Clients file end while reading clients parameters");
            /* _PH_ Set internal server error in parent for pause server. Remember to send errors for all active threads*/
            return FILE_READ_ERROR_EOF_WHILE_READING;
        }
        readCharUtf8(file, tempChar);
        // Operation on readed character
        switch(frs){
            case FILE_READING_SEARCHING:
            {
            if(!(tempChar == '\n' || tempChar == '\r' || tempChar == ' ' || tempChar == '"')){
                frs = FILE_READING_READING_PARAM_NAME;
                tempStr.append(tempChar);
              }
            }
            break;
            case FILE_READING_READING_PARAM_NAME:
            {   // Read until equal sign or (file corrupted , internal server error, SERVER PAUSE WORK)
                if( tempChar == ' ' || tempChar == '\t'){
                    //SERVER_MSG("___CRITICAL INTERNAL SERVER ERROR___");
                    //SERVER_MSG("Clients file have corrupted parameter name");
                    /* _PH_ Set internal server error in parent for pause server. Remember to send errors for all active threads*/
                    return FILE_READ_ERROR_EOF_WHILE_READING;
                }
                if(tempChar == '=' ||tempChar == '\n' || tempChar == '\r'){
                    // Set QString param
                    param = tempStr;
                    // ---------------------
                    if(tempChar != '=')
                        return FILE_READ_NO_ERROR;
                    frs = FILE_READING_READING_VALUE;
                    tempStr.clear();
                }else{
                    tempStr.append(tempChar);
                }
            }
            break;
            case FILE_READING_READING_VALUE:
            {
                // Check if speech marks, if not read as number (End with EndLineSign and check only digits)
                    if(tempChar == '"'){
                        bool specialCharCatched = false;
                        readCharUtf8(file, tempChar);                        
                        while(tempChar != '"' || specialCharCatched){
                            if(specialCharCatched){
                                if((tempChar == "\"" || tempChar == "\\"))
                                    tempStr.chop(1);
                                else
                                    return FILE_READ_ERROR_SPECIAL_CHARACKTER_WRONG_POSITION;
                                specialCharCatched = false;
                            }else{
                                if(tempChar == "\\")
                                    specialCharCatched = true;
                            }
                            tempStr.append(tempChar);
                            if(file.atEnd()){ // CANT BE AT END IN THIS FUNCTION (FILE IS CORRUPTED, SERVER INTERNAL ERROR, SERVER PAUSE WORK)
                                //SERVER_MSG("___CRITICAL INTERNAL SERVER ERROR___");
                                //SERVER_MSG("Clients file end while reading clients parameters");
                                /* _PH_ Set internal server error in parent for pause server. Remember to send errors for all active threads*/
                                return FILE_READ_ERROR_EOF_WHILE_READING;
                            }
                            readCharUtf8(file, tempChar);
                        }

                    }else{
                        while(tempChar != '\n'){
                            if(file.atEnd()){ // CANT BE AT END IN THIS FUNCTION (FILE IS CORRUPTED, SERVER INTERNAL ERROR, SERVER PAUSE WORK)
                                //SERVER_MSG("___CRITICAL INTERNAL SERVER ERROR___");
                                //SERVER_MSG("Clients file end while reading clients parameters");
                                /* _PH_ Set internal server error in parent for pause server. Remember to send errors for all active threads*/
                                return FILE_READ_ERROR_EOF_WHILE_READING;
                            }
                            if((tempChar.at(0).toLatin1() < 48 || tempChar.at(0).toLatin1() > 57)){
                                if(tempChar != '\r'){
                                //SERVER_MSG("___CRITICAL INTERNAL SERVER ERROR___");
                                //SERVER_MSG("Clients file number parameter have no digit sign in value");
                                /* _PH_ Set internal server error in parent for pause server. Remember to send errors for all active threads*/
                                return FILE_READ_ERROR_EOF_WHILE_READING;
                                }
                            }else{
                                tempStr.append(tempChar);
                            }
                            readCharUtf8(file, tempChar);
                        }
                    }
                    value = tempStr;
                    return FILE_READ_NO_ERROR;
            }
        //break;
         }
    }
}

void FileableObject::readCharUtf8(QFile &file, QString &tempChar){
    QByteArray byteArr = QByteArray();
    char tempC;
    file.getChar(&tempC);
    byteArr.append(tempC);
    if(tempC < 0){
        if(tempC > -96)
        {
           file.getChar(&tempC);
           byteArr.append(tempC);
        }else{
             if(tempC > -112){
                 for(uint i = 0; i < 2; i++){
                    file.getChar(&tempC);
                    byteArr.append(tempC);
                 }
             }else{
                 if(tempC > -120){
                     for(uint i = 0; i < 3; i++){
                         file.getChar(&tempC);
                         byteArr.append(tempC);
                      }
                  }else{
                       if(tempC > -124){
                         for(uint i = 0; i < 4; i++){
                             file.getChar(&tempC);
                             byteArr.append(tempC);
                          }
                        }else{
                              for(uint i = 0; i < 5; i++){
                                   file.getChar(&tempC);
                                   byteArr.append(tempC);
                               }
                        }
                  }
             }
         }
    }
   tempChar.clear();
   tempChar = QString(byteArr);
}

QString FileableObject::getStringForFile(GetParamRules &paramRules){
    QString str = getParamName(paramRules.param);
    return str + QString("=\"") + getParam(paramRules).replace("\\", "\\\\").replace("\"", "\\\"") + QString("\"\n");
}

bool FileableObject::writeParameterToFile(QFile &file, GetParamRules& paramRules){
    file.write(getStringForFile(paramRules).toUtf8());
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
