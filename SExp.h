
#ifndef __SEXPRESSION_H__
#define __SEXPRESSION_H__

#include "stdlib.h"
#include "string.h"


class SExp
{
public:

	int isAtom;
	int isInt;
	char value[1024];
	int iValue;

	SExp* car;
	SExp* cdr;

	void setValue(char* s);

	int isT();
	int isNIL();
	int isEOF();
	void convertString(char* str);
	void convertStringList(char* str);
	void convertStringList1(char* str);

public:

	SExp(int i);

	SExp()
	{
		isAtom=0;
		isInt = 0;
		memset(value,0,1000);
		car = NULL;
		cdr = NULL;
	}

	~SExp(){}

};

#endif //
