#ifndef LEDMATRIXPICTUREBASICCONFIG_HPP
#define LEDMATRIXPICTUREBASICCONFIG_HPP

#include"DataBase/databaseobject.hpp"
#include"ledmatrixpicturebasicconfigparameters.hpp"

class LEDMatrixPictureBasicConfig : public DataBaseObject{
public:
    LEDMatrixPictureBasicConfig();
    virtual ~LEDMatrixPictureBasicConfig() override;

protected:
    // Optionality Table
    static constexpr bool optionality[]=
    {

    };

    // Param is Object(Record) Table
    static constexpr bool paramIsObject[]=
    {


    };


public:
    DB_OBJECT_STANDARD_METHODS_NO_TYPES(LEDMatrixPictureBasicConfig, DataBaseObject, LEDMatrixPictureBasicConfigParameters, NUMB_OF_LED_MATRIX_PICTURE_BASIC_CONFIG_PARAMETERS, NUMB_OF_DATABASE_OBJECT_PARAMETERS)
    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    virtual DataBaseObject* createObject()override{return nullptr;}

};

#endif // LEDMATRIXPICTUREBASICCONFIG_HPP
