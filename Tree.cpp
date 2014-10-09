///////////////////////////////////////////////////////////////////////////////
///
/// @file Tree.cpp
/// LISP Interpreter - Tree
/// This program deals with
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
#include "string.h"
#include "Tree.h"


Tree::Tree()
{
	size=0;
	header=NULL;
	tail=NULL;
}


Tree::~Tree()
{

}

Nodes* Tree::getNewStruct()
{
	Nodes* r=(Nodes*)malloc(sizeof(Nodes));
	r->prev=NULL;
	r->next=NULL;
	r->content=NULL;

	return r;
}

SExp* Tree::get(int index)
{

	Nodes* r=header;
	int count=0;
	if(index<0 || size<=index)
		return NULL;

	while(count<index && r!=NULL)
	{
		count++;
		r=r->next;
	}

	if(r!=NULL){}
	else
		return NULL;

	return r->content;
}

int Tree::appendHeader(SExp* s)
{

	Nodes* r=getNewStruct();
	r->content=s;

	if(header!=NULL)
	{header->prev=r;
	r->next=header;
	header=r;}

	else
	{
		header=tail=r;
	}

	++size;

	return size;
}

int Tree::append(SExp* s)
{

	Nodes* N=getNewStruct();
	N->content=s;

	if(header!=NULL){

		tail->next=N;
		N->prev=tail;
		tail=N;
	}
	else
	{	header=tail=N;	}

	++size;

	return size;
}

SExp* Tree::removeHeader()
{
	if(header==NULL)
		return NULL;

	SExp* S=header->content;

	header=header->next;

	if(header!=NULL){
		//Do nothing
	}else
		header=tail=NULL;

	--size;

	return S;
}

int Tree::getSize()
{
	return size;
}
