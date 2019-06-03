#pragma once
typedef struct intNode Node;

typedef struct intNode
{
	char* arr;
	Node* prev;
	Node* next;
}Node;

typedef struct intList
{
	int count;
	Node* first;
	Node* last;
}List;


Node* createNode(char* arr);
List* createList();

void destroyList(List* aList);
void addLineToList(List* aList, char* arr);
void swap(List* theList, int theLeft, int theRight);