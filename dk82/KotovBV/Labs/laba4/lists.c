#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include "lists.h"
#include <string.h>


List* createList()
{
	List* theList = (List*)malloc(sizeof(List));
	 
	if (theList != NULL)
	{
		theList->count = 0;
		theList->first = NULL;
		theList->last = NULL;
	}
    
	return theList;
}

Node* createNode(char* arr)
{
	if (NULL == arr)
		return NULL;

	Node* theNode = (Node*)malloc(sizeof(Node));
	if (theNode != NULL)
	{
		theNode->arr = arr;
		theNode->next = NULL;
		theNode->prev = NULL;
	}
	return theNode;
}

void destroyList(List* aList)
{
	if (aList == NULL)
		return;
	Node* theNode = aList->first;
	while (theNode!=NULL)
	{
		Node* toRemove = theNode;
		theNode = theNode->next;
		free(toRemove);
	}
	free(aList);
}


void addLineToList(List* thelist, char* arr)
{
	if (thelist != NULL)
	{
		Node* theNode = createNode(arr);

		if (theNode != NULL)
		{

			if (thelist->first == NULL && thelist->first == thelist->last)
			{
				thelist->first = thelist->last = theNode;
			}
			else
			{
				Node* thelast = thelist->last;
				thelist->last = theNode;
				thelast->next = theNode;
				theNode->prev = thelast;
			}

			thelist->count++;
		}

	}
}

Node *findAtIndex(List *aList, int anIndex)
{
	Node* theResult = NULL;
	if (aList == NULL || anIndex>=aList->count)
		return theResult;
	Node* theNode = aList->first;
	int i = 0;

	do
	{
		if (i == anIndex)
		{
			theResult = theNode;
			break;
		}
		i++;
		theNode = theNode->next;
	} while (theNode!=NULL);

	return theResult;
}

void swap(List* thelist,int theLeft,int theRight)
{
	if (theLeft == theRight) return;

	Node * theNode_l = findAtIndex(thelist, theLeft);
	Node * theNode_r = findAtIndex(thelist, theRight);
	Node * theNode_rNext = findAtIndex(thelist, theRight)->next;

	if (theLeft == 0)
	{
		thelist->first = theNode_r;
		thelist->first->next = theNode_l->next;
	}
	else
	{
		findAtIndex(thelist, theLeft - 1)->next = theNode_r;
		findAtIndex(thelist, theLeft - 1)->next->next = theNode_l->next;
	}

	findAtIndex(thelist, theRight - 1)->next = theNode_l;
	findAtIndex(thelist, theRight - 1)->next->next = theNode_rNext;

	if (theRight + 1 == thelist->count)
	{
		thelist->last = findAtIndex(thelist, theRight);
	}
}