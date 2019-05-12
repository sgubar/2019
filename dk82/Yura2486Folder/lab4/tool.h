#ifndef tool_h
#define tool_h
#include <stdio.h>

typedef struct tagIntNode
{
	int value;
	struct tagIntNode *nextNode;

}intNode;

typedef struct tagIntList
{
	intNode *head;
	int count;
}intList;

intList *createList();
void freeList(intList *aList);
void freeIntNode(intNode *aNode);
void printList(intList *aList);
void addNElementsInList(intList *aList, int n);
void bubbleSort(intList *aList);

int countList(const intList *aList);
intNode *addNode(intList *aList, intNode *aNewNode);
intNode *createNodeWithIntValue(int aValue);

#endif

