#ifndef THELIST_H_INCLUDED
#define THELIST_H_INCLUDED
#include <stdio.h>

typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int acount;
}IntList;

extern const int ListError;


IntList *CreateList();
void FreeList(IntList *aList);

IntNode *AddNode(IntList *aList, IntNode *aNewNode);

int CountList(const IntList *aList);
IntNode *NodeAtIndex(const IntList *aList, int aIndex);
void doPrintList(const IntList *aList);

IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex);

int FindtheSameNodeIndex(IntList *aList);
void SwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex);


#endif // THELIST_H_INCLUDED
