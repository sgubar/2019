#ifndef THENODE_H_INCLUDED
#define THENODE_H_INCLUDED
#include <stdio.h>

typedef struct __IntNode IntNode;

struct __IntNode
{
	int data;
	IntNode *nextNode;
};


IntNode *CreateNode(int adata);
void FreeNode(IntNode *aNode);


#endif // THENODE_H_INCLUDED
