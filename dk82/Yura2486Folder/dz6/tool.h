#ifndef tool_h
#define tool_h
#include <stdio.h>

// The node declaration
typedef struct tagIntNode
{
	int value;
	struct tagIntNode *nextNode;
}intNode;

typedef struct tagIntList
{
	intNode *head;
	intNode *tail;
	int count;
}intList;

extern const int kSLListError;

//Interface
//Create/delete a list
intList *createList();
void freeList(intList *aList);
void freeIntNode(intNode *aNode);
void quickSort(intList *aList, int aLeftIndex, int aRightIndex);
void swapNodesByIndex(intList *aList, int aLeftIndex, int aRightIndex);
void printList(const intList *aList);

int countList(const intList *aList);
int partitionIt(intList *aList, int aLeftIndex, int aRightIndex, int aPivot);

intNode *nodeAtIndex(const intList *aList, int aIndex);
intNode *insertNodeAtIndex(intList *aList, intNode *aNewNode, int anIndex);
intNode *removedNodeAtIndex(intList *aList, int anIndex);
intNode *addNode(intList *aList, intNode *aNewNode);
intNode *createNodeWithIntValue(int aValue);

#endif
