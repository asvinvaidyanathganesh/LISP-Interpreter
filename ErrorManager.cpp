///////////////////////////////////////////////////////////////////////////////
///
/// @file ErrorManager.cpp
/// LISP Interpreter - ErrorManager
/// This program is the driver for error Controls. It captures the error and
/// prints on the screen.
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Header Files
///////////////////////////////////////////////////////////////////////////////
#include "ErrorManager.h"
#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
/// void ErrorManager ::buildErrors(enum ErrorCode E) - Builds Error
///////////////////////////////////////////////////////////////////////////////

void ErrorManager ::buildErrors(enum ErrorCode E){
	switch(E){
	case 2:
		cout<<"\n ERROR: V1 is not atomic ";
		break;
	case 3:
		cout<<"\n ERROR: Unable to find matches ";
		break;
	case 4:
		cout<<"\n ERROR: P1 value is NULL ";
		break;
	case 5:
		cout<<"\n ERROR: P2 value is NULL ";
		break;
	case 6:
		cout<<"\n ERROR: S.CAR is NULL ";
		break;
	case 7:
		cout<<"\n ERROR: S.CDR is NULL ";
		break;
	case 8:
		cout<<"\n ERROR: f.value is NULL ";
		break;
	case 9:
		cout<<"\n ERROR: '(' Expected ";
		break;
	case 10:
		cout<<"\n ERROR: CAR cannot be applied to atomic S-Expression ";
		break;
	case 11:
		cout<<"\n ERROR: CDR cannot be applied to atomic S-Expression ";
		break;
	case 12:
		cout<<"\n ERROR: EQ cannot be applied to non-atomic S-Expression ";
		break;
	case 13:
		cout<<"\n ERROR: Redefined Function ";
		break;
	case 14:
		cout<<"\n ERROR: Undefined Function ";
		break;
	case 15:
		cout<<"\n ERROR: Expression Unbound ";
		break;
	case 16:
		cout<<"\n ERROR: DEFUN is not at the Top ";
		break;
	case 17:
		cout<<"\n ERROR: Arguments Mismatch ";
		break;
	case 18:
		cout<<"\n ERROR: Divide By 0 Exception ";
		break;
	case 19:
		cout<<"\n ERROR: Syntax Error in COND ";
		break;
	case 20:
		cout<<"\n ERROR: Arguments Mismatch ";
		break;
	case 21:
		cout<<"\n ERROR: Syntax Error ";
		break;
	case 22:
		cout<<"\n ERROR: Empty String ";
		break;
	case 23:
		cout<<"\n ERROR: Function Name non-Atomic ";
		break;
	case 24:
		cout<<"\n ERROR: Not a list ";
		break;
	case 25:
		cout<< "\n ERROR: Mismatch in Parenthesis ";
		break;
	case 26:
		cout<<"\n ERROR: Cannot apply this function to non-integers ";
		break;

	default:
		break;
	}
	//Bye Bye
	exit(0);
}
///////////////////////////////////////////////////////////////////////////////
/// void ErrorManager ::buildRunTimeErrors() - Builds Error with Runtime val
///////////////////////////////////////////////////////////////////////////////

void ErrorManager ::buildRunTimeErrors(enum ErrorCode E, char* err){
	switch(E){
	case 2:
		cout<<"\n ERROR: V1 is not atomic ";
		break;
	case 3:
		cout<<"\n ERROR: Unable to find matches ";
		break;
	case 4:
		cout<<"\n ERROR: P1 value is NULL ";
		break;
	case 5:
		cout<<"\n ERROR: P2 value is NULL ";
		break;
	case 6:
		cout<<"\n ERROR: S.CAR is NULL ";
		break;
	case 7:
		cout<<"\n ERROR: S.CDR is NULL ";
		break;
	case 8:
		cout<<"\n ERROR: f.value is NULL ";
		break;
	case 9:
		cout<<"\n ERROR: '(' Expected ";
		break;
	case 10:
		cout<<"\n ERROR: CAR cannot be applied to atomic S-Expression ";
		break;
	case 11:
		cout<<"\n ERROR: CDR cannot be applied to atomic S-Expression ";
		break;
	case 12:
		cout<<"\n ERROR: EQ cannot be applied to non-atomic S-Expression ";
		break;
	case 13:
		cout<<"\n ERROR: Redefined Function ";
		break;
	case 14:
		cout<<"\n ERROR: Undefined Function ";
		break;
	case 15:
		cout<<"\n ERROR: Expression Unbound ";
		break;
	case 16:
		cout<<"\n ERROR: DEFUN is not at the Top ";
		break;
	case 17:
		cout<<"\n ERROR: Arguments Mismatch ";
		break;
	case 18:
		cout<<"\n ERROR: Divide By 0 Exception ";
		break;
	case 19:
		cout<<"\n ERROR: Syntax Error in COND ";
		break;
	case 20:
		cout<<"\n ERROR: Arguments Mismatch ";
		break;
	case 21:
		cout<<"\n ERROR: Syntax Error ";
		break;
	case 22:
		cout<<"\n ERROR: Empty String ";
		break;
	case 23:
		cout<<"\n ERROR: Function Name non-Atomic ";
		break;
	case 24:
		cout<<"\n ERROR: Not a list ";
		break;
	case 25:
		cout<< "\n ERROR: Mismatch in Parenthesis ";
		break;
	case 26:
		cout<<"\n ERROR: Cannot apply this function to non-integers ";
		break;

	default:
		break;
	}
	printf("%s\n",err);
	//Bye Bye
	exit(0);
}
