///////////////////////////////////////////////////////////////////////////////
///
/// @file Interpreter.cpp
/// LISP Interpreter - Interpreter
/// This program is the driver program of this LISP Interpreter.
/// This program handles the Input and Output operations with the console
/// and calls Parser and Eval.
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Header Files
///////////////////////////////////////////////////////////////////////////////

#include "Interpreter.h"
#include "Parser.h"
#include "Eval.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// Interpreter::scanUntil() - Scans Token till EOF is reached
///////////////////////////////////////////////////////////////////////////////

int Interpreter::scanUntil(char* inp)
{
	size = strlen(inp);
	index = -1;
	// Convert to UpperCase Characters
	for(int i=0;i<size;i++){
			if (inp[i] >= 'a' && inp[i]<= 'z')
				inp[i] = ('A' + inp[i] - 'a');
	}

	for( int i=0;i<size;i++)
	{

		if (inp[i]=='E' && inp[i+1]=='O' && inp[i+2]=='F'){
			index = 1;
		}
	}
	return index;
}
///////////////////////////////////////////////////////////////////////////////
/// Interpreter::main() - The main driver function
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	Parser P;
	Eval E;

	char input[1000];
	char current[1000];
	char alter[1000];


	Tree* dList=new Tree();

	cout<<"\n LISP INTERPRETER\n";
	cout<<"To terminate a particular input, please type EOF at the end\n";

	memset(input,0,1000);

	fgets(input, 1000, stdin);
	Interpreter I;

	// Read input till the last parenthesis.
	while(I.scanUntil(input)<0)
	{
		// memcpy and memset for faster performances.
		memcpy(current,input,1000);
		memset(alter,0,1000);
		memset(input,0,1000);

		fgets(alter, 1000, stdin);
		sprintf(input,"%s\n%s",current,alter);
	}

	// Convert to UpperCase Characters
	for(unsigned int i=0;i<strlen(input);i++){
		if (input[i] >= 'a' && input[i]<= 'z')
			input[i] = ('A' + input[i] - 'a');
	}
	Tree* T = P.parse(input,strlen(input));
	if(T==NULL)
	{
	}
	else
	{
		for (int i=0;i<T->getSize();i++)
		{
			SExp* aList = new SExp(0);
			SExp* Sin = T->get(i);
			E.def=0;
			SExp* Sout=E.eval(Sin,aList,dList);
			if(Sout!=NULL && E.def==0)
			{
				memset(alter,0,1000);
				Sout->convertStringList(alter);
				printf("%s\n",alter);
			}
		}
	}

	return 0;
}
