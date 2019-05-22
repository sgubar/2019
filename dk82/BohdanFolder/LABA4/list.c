#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


List* createList()
{
	List* theList = (List*)malloc(sizeof(List));

	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}

	return theList;
}

Node* createNode(int value)
{
	Node* theNode = (Node*)malloc(sizeof(Node));

	if (NULL != theNode)
	{
		theNode->value = value;
		theNode->next = NULL;
	}

	return theNode;
}

void addNode(List* aList, Node* aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
	{
		return;
	}

	if (NULL == aList->head && aList->head == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		Node* theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->next = aList->tail;
		}
	}

	aList->count += 1;

	return aNewNode;
}


void addElements(List* aList, int i)
{
	if (i < 1)
	{
		printf("Invalid value");
		return;
	}
	
	srand(time(NULL));
	for (i; i > 0; i--)
	{
		addNode(aList, createNode(rand() % 1000));
	}
}

void printList(List* aList)
{
	if (NULL == aList->head)
	{
		return;
    }

	int i = 0;
	Node* theNode = aList->head;

	while (1)
	{
		if (NULL != theNode)
		{
			printf("Node[%d] = %d\n", i+1, theNode->value);
		}
		i++;
		theNode = theNode->next;
		
		if(NULL == theNode->next)
		{
			break;
		}
	}
	printf("\n");
}

int searchMax(List* aList)
{
	Node* theNode = aList->head;

	int max = theNode->value;
	while (NULL != theNode->next)
	{
		if (theNode->next->value > max)
		{
			max = theNode->next->value;
		}
		theNode = theNode->next;
	}
	return max;
}

int countBeforeMax(List* aList, int max)
{
	if (NULL == aList->head)
	{
		return;
	}

	int count = 0;
	Node* theNode = aList->head;

	while (1)
	{
		if (NULL != theNode && theNode->value != max)
		{
			count++;
		}
		else
		{
			return count;
		}
		
		theNode = theNode->next;
	}
}

void bubbleSort(List* aList, int count)
{
	if (NULL != aList)
	{
		if (aList->count <= 1)
		{
			return;
		}

		int temp;
		unsigned int i = 0;
		Node * theNode = aList->head;
		bool isSwaped = true;

		while (isSwaped)
		{
			isSwaped = false;
			theNode = aList->head;
			for (i = 0; i < count; ++i)
			{
				if (theNode->value > theNode->next->value)
				{
					temp = theNode->value;
					theNode->value = theNode->next->value;
					theNode->next->value = temp;
					isSwaped = true;
				}
				theNode = theNode->next;
			}
		}

	}
	return;
}

void destroyList(List* aList)
{
	if (NULL == aList)
	{
		return;
	}

	Node* theNode = aList->head;
	while (NULL != theNode)
	{
		Node* toRemove = theNode;
		theNode = theNode->next;
		free(toRemove);
	}

	free(aList);
}