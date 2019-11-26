#ifndef FILEMENEGMENTMACROS_HPP
#define FILEMENEGMENTMACROS_HPP

#define WRITE_PARAM_TO_FILE(obj, paramN) (obj.getStrForFile(paramN).toUtf8())
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Object obj have to derived from FileableObject

// Check File Param
#define CHECK_PARAM_RETURN_V(checkStrV, paramNameText, numbOfSigns, returnV) {tempStr.clear(); tempStr = paramNameText; for(i = 0; i < numbOfSigns; i++) if(checkStrV.at(i) != tempStr.at(i)) break; if(i == numbOfSigns) return returnV;}
#define CHECK_PARAM_NO_RETURN_V(checkStrV, paramNameText, numbOfSigns) {tempStr.clear(); tempStr = paramNameText; for(i = 0; i < numbOfSigns; i++) if(checkStrV.at(i) != tempStr.at(i)) break;}
#define CHECK_PARAM_DECISION_BLOCK(checkStrV, paramNameText, numbOfSigns) tempStr.clear(); tempStr = paramNameText; for(i = 0; i < numbOfSigns; i++) if(checkStrV.at(i) != tempStr.at(i)) break; if(i == numbOfSigns)
#define CHECK_PARAM_INIT QString tempStr; int i = 0; SetParamRules spr; spr.action = SET_PARAM_ACTION_ADD;

// Param Length Macros
#define PARAM_LENGTH_1 (1)
#define PARAM_LENGTH_2 (2)
#define PARAM_LENGTH_4 (4)
#define PARAM_LENGTH_5 (5)
#define PARAM_LENGTH_6 (6)
#define PARAM_LENGTH_7 (7)
#define PARAM_LENGTH_8 (8)
#define PARAM_LENGTH_9 (9)
#define PARAM_LENGTH_10 (10)
#define PARAM_LENGTH_13 (13)
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// _ADD_PARAM_LENGTH_MACRO_
//
// Use Pattern: PARAM_LENGTH_4 for parameter length 4 signs
//
// --------------------------------


#endif // FILEMENEGMENTMACROS_HPP
