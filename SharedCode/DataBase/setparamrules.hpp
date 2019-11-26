#ifndef SETPARAMRULES_HPP
#define SETPARAMRULES_HPP

#include<QObject>

#define SET_PARAM_RULES_SET_INIT(paramRules, objType) {(*(initializedParameters + objType::getSuperClassNumbOfParameters() + paramRules.param)) = true;}
#define SET_PARAM_RULES_CLEAR_INIT(paramRules, objType) {*(objType::initializedParameters + objType::getSuperClassNumbOfParameters() + paramRules.param) = false;}

enum SetParamAction{
    SET_PARAM_ACTION_NO_ACTION,
    SET_PARAM_ACTION_ADD,
    SET_PARAM_ACTION_REMOVE,
    SET_PARAM_ACTION_REPLACE,
    SET_PARAM_ACTION_CLEAR,
    NUMB_OF_SET_PARAM_ACTIONS
};

struct SetParamRules{
    uint param = UINT_MAX;
    uint index = UINT_MAX;
    SetParamAction action = NUMB_OF_SET_PARAM_ACTIONS;

    void* additionalPtr = nullptr;

};

#endif // SETPARAMRULES_HPP
