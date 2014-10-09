#ifndef __PARSER_H__
#define __PARSER_H__

///////////////////////////////////////////////////////////////////////////////
/// @file Parser.h
/// @n Parser.h includes the blueprint of the class Parser which
/// is the function to Parse the input tokens
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "string.h"
#include "Tree.h"

// Forward Declarations
class SExp;
class Tree;

class Parser
{
public:
	int isAlpha(char c);
	int isDigit(char c);
	int isAlphaOrDigit(char c);
	SExp* parseOne(char* str);
	int pairs(char* str, int pos);
	char* getNeighbour(char* str, char* s, int index);
	int getTop(char* str,  int pos, char ch);
	Tree* parseTree(char* str);
	SExp* getSExp(Tree* li);
	int indexOf(char* str,int pos, char c);
	char* removeS(char* str);

public:
	Tree* parse(char* s,int len);

public:
	Parser(){}
	~Parser(){}
};

#endif
