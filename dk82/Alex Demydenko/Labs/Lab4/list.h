#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_h
#define LIST_h



typedef struct tagNode Node;

struct tagNode
{
	int value;
	Node *nextNode;
	Node *prevNode;
};

typedef struct tagList
{
	Node *head;
	Node *tail;
	int count;
}List;



Node *createNode(int aValue);
void destroyNode(Node *aNode);



List *createList();
void destroyList(List *aList);

	//operations
Node *addNode(List *aList, Node *aNewNode);
//Node *insertNodeAtIndex(List *aList, Node *aNewNode, int anIndex);
void destroyNodeAtIndex(List *aList, int anIndex);

	
//int countList(const List *aList);
Node *nodeAtIndex(const List *aList, int aIndex);
//void swapNodes(List *aList, int aLeftIndex, int aRightIndex);

void printList();
void DeleteIndex (List *aList, int anIndex);
#endif
