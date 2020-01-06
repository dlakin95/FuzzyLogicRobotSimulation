#ifndef DATABASEMENEGMENTMACROS_HPP
#define DATABASEMENEGMENTMACROS_HPP

#define DB_GET_SUPER_CLASS_NUMB_OF_PARAMS(objType) objType::getSuperClassNumbOfParameters_priv()
#define DB_GET_SUPER_CLASS_NUMB_OF_TYPES(objType) objType::getSuperClassNumbOfTypes()

#define DB_SET_PARAM_ID(objType) if(DB_OBJECT_MACRO_ACCESS_PARAM_ID_REQUIRED(objType) && setParamId) (*static_cast<DataBaseObject**>(value))->setParamId(DB_GET_SUPER_CLASS_NUMB_OF_PARAMS(objType) + paramRules.param);

#define DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN_DB_PROCESSING(objType, paramEnum, value,dbObjContainer) {if(dbObjContainer->getLastObject()) {spr.param = objType::getRealParam(paramEnum); dbObjContainer->getLastObject()->lastReadedParam = spr.param;} else {return NUMB_OF_DATABASE_FILE_OPERATIONS;} if(!setParam(value, spr)) return NUMB_OF_DATABASE_FILE_OPERATIONS; return DATABASE_FILE_OPERATION_DB_PROCESSING;}
#define DB_OBJECT_CHECK_PARAM_AND_PROCCESS_ASSIGN_VALUE_RETURN(objType, paramEnum, value,dbObjContainer, returnValue) {if(dbObjContainer->getLastObject()) {spr.param = objType::getRealParam(paramEnum); dbObjContainer->getLastObject()->lastReadedParam = spr.param;} else {return NUMB_OF_DATABASE_FILE_OPERATIONS;} if(!setParam(value, spr)) return NUMB_OF_DATABASE_FILE_OPERATIONS; return returnValue;}

#define DB_OBJECT_GET_PARAM_VOID_PTR(ptr, castType, paramObj) {*static_cast<castType*>(ptr) = paramObj;}
#define DB_OBJECT_SET_PARAM_VOID_PTR(ptr, castType, paramObj) {paramObj = *static_cast<castType*>(ptr); ret = true;}
#define DB_OBJECT_SET_PARAM_NOT_ASSIGN_VOID_PTR(ptr, castType, operation) {operation(*static_cast<castType*>(ptr)); ret = true;}

#define DB_OBJECT_GET_PARAM_ENUM_CALL_BASE(paramRules, objType, baseObjType) {if(paramRules.param < objType::getSuperClassNumbOfParameters_priv())   return baseObjType::getParam(paramRules);   else    paramRules.param -= objType::getSuperClassNumbOfParameters_priv();}
#define DB_OBJECT_GET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, objType, baseObjType) {if(paramRules.param < objType::getSuperClassNumbOfParameters_priv())  return baseObjType::getParam(value, paramRules); else    paramRules.param -= objType::getSuperClassNumbOfParameters_priv();}
#define DB_OBJECT_SET_PARAM_VOID_PTR_CALL_BASE(paramRules, value, objType, baseObjType) {if(paramRules.param < objType::getSuperClassNumbOfParameters_priv())  return baseObjType::setParam(value, paramRules); else    paramRules.param -= objType::getSuperClassNumbOfParameters_priv();}
#define DB_OBJECT_SET_PARAM_STR_CALL_BASE(paramRules, value, objType, baseObjType) {if(paramRules.param < objType::getSuperClassNumbOfParameters_priv())  return baseObjType::setParam(value, paramRules); else    paramRules.param -= objType::getSuperClassNumbOfParameters_priv();}
#define DB_OBJECT_COMPARE_PARAMS_CALL_BASE(paramRules, value, objType, baseObjType) {if(paramRules.param < objType::getSuperClassNumbOfParameters_priv())  return baseObjType::compareParams(value, paramRules); else    paramRules.param -= objType::getSuperClassNumbOfParameters_priv();}

#define DB_OBJECT_CREATE_OBJECT_CALL_BASE(obj, objType, baseObjType) {if(newType < objType::getSuperClassNumbOfTypes())  return baseObjType::createObject(obj, newType); else    newType -= objType::getSuperClassNumbOfTypes();}

#define DB_OBJECT_IS_PARAM_OPTIONAL_CALL_BASE(param, objType, baseObjType) {if(param < objType::getSuperClassNumbOfParameters()) return baseObjType::isParamOptional(param); else param -= getSuperClassNumbOfParameters_priv(); return (*(objType::optionality + param));}
#define DB_OBJECT_IS_PARAM_OBJECT_CALL_BASE(param, objType, baseObjType) {if(param < objType::getSuperClassNumbOfParameters()) return baseObjType::isParamObject(param); else param -= getSuperClassNumbOfParameters_priv(); return (*(objType::paramIsObject + param));}
#define DB_OBJECT_GET_PARAM_NAME_CALL_BASE(param, objType, baseObjType) {if(param < objType::getSuperClassNumbOfParameters()) return baseObjType::getParamName(param); else param -= getSuperClassNumbOfParameters_priv();}

#define DB_OBJECT_GET_PARAM_ID_BY_TYPE_BASE_FUNC(type, objType) {if(type < (objType::startType - 1)) return UINT_MAX; type -= objType::startType; return (*(objType::paramForTypes + type));}
#define DB_OBJECT_GET_PARAM_ID_BY_TYPE_CALL_BASE(type, objType, baseObjType) {if(type < objType::getSuperClassNumbOfTypes()) return baseObjType::getParamIdByType(type); else type -= objType::getSuperClassNumbOfTypes(); return (*(objType::));}

#define DB_CREATE_OBJECT_VOID_PTR_CALL_BASE(type, obj, curDbType, baseDbType) {if(type < (curDbType::getSuperClassNumbOfTypes()))   return baseDbType::createObject(obj); else    type -= curDbType::getSuperClassNumbOfTypes();}
//#define DB_CREATE_PARAM_OBJECT_

#define DB_GET_REAL_PARAM(objType, param) objType::getRealParam(param)
#define DB_GET_REAL_TYPE(objType, type) objType::getRealType(type)

#define DB_GET_PARAM_NAME(paramName) case paramName: return DB_OBJECT_MACRO_ACCESS_NAME(paramName);

#define DB_FILE_READ_ERROR(setError) error = setError;  dataBaseReaded = true; continue;
#define DB_READ_ERROR(setError) error = static_cast<DataBaseError>(NUMB_OF_FILE_READ_ERRORS + setError); dataBaseReaded = true; continue;

#define DB_OBJECT_IS_INITIALIZED_BOOL(objType) if(!initializedParameters || (paramRules.initialized = (*(initializedParameters + objType::getSuperClassNumbOfParameters_priv() + paramRules.param))) == false)  return false;
#define DB_OBJECT_IS_INITIALIZED_QSTRING(objType) if(!initializedParameters || (paramRules.initialized = (*(initializedParameters + objType::getSuperClassNumbOfParameters_priv() + paramRules.param))) == false)  return QString();

// Methods Definitions

// Parameters
#define DB_OBJECT_BASE_CLASS_METHOD_GET_REAL_PARAM(parameterEnumName) static inline constexpr uint getRealParam(parameterEnumName param){return param;}
#define DB_OBJECT_BASE_CLASS_METHOD_GET_NUMB_OF_PARAMETERS virtual inline uint getNumbOfParameters(){return getNumbOfParameters_priv();}
#define DB_OBJECT_BASE_CLASS_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS virtual inline uint getSuperClassNumbOfParameters(){return getSuperClassNumbOfParameters_priv();}
#define DB_OBJECT_BASE_CLASS_METHOD_GET_NUMB_OF_PARAMETERS_PRIVATE(curClassNumbOfParameters) protected: constexpr inline uint getNumbOfParameters_priv(){return curClassNumbOfParameters + getSuperClassNumbOfParameters_priv();} public:
#define DB_OBJECT_BASE_CLASS_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS_PRIVATE protected: constexpr inline uint getSuperClassNumbOfParameters_priv(){return 0;} public:

#define DB_OBJECT_METHOD_GET_REAL_PARAM(curClassParameterEnumName, superClassName, superClassNumbOfParameters) static inline constexpr uint getRealParam(curClassParameterEnumName param){return param + superClassName::getRealParam(superClassNumbOfParameters);}
#define DB_OBJECT_METHOD_GET_NUMB_OF_PARAMETERS_PRIVATE(curClassNumbOfParameters, curClassName) protected: constexpr inline uint getNumbOfParameters_priv(){return curClassNumbOfParameters + curClassName::getSuperClassNumbOfParameters_priv();} public:
#define DB_OBJECT_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS_PRIVATE(superClassName) protected: constexpr inline uint getSuperClassNumbOfParameters_priv(){return superClassName::getNumbOfParameters_priv();} public:
#define DB_OBJECT_METHOD_GET_NUMB_OF_PARAMETERS virtual inline uint getNumbOfParameters(){return getNumbOfParameters_priv();}
#define DB_OBJECT_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS virtual inline uint getSuperClassNumbOfParameters(){return getSuperClassNumbOfParameters_priv();}

#define DB_OBJECT_BASE_CLASS_PARAMETERS_MENEGMENT_DEFINITIONS( curClassParameterEnumName, curClassNumbOfParameters)      DB_OBJECT_BASE_CLASS_METHOD_GET_REAL_PARAM(curClassParameterEnumName) \
                                                                                                                        DB_OBJECT_BASE_CLASS_METHOD_GET_NUMB_OF_PARAMETERS    \
                                                                                                                        DB_OBJECT_BASE_CLASS_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS \
                                                                                                                        DB_OBJECT_BASE_CLASS_METHOD_GET_NUMB_OF_PARAMETERS_PRIVATE(curClassNumbOfParameters) \
                                                                                                                        DB_OBJECT_BASE_CLASS_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS_PRIVATE

#define DB_OBJECT_PARAMETERS_MENEGMENT_DEFINITIONS(curClassName, superClassName, curClassParameterEnumName, curClassNumbOfParameters,  superClassNumbOfParameters)              DB_OBJECT_METHOD_GET_REAL_PARAM(curClassParameterEnumName, superClassName, superClassNumbOfParameters) \
                                                                                                                                                                                DB_OBJECT_METHOD_GET_NUMB_OF_PARAMETERS    \
                                                                                                                                                                                DB_OBJECT_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS \
                                                                                                                                                                                DB_OBJECT_METHOD_GET_NUMB_OF_PARAMETERS_PRIVATE(curClassNumbOfParameters, curClassName) \
                                                                                                                                                                                DB_OBJECT_METHOD_GET_SUPER_CLASS_NUMB_OF_PARAMETERS_PRIVATE(superClassName)
// Types
#define DB_OBJECT_BASE_CLASS_METHOD_GET_REAL_TYPE(curClassTypeEnumName) static inline constexpr uint getRealType(curClassTypeEnumName type){return type;}
#define DB_OBJECT_BASE_CLASS_METHOD_GET_NUMB_OF_TYPES(curClassNumbOfTypes) virtual inline uint getNumbOfTypes(){return curClassNumbOfTypes;}
#define DB_OBJECT_BASE_CLASS_METHOD_GET_SUPER_CLASS_NUMB_OF_TYPES virtual inline uint getSuperClassNumbOfTypes(){return 0;}
#define DB_OBJECT_METHOD_GET_REAL_TYPE(curClassTypeEnumName, superClassName, superClassNumbOfTypes) static inline constexpr uint getRealType(curClassTypeEnumName type){return type + superClassName::getRealType(superClassNumbOfTypes);}
#define DB_OBJECT_METHOD_GET_NUMB_OF_TYPES(curClassNumbOfTypes, curClassName) virtual inline uint getNumbOfTypes()override{return curClassNumbOfTypes + DB_GET_SUPER_CLASS_NUMB_OF_TYPES(curClassName);}
#define DB_OBJECT_METHOD_GET_SUPER_CLASS_NUMB_OF_TYPES(superClassName) virtual inline uint getSuperClassNumbOfTypes()override{return superClassName::getNumbOfTypes();}


#define DB_OBJECT_BASE_CLASS_TYPES_MENEGMENT_DEFINITIONS(curClassTypeEnumName, curClassNumbOfTypes)         DB_OBJECT_BASE_CLASS_METHOD_GET_REAL_TYPE(curClassTypeEnumName) \
                                                                                                            DB_OBJECT_BASE_CLASS_METHOD_GET_NUMB_OF_TYPES(curClassNumbOfTypes)    \
                                                                                                            DB_OBJECT_BASE_CLASS_METHOD_GET_SUPER_CLASS_NUMB_OF_TYPES

#define DB_OBJECT_TYPES_MENEGMENT_DEFINITIONS(curClassName, superClassName, curClassTypeEnumName, curClassNumbOfTypes,  superClassNumbOfTypes)           DB_OBJECT_METHOD_GET_REAL_TYPE(curClassTypeEnumName, superClassName, superClassNumbOfTypes) \
                                                                                                                                                        DB_OBJECT_METHOD_GET_NUMB_OF_TYPES(curClassNumbOfTypes, curClassName)    \
                                                                                                                                                        DB_OBJECT_METHOD_GET_SUPER_CLASS_NUMB_OF_TYPES(superClassName)
// Parameter Informations
#define DB_OBJECT_BASE_CLASS_METHOD_IS_PARAM_OPTIONAL(curClassName) virtual inline bool isParamOptional(uint param){if(param < curClassName::getNumbOfParameters()) return (*(curClassName::optionality + param)); return false;}
#define DB_OBJECT_BASE_CLASS_METHOD_IS_PARAM_OBJECT(curClassName) virtual inline bool isParamObject(uint param){if(param < curClassName::getNumbOfParameters()) return (*(curClassName::paramIsObject + param)); return false;}
#define DB_OBJECT_BASE_CLASS_METHOD_IS_PARAM_INITIALIZED inline bool isParameterInitialized(uint parameter){if(initializedParameters && parameter < getNumbOfParameters()) return (*(initializedParameters + parameter)); return false;}
#define DB_OBJECT_METHOD_IS_PARAM_OPTIONAL(curClassName, superClassName) virtual inline bool isParamOptional(uint param)override{DB_OBJECT_IS_PARAM_OPTIONAL_CALL_BASE(param, curClassName, superClassName);}
#define DB_OBJECT_METHOD_IS_PARAM_OBJECT(curClassName, superClassName) virtual inline bool isParamObject(uint param)override{DB_OBJECT_IS_PARAM_OBJECT_CALL_BASE(param, curClassName, superClassName);}

#define DB_OBJECT_BASE_CLASS_PARAM_INFORMATION_MENEGMENT_DEFINITIONS(curClassName)    DB_OBJECT_BASE_CLASS_METHOD_IS_PARAM_OPTIONAL(curClassName) \
                                                                                       DB_OBJECT_BASE_CLASS_METHOD_IS_PARAM_OBJECT(curClassName) \
                                                                                       DB_OBJECT_BASE_CLASS_METHOD_IS_PARAM_INITIALIZED


#define DB_OBJECT_PARAM_INFORMATION_MENEGMENT_DEFINITIONS(curClassName, superClassName)      DB_OBJECT_METHOD_IS_PARAM_OPTIONAL(curClassName, superClassName) \
                                                                                             DB_OBJECT_METHOD_IS_PARAM_OBJECT(curClassName, superClassName)

// Base Class Standard Parameters Access Declarations
#define DB_OBJECT_BASE_CLASS_GET_PARAM_QSTRING virtual QString getParam(GetParamRules&) override;
#define DB_OBJECT_BASE_CLASS_GET_PARAM_VOID virtual bool getParam(void*, GetParamRules&);
#define DB_OBJECT_BASE_CLASS_SET_PARAM_VOID virtual bool setParam(void*, SetParamRules&);
#define DB_OBJECT_BASE_CLASS_SET_PARAM_QSTRING virtual bool setParam(QString&, SetParamRules&);
#define DB_OBJECT_BASE_CLASS_COMPARE_PARAMS virtual bool compareParams(void*, GetParamRules&);

#define DB_OBJECT_BASE_CLASS_PARAM_ACCESS_DECLARATIONS  DB_OBJECT_BASE_CLASS_GET_PARAM_QSTRING \
                                                        DB_OBJECT_BASE_CLASS_GET_PARAM_VOID \
                                                        DB_OBJECT_BASE_CLASS_SET_PARAM_VOID \
                                                        DB_OBJECT_BASE_CLASS_SET_PARAM_QSTRING \
                                                        DB_OBJECT_BASE_CLASS_COMPARE_PARAMS

// Derived Class Standard Parameters Access Declarations
#define DB_OBJECT_GET_PARAM_QSTRING virtual QString getParam(GetParamRules&)override;
#define DB_OBJECT_GET_PARAM_VOID virtual bool getParam(void*, GetParamRules&)override;
#define DB_OBJECT_SET_PARAM_VOID virtual bool setParam(void*, SetParamRules&)override;
#define DB_OBJECT_SET_PARAM_QSTRING virtual bool setParam(QString&, SetParamRules&)override;
#define DB_OBJECT_COMPARE_PARAMS virtual bool compareParams(void*, GetParamRules&)override;

#define DB_OBJECT_PARAM_ACCESS_DECLARATIONS     DB_OBJECT_GET_PARAM_QSTRING \
                                                DB_OBJECT_GET_PARAM_VOID \
                                                DB_OBJECT_SET_PARAM_VOID \
                                                DB_OBJECT_SET_PARAM_QSTRING \
                                                DB_OBJECT_COMPARE_PARAMS
// Param Name Access
#define DB_OBJECT_PARAM_NAME_ACCESS_METHOD_DECLARATION virtual const QString getParamName(uint param)override;

// DataBaseObject BaseClass Standard Methods Definitions
#define DB_OBJECT_BASE_CLASS_STANDARD_METHODS(curClassName, curClassParameterEnumName, curClassNumbOfParameters, curClassTypeEnumName, curClassNumbOfTypes)       DB_OBJECT_BASE_CLASS_PARAMETERS_MENEGMENT_DEFINITIONS(curClassParameterEnumName, curClassNumbOfParameters) \
                                                                                                                                                    DB_OBJECT_BASE_CLASS_TYPES_MENEGMENT_DEFINITIONS(curClassTypeEnumName, curClassNumbOfTypes) \
                                                                                                                                                    DB_OBJECT_BASE_CLASS_PARAM_ACCESS_DECLARATIONS \
                                                                                                                                                    DB_OBJECT_BASE_CLASS_PARAM_INFORMATION_MENEGMENT_DEFINITIONS(curClassName) \
                                                                                                                                                    DB_OBJECT_PARAM_NAME_ACCESS_METHOD_DECLARATION

#define DB_OBJECT_STANDARD_METHODS(curClassName, superClassName, curClassParameterEnumName, curClassNumbOfParameters,  superClassNumbOfParameters, curClassTypeEnumName, curClassNumbOfTypes,  superClassNumbOfTypes)       DB_OBJECT_PARAMETERS_MENEGMENT_DEFINITIONS(curClassName, superClassName, curClassParameterEnumName, curClassNumbOfParameters,  superClassNumbOfParameters) \
                                                                                                                                                                                                                            DB_OBJECT_TYPES_MENEGMENT_DEFINITIONS(curClassName, superClassName, curClassTypeEnumName, curClassNumbOfTypes,  superClassNumbOfTypes) \
                                                                                                                                                                                                                            DB_OBJECT_PARAM_ACCESS_DECLARATIONS \
                                                                                                                                                                                                                            DB_OBJECT_PARAM_INFORMATION_MENEGMENT_DEFINITIONS(curClassName, superClassName) \
                                                                                                                                                                                                                            DB_OBJECT_PARAM_NAME_ACCESS_METHOD_DECLARATION

#define DB_OBJECT_STANDARD_METHODS_NO_TYPES(curClassName, superClassName, curClassParameterEnumName, curClassNumbOfParameters,  superClassNumbOfParameters)       DB_OBJECT_PARAMETERS_MENEGMENT_DEFINITIONS(curClassName, superClassName, curClassParameterEnumName, curClassNumbOfParameters,  superClassNumbOfParameters) \
                                                                                                                                                                                                                            DB_OBJECT_PARAM_ACCESS_DECLARATIONS \
                                                                                                                                                                                                                            DB_OBJECT_PARAM_INFORMATION_MENEGMENT_DEFINITIONS(curClassName, superClassName) \
                                                                                                                                                                                                                            DB_OBJECT_PARAM_NAME_ACCESS_METHOD_DECLARATION

#endif // DATABASEMENEGMENTMACROS
