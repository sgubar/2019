#pragma once
typedef struct intNode Node;

typedef struct intNode
{
	int arr;
	Node* prev;
	Node* next;
}Node;

typedef struct intList
{
	int count;
	Node* first;
	Node* last;
}List;


Node* createNode(int arr);
List* createList();

void destroyList(List* aList);
void addLineToList(List* aList, int arr);
void swap(List* theList, int theLeft, int theRight);
void SLRemovedNodeAtIndex(List* aList, double aver);
void destroyNode(Node* aNode);