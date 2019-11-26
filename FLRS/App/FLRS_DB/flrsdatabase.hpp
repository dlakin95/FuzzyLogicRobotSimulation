#ifndef LEDMATRIXPICTUREDATABASE_HPP
#define LEDMATRIXPICTUREDATABASE_HPP

#include"DataBase/database.hpp"
#include"flrsdatabaseparameters.hpp"
#include"flrsdatabasetypes.hpp"

class DataBaseObject;
class FuzzyLogicRobotSimulationDataBase : public DataBase{
public:
    FuzzyLogicRobotSimulationDataBase();
    virtual ~FuzzyLogicRobotSimulationDataBase() override;

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
    DB_OBJECT_STANDARD_METHODS(FuzzyLogicRobotSimulationDataBase, DataBase, FuzzyLogicRobotSimulationDataBaseParameters, NUMB_OF_FUZZY_LOGIC_ROBOT_SIMULATION_DATA_BASE_PARAMETERS, NUMB_OF_DATABASE_PARAMETERS , FuzzyLogicRobotSimulationDataBaseTypes, NUMB_OF_FUZZY_LOGIC_ROBOT_SIMULATION_DATA_BASE_TYPES, NUMB_OF_DATABASE_CATEGORY_TYPES)

    virtual DataBaseFileOperationStat checkParamAndProccess(QString&, QString&, DataBaseObjectsReadFileContainer*)override;

    //virtual DataBaseObject* createObject()override{return nullptr;}
    virtual DataBaseObject* createObject(DataBaseObject* obj, uint newType) override;

};

#endif // LEDMATRIXPICTUREDATABASE_HPP
