#ifndef STANDARDCLASSDEFINITIONS_HPP
#define STANDARDCLASSDEFINITIONS_HPP

// Standard Get/Set Definitions
#define GET_DEFINITION(className,retType, retObj)  retType className::get_##retObj(){return retObj;}
#define GET_PTR_DEFINITION(className, retType, retObj) retType className::get_##retObj(){return &retObj;}
#define SET_NDO_DEFINITION(className,objType, obj) void className::set_##obj(objType set){obj = set;}
#define GET_SET_NDO_DEFINITION(className, type, obj) type className::get_##obj(){return obj;} void className::set_##obj(type set){obj = set;}

// Standard Get/Set Declarations
#define GET_DECLARATION(retType, retObj) retType get_##retObj();
#define SET_DECLARATION(objType, obj) void set_##obj(objType set);
#define GET_SET_DECLARATION(type, obj) GET_DECLARATION(type, obj) SET_DECLARATION(type, obj)

#endif // STANDARDCLASSDEFINITIONS
