///////////////////////////////////////////////////////////////////////////////
///
/// @file SExp.cpp
/// LISP Interpreter - SExp
/// This program defines the S-Expression
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Header Files
///////////////////////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "stdio.h"
#include "SExp.h"
#include "Tree.h"



void SExp::setValue(char* s)
{
	memcpy(value,s,strlen(s));
}


SExp::SExp(int a)
{
	memset(value,0,1000);

	if(a==1)
	{
		isAtom=1;
		setValue("T");
	}
	else if(a==0)
	{
		isAtom=1;
		setValue("NIL");
	}

	car = NULL;
	cdr = NULL;
}


int SExp::isT()
{

	if(isAtom==1 && strcmp(value,"T")==0)
		return 1;

	return 0;
}

int SExp::isEOF()
{

	if(isAtom==1 && strcmp(value,"EOF")==0)
		return 1;

	return 0;
}

int SExp::isNIL()
{
	if(isAtom==1 && strcmp(value,"NIL")==0)
		return 1;
	return 0;
}

void SExp::convertString(char* str)
{
	if (isAtom==1)
	{
		memcpy(str,value,strlen(value));
		return;
	}

	char carStr[1000];
	char cdrStr[1000];
	memset(carStr,0,1000);
	memset(cdrStr,0,1000);

	car->convertString(carStr);
	cdr->convertString(cdrStr);

	sprintf(str,"(%s.%s)",carStr,cdrStr);
}

void SExp::convertStringList(char* str)
{
	int i;
	convertStringList1(str);
	int len=strlen(str)-2;

	for(i=0;i<len;i++)
	{
		if(str[i]==' ' && str[i+1]=='(' && str[i+2]==')')
		{
			str[i]='N';
			str[i+1]='I';
			str[i+2]='L';
		}
	}
}

void SExp::convertStringList1(char* str)
{
	if (isNIL()!=1){}
	else
	{
		sprintf(str," ()");
		return;
	}

	if (isAtom!=1)
	{}
	else
	{
		memcpy(str,value,strlen(value));
		return;
	}

	char carStr[1000];
	char cdrStr[1000];
	memset(carStr,0,1000);
	memset(cdrStr,0,1000);

	car->convertStringList1(carStr);
	cdr->convertStringList1(cdrStr);

	if(cdrStr[0]==' ' && cdrStr[1]=='(')
	{
		char* cdr1=cdrStr+2;
		if(strcmp(cdr1,")")!=0){}
		else
		{
			sprintf(str," (%s%s",carStr,cdr1);
			return;
		}

		sprintf(str," (%s %s",carStr,cdr1);
		return;
	}

	sprintf(str,"(%s.%s)",carStr,cdrStr);


	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ' && str[i+1]=='(' && str[i+2]==')')
		{
			str[i]='N';
			str[i+1]='I';
			str[i+2]='L';
		}
	}
}

