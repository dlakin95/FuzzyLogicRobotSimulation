#ifndef GETPARAMRULES_HPP
#define GETPARAMRULES_HPP

#include<QObject>

struct GetParamRules{
    uint param = UINT_MAX;
    uint index = UINT_MAX;    
    bool nextAvailable = false;
    bool compared = false;
    bool initialized = false;
    bool getNumbOfObjects = false;
};


#endif // GETPARAMRULES_HPP
