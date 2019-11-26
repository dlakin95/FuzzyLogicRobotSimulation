#ifndef FILEABLEOBJECT_HPP
#define FILEABLEOBJECT_HPP
// _INCLUDES_ FileableObject.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QString>
#include<QFile>
#include"Enum/FilesMenegment/filereaderror.hpp"

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ FileableObject.hpp --------------------------------------------------------------------------------------------------------------------------------------
class GetParamRules;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ FileableObject -----------------------------------------------------------------------------------------------------------------------------------------------
class FileableObject{
public:
    // _CONSTRUCTORS_ FileableObject.hpp
    FileableObject();

    // _DESTRUCTORS_ FileableObject.hpp
    virtual ~FileableObject();

private:
    // _PRIVATE_MEMBERS_ FileableObject.hpp

public:
    // _PUBLIC_MEMBERS_ FileableObject.hpp

private:
    // _PRIVATE_METHODS_ FileableObject.hpp
    void readCharUtf8(QFile&, QString& tempChar);
public:
    // _PUBLIC_METHODS_ FileableObject.hpp
    FileReadError readParameter(QString&, QString&, QFile&);
    QString getStringForFile(GetParamRules&);
    virtual const QString getParamName(uint) = 0;
    virtual QString getParam(GetParamRules&) = 0;
    bool writeParameterToFile(QFile&, GetParamRules&);
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // FILEABLEOBJECT
