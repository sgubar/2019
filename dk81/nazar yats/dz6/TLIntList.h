#ifndef TLIntList_h
#define TLIntList_h

#include <stdio.h>

typedef struct __tagIntNode IntNode;

struct __tagIntNode
{
	char value[25];
	IntNode *prev;
	IntNode *next;
};


typedef struct __tagIntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

IntList *TLCreateIntList();
void TLDestroyIntList(IntList *aList);


int TLAddIntValueToList(IntList *aList, char *anIntValue);


void TLPrintList(IntList *aList);

#endif 
