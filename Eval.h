
#ifndef __EVAL_H__
#define __EVAL_H__

///////////////////////////////////////////////////////////////////////////////
/// @file Eval.h
/// @n Eval.h includes the blueprint of the class Eval which
/// evaluates functions in LISP interpreter.
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

#include "Tree.h"

class Eval
{
public:
	int def;


	SExp* cons(SExp* p1, SExp* p2);
	SExp* car(SExp* s);
	SExp* cdr(SExp* s);
	SExp* atom(SExp* s);
	SExp* Int(SExp* s);
	SExp* eq(SExp* p1, SExp* p2);
	SExp* isNull(SExp* s);
	SExp* plus(SExp* p1, SExp* p2);
	SExp* minus(SExp* p1, SExp* p2);
	SExp* times(SExp* p1, SExp* p2);
	SExp* remainder(SExp* p1, SExp* p2);
	SExp* greater(SExp* p1, SExp* p2);
	SExp* less(SExp* p1, SExp* p2);
	SExp* quotient(SExp* p1, SExp* p2);
	int isKeyword(SExp* s);

	SExp* bound(SExp* p1, SExp* p2);
	SExp* getVal(SExp* p1, SExp* p2);

	SExp* getFunc(SExp* p1, Tree* p2);
	SExp* addPairs(SExp* p, SExp* x,SExp* a);
	SExp* eval_list(SExp* l, SExp* a,Tree* d);
	SExp* eval_con(SExp* be, SExp* a,Tree* d);
	SExp* eval(SExp* exp, SExp* a,Tree* d);
	SExp* apply(SExp* f, SExp* x, SExp* a,Tree* d);


public:
	Eval(){def = 0;}
	~Eval(){}

};

#endif
