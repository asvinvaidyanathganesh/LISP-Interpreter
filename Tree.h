
#ifndef __TREE_H__
#define __TREE_H__


#include "SExp.h"

typedef struct Nodes{
	SExp* content;
	Nodes* prev;
	Nodes* next;
}Nodes;


class Tree
{
private:
	Nodes* header;
	Nodes* tail;

	Nodes* getNewStruct();

	int size;
public:

	SExp* get(int index);
	int getSize();
	int append(SExp* s);
	int appendHeader(SExp* s);
	SExp* removeHeader();

public:
	Tree();
	virtual ~Tree();

};

#endif
