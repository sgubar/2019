#ifndef list_h
#define list_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode 
{
	int value;
	struct tagNode* next;
	
}Node;

typedef struct tagList
{
	int count;
	Node* head;
	Node* tail;
}List;

List* createList();
Node* createNode(int value);
void destroyList(List* aList);
void addNode(List* aList, Node* aNewNode);
void addElements(List* aList, int i);
void printList(List* aList);
int searchMax(List* aList);
int countBeforeMax(List* aList, int max);
void bubbleSort(List* aList, int count);


#endif
