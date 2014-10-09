#ifndef INTERPRETER_H_
#define INTERPRETER_H_

///////////////////////////////////////////////////////////////////////////////
/// @file Interpreter.h
/// @n Interpreter.h includes the blueprint of the class Interpreter which
/// is the driver to this LISP Interpreter
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////


class Interpreter{
	int index;
	int size;
public:
	Interpreter(){}
	~Interpreter(){}
	int scanUntil( char* );
};

#endif /* INTERPRETER_H_ */
