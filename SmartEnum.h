#include <string.h> // for strcmp
#include <stdbool.h> // for bool

#define $(class, method) class##_##method

/*
	UTILS MACROS
*/
#define __SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name) enum_name##element_name
#define __SMARTENUM_MACRO_ENTRY_CASE(entry_name) case entry_name:
#define __SMARTENUM_MACRO_ENTRY_COMPARE(element_name) if(!strcmp(#element_name, str_value))

#define __SMARTENUM_MACRO_ENTRY_UNKNOWN_VALUE(enum_name) __##enum_name##_UNKNOWN_VALUE__
/* 
	MACROS FOR SMARTENUMS MACRO ENTRIES (TWO PARAMETERS) 
	PREFIX : __SMARTENUM_MACRO_ENTRY_
*/
#define __SMARTENUM_MACRO_ENTRY_TO_ENUM_ELEMENT(enum_name, element_name, element_value)\
	__SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name) = element_value,
	
#define __SMARTENUM_MACRO_ENTRY_TO_ISVALID_CASE(enum_name, element_name, element_value)\
	__SMARTENUM_MACRO_ENTRY_CASE(__SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name)) return true;

#define __SMARTENUM_MACRO_ENTRY_TO_TOSTRING_CASE(enum_name, element_name, element_value)\
	__SMARTENUM_MACRO_ENTRY_CASE(__SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name)) return #element_name;
	
#define __SMARTENUM_MACRO_ENTRY_TO_ISSTRINGVALID_COMPARE(enum_name, element_name, element_value)\
	 __SMARTENUM_MACRO_ENTRY_COMPARE(element_name) return true;

#define __SMARTENUM_MACRO_ENTRY_TO_FROMSTRING_COMPARE(enum_name, element_name, element_value)\
	 __SMARTENUM_MACRO_ENTRY_COMPARE(element_name) return __SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name);
	 
#define __SMARTENUM_MACRO_ENTRY_TO_SIZE_COUNT(enum_name, element_name, element_value)\
	+ 1

#define __SMARTENUM_MACRO_ENTRY_TO_TABLE_ENTRY(enum_name, element_name, element_value)\
	__SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name),
	
#define __SMARTENUM_MACRO_ENTRY_TO_FIRST_RETURN(enum_name, element_name, element_value)\
	return __SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name);

#define __SMARTENUM_MACRO_ENTRY_TO_LAST_ASSIGNMENT(enum_name, element_name, element_value)\
	last = __SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name);

#define __SMARTENUM_MACRO_ENTRY_TO_MIN_COMPARE(enum_name, element_name, element_value)\
	if(__SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name) < min) min = __SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name);

#define __SMARTENUM_MACRO_ENTRY_TO_MAX_COMPARE(enum_name, element_name, element_value)\
	if(__SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name) > max) max = __SMARTENUM_MACRO_ENTRY_NAME(enum_name, element_name);

/* MACROS FOR SMARTENUMS MACRO ENTRIES (END) */



/* MACRO FOR ENUM DECLARATION */
#define __SMARTENUM_DECLARE_ENUM(MACRO_DEFINITION, enum_name)\
typedef enum enum_name\
{\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_ENUM_ELEMENT, enum_name)\
	__SMARTENUM_MACRO_ENTRY_UNKNOWN_VALUE(enum_name)\
}\
enum_name;
/* MACRO FOR ENUM DECLARATION (END) */



/* 
	MACRO FOR SMARTENUMS FUNCTIONS 
	PREFIX : __SMARTENUM_FUNCTION_
*/
// MACRO for function declaration (just add ; after function)
#define __SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION, enum_name) __SMARTENUM_FUNCTION(enum_name);

#define __SMARTENUM_FUNCTION_ISVALID(enum_name)\
bool $(enum_name, isValid)(enum_name value)

#define __SMARTENUM_FUNCTION_TOSTRING(enum_name)\
const char* $(enum_name, toString)(enum_name value)

#define __SMARTENUM_FUNCTION_ISSTRINGVALID(enum_name)\
bool $(enum_name, isStringValid)(const char* str_value)

#define __SMARTENUM_FUNCTION_FROMSTRING(enum_name)\
enum_name $(enum_name, fromString)(const char* str_value)

#define __SMARTENUM_FUNCTION_SIZE(enum_name)\
size_t $(enum_name, size)()

#define __SMARTENUM_FUNCTION_NAME(enum_name)\
const char* $(enum_name, name)()

#define __SMARTENUM_FUNCTION_AT(enum_name)\
enum_name $(enum_name, at)(size_t index)

#define __SMARTENUM_FUNCTION_FIRST(enum_name)\
enum_name $(enum_name, first)()

#define __SMARTENUM_FUNCTION_LAST_PRIVATE(enum_name)\
enum_name $(enum_name, last_private)()
#define __SMARTENUM_FUNCTION_LAST(enum_name)\
enum_name $(enum_name, last)()

#define __SMARTENUM_FUNCTION_MIN_PRIVATE(enum_name)\
enum_name $(enum_name, min_private)()
#define __SMARTENUM_FUNCTION_MIN(enum_name)\
enum_name $(enum_name, min)()

#define __SMARTENUM_FUNCTION_MAX_PRIVATE(enum_name)\
enum_name $(enum_name, max_private)()
#define __SMARTENUM_FUNCTION_MAX(enum_name)\
enum_name $(enum_name, max)()
/* MACRO FOR SMARTENUMS FUNCTIONS (END) */



/* 
	MACRO FOR SMARTENUMS FUNCTIONS DEFINITIONS 
	PREFIX : __SMARTENUM_DEFINE_FUNCTION_
*/
#define __SMARTENUM_DEFINE_FUNCTION_ISVALID(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_ISVALID(enum_name)\
{\
	switch(value)\
	{\
		MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_ISVALID_CASE, enum_name)\
		default: return false;\
	}\
}

#define __SMARTENUM_DEFINE_FUNCTION_TOSTRING(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_TOSTRING(enum_name)\
{\
	switch(value)\
	{\
		MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_TOSTRING_CASE, enum_name)\
		default: return 0;\
	}\
}

#define __SMARTENUM_DEFINE_FUNCTION_ISSTRINGVALID(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_ISSTRINGVALID(enum_name)\
{\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_ISSTRINGVALID_COMPARE, enum_name)\
	return false;\
}

#define __SMARTENUM_DEFINE_FUNCTION_FROMSTRING(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_FROMSTRING(enum_name)\
{\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_FROMSTRING_COMPARE, enum_name)\
	return __SMARTENUM_MACRO_ENTRY_UNKNOWN_VALUE(enum_name);\
}

#define __SMARTENUM_DEFINE_FUNCTION_SIZE(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_SIZE(enum_name)\
{\
	static const size_t size = 0 MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_SIZE_COUNT, enum_name);\
	return size;\
}

#define __SMARTENUM_DEFINE_FUNCTION_NAME(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_NAME(enum_name)\
{\
	return #enum_name;\
}

#define __SMARTENUM_DEFINE_FUNCTION_AT(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_AT(enum_name)\
{\
	static const enum_name indexed_values[] = \
	{\
		MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_TABLE_ENTRY, enum_name)\
	};\
	static const size_t sizeof_indexed_values = sizeof(indexed_values)/sizeof(enum_name);\
	if(index < sizeof_indexed_values)\
	{\
		return indexed_values[index];\
	}\
	return __SMARTENUM_MACRO_ENTRY_UNKNOWN_VALUE(enum_name);\
}

#define __SMARTENUM_DEFINE_FUNCTION_FIRST(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_FIRST(enum_name)\
{\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_FIRST_RETURN, enum_name);\
}

#define __SMARTENUM_DEFINE_FUNCTION_LAST(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_LAST_PRIVATE(enum_name)\
{\
	enum_name last;\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_LAST_ASSIGNMENT, enum_name);\
	return last;\
}\
__SMARTENUM_FUNCTION_LAST(enum_name)\
{\
	static enum_name last;\
	static bool initialized = false;\
	if(!initialized)\
	{\
		last = $(enum_name, last_private)();\
		initialized = true;\
	}\
	return last;\
}

#define __SMARTENUM_DEFINE_FUNCTION_MIN(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_MIN_PRIVATE(enum_name)\
{\
	enum_name min = $(enum_name, first)();\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_MIN_COMPARE, enum_name)\
	return min;\
}\
__SMARTENUM_FUNCTION_MIN(enum_name)\
{\
	static enum_name min;\
	static bool initialized = false;\
	if(!initialized)\
	{\
		min = $(enum_name, min_private)();\
		initialized = true;\
	}\
	return min;\
}

#define __SMARTENUM_DEFINE_FUNCTION_MAX(MACRO_DEFINITION, enum_name)\
__SMARTENUM_FUNCTION_MAX_PRIVATE(enum_name)\
{\
	enum_name max;\
	/* initialization to the first element */\
	max = $(enum_name, first)();\
	MACRO_DEFINITION(__SMARTENUM_MACRO_ENTRY_TO_MAX_COMPARE, enum_name)\
	return max;\
}\
__SMARTENUM_FUNCTION_MAX(enum_name)\
{\
	static enum_name max;\
	static bool initialized = false;\
	if(!initialized)\
	{\
		max = $(enum_name, max_private)();\
		initialized = true;\
	}\
	return max;\
}
/* MACRO FOR SMARTENUMS FUNCTIONS DEFINITIONS (END) */


/* SMART ENUM DECLARATION */
#define SMARTENUM_DECLARE(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DECLARE_ENUM(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_ISVALID, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_TOSTRING, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_ISSTRINGVALID, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_FROMSTRING, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_SIZE, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_NAME, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_AT, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_FIRST, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_LAST, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_MIN, enum_name)\
__SMARTENUM_DECLARE_FUNCTION(__SMARTENUM_FUNCTION_MAX, enum_name)
/* SMART ENUM DECLARATION (END) */

/* SMART ENUM DEFINITION */
#define SMARTENUM_DEFINE(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_ISVALID(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_TOSTRING(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_ISSTRINGVALID(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_FROMSTRING(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_SIZE(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_NAME(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_AT(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_FIRST(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_LAST(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_MIN(MACRO_DEFINITION, enum_name)\
__SMARTENUM_DEFINE_FUNCTION_MAX(MACRO_DEFINITION, enum_name)
/* SMART ENUM DEFINITION (END) */
