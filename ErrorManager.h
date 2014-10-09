#ifndef __ERRORMANAGER_H_
#define __ERRORMANAGER_H_

///////////////////////////////////////////////////////////////////////////////
/// @file ErrorManager.h
/// @n ErrorManager.h includes the blueprint of the class ErrorManager which
/// is the driver to error control
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class ErrorManager{
public:
	typedef enum ErrorCode {
			SUCCESSFUL			= 0,
			RESERVED			= 1,
			V1_NOT_ATOMIC		= 2,
			CANT_FIND_MATCH		= 3,
			P1_VALUE_NULL		= 4,
			P2_VALUE_NULL		= 5,
			CAR_NULL			= 6,
			CDR_NULL			= 7,
			F_VALUE_NULL		= 8,
			STRING_POS_INVALID	= 9,
			CAR_ATOMIC			= 10,
			CDR_ATOMIC			= 11,
			EQ_NON_ATOMIC		= 12,
			REDEFINED_FUNC		= 13,
			UNDEFINED_FUNC		= 14,
			UNBOUNDED_VARIABLE	= 15,
			DEFUN_NOT_TOP		= 16,
			ARGUMENT_NO_MATCH	= 17,
			DIVISION_BY_ZERO	= 18,
			ERROR_COND			= 19,
			USER_ARG_NO_MATCH	= 20,
			SYNTAX_ERROR		= 21,
			EMPTY_STRING		= 22,
			NON_ATOMIC_FUNC		= 23,
			NOT_LIST			= 24,
			MISMATCH_PAREN		= 25,
			MATH_NON_INT		= 26

	}ERRORCODE;

public:
	void buildErrors(ErrorCode);
	void buildRunTimeErrors(ErrorCode,char*);

	ErrorManager(){}
	 ~ErrorManager(){}

};




#endif /* ERRORMANAGER_H_ */
