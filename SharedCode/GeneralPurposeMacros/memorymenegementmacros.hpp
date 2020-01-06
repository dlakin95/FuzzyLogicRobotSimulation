#ifndef MEMORYMENEGEMENTMACROS_HPP
#define MEMORYMENEGEMENTMACROS_HPP

// Pointer Memory Menegment
#define SET_PTR_DO(ptr, newPtr) {if(ptr) {delete ptr; ptr = nullptr;} ptr = newPtr;}
#define SET_PTR_DOA(ptrA, newPtrA) {if(ptrA) {delete []ptrA; ptrA = nullptr;}; ptrA = newPtrA;}
#define SET_PTR_NDO(ptr, newPtr) {ptr = newPtr;}

// Array Memory Menegment
#define ARRAY_ADD_PTR_WITH_TEMP_PTR_RETURN_BOOL(objType, arr, arrSize, newObj) {if(newObj){if(arrSize + 1 > arrSize){objType** newObjs = new objType*[arrSize + 1]; objType** tempNewObj = newObjs; for(uint i = 0; i < arrSize; i++, tempNewObj++, arr++) (*tempNewObj) = *arr; (*tempNewObj) = newObj; arr -= arrSize; delete [] arr; arr = newObjs; arrSize++; return true;}else{delete newObj;}} return false;}
#define ARRAY_REPLACE_PTR_WITH_TEMP_PTR_RETURN_BOOL(objType, arr, arrSize, oldObj, newObj) {if(newObj) switch(arrSize){case 0: return false;default:{for(uint i = 0; i < arrSize; i++, arr++){if(*arr == oldObj){delete oldObj; oldObj = nullptr; *arr = newObj; arr -= i; return true;}} arr -= arrSize; }break;} return false;}
#define ARRAY_REMOVE_PTR_WITH_TEMP_PTR_RETURN_BOOL(objType, arr, arrSize, remObj) {if(remObj){switch(arrSize){case 1: {if(remObj == *arr){delete remObj; delete [] arr; arr = nullptr;}else{return false;}}break;case 0: return false;default:{objType** newElems = new objType*[arrSize - 1]; objType** tempNewElem = newElems; for(uint i = 0; i < arrSize; i++, arr++, tempNewElem++){if(*arr == remObj){delete remObj; remObj = nullptr; tempNewElem--;}else{*tempNewElem = *arr;}} arr -= arrSize; delete [] arr; arr = newElems;} break;} arrSize--; return true;}else{return false;}}
#define ARRAY_REMOVE_LAST_PTR_WITH_TEMP_PTR_RETURN_BOOL(objType, arr, arrSize) {switch(arrSize){case 1: if(arr){delete *arr; delete [] arr; arr = nullptr; arrSize--;}else{return false;}break;case 0: return false;default:{arrSize--; objType** newElems = new objType*[arrSize]; objType** tempNewElem = newElems; for(uint i = 0; i < arrSize; i++, arr++, tempNewElem++)*tempNewElem = *arr;delete *arr; arr -= arrSize; delete [] arr; arr = newElems;} break;} return true;}
#define ARRAY_CLEAR_PTR_WITH_TEMP_PTR(arr, arrSize) {if(arr){for(uint i = 0; i < arrSize; i++, arr++) {SET_PTR_DO((*arr), nullptr);} arr -= arrSize; SET_PTR_DOA(arr, nullptr);arrSize = 0;}}

#define ARRAY_ADD_PTR_WITH_TEMP_PTR_BOOL_ERROR(objType, arr, arrSize, newObj, error) {if(newObj){if(arrSize + 1 > arrSize){objType** newObjs = new objType*[arrSize + 1]; objType** tempNewObj = newObjs; for(uint i = 0; i < arrSize; i++, tempNewObj++, arr++) (*tempNewObj) = *arr; (*tempNewObj) = newObj; arr -= arrSize; delete [] arr; arr = newObjs; arrSize++; error = false;}else{delete newObj;  error = true;}}else{ error = true;}}
#define ARRAY_REMOVE_PTR_WITH_TEMP_PTR_BOOL_ERROR(objType, arr, arrSize, remObj, error) {if(remObj){switch(arrSize){case 1: {if(remObj == *arr){delete remObj; delete [] arr; arr = nullptr;}else{error = true;}}break;case 0: error = true;default:{objType** newElems = new objType*[arrSize - 1]; objType** tempNewElem = newElems; for(uint i = 0; i < arrSize; i++, arr++, tempNewElem++){if(*arr == remObj){delete remObj; remObj = nullptr; tempNewElem--;}else{*tempNewElem = *arr;}} arr -= arrSize; delete [] arr; arr = newElems;} break;} arrSize--; error = false;}else{error = true;}}



#define ARRAY_PULL_PTR_WITH_TEMP_PTR_VOID(objType, arr, arrSize) {if(arrSize > 0){if(arrSize > 1){arrSize--; objType** newElements = new objType*[arrSize]; objType** newTempElement = newElements; for(uint i = 0; i < arrSize; i++, arr++, newTempElement++) SET_PTR_NDO((*newTempElement), (*arr)); SET_PTR_DO((*arr), nullptr); arr-= arrSize; SET_PTR_DOA(arr, newElements);}else{SET_PTR_DO((*arr), nullptr); SET_PTR_DOA(arr, nullptr); arrSize--;} return true;}else{ return false;}}
#define ARRAY_PULL_PTR_WITH_TEMP_PTR(objType, arr, arrSize) {objType* ret = nullptr; if(arrSize > 0){if(arrSize > 1){arrSize--; objType** newElements = new objType*[arrSize]; objType** newTempElement = newElements; for(uint i = 0; i < arrSize; i++, arr++, newTempElement++) SET_PTR_NDO((*newTempElement), (*arr)); ret = (*(arr)); arr-= arrSize; SET_PTR_DOA(arr, newElements);}else{ret = (*(arr)); SET_PTR_DOA(arr, nullptr); arrSize--;} return ret;}else{ return nullptr;}}

#endif // MEMORYMENEGEMENTMACROS_HPP
