#include <stdio.h>
#include "List.h"
#include <stdlib.h>
#include <limits.h>

DoubleList *CreateDoubleList()
{
	DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));

	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->counter = 0;
	}

	return theList;
}

void DestroyDoubleList(DoubleList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		DoubleNode *theNode = aList->head;

		do
		{
			DoubleNode *theNodeToDelete = theNode;
			theNode = theNode->next;

			free (theNodeToDelete);

		}while (NULL != theNode);

		free(aList);
	}
}

double AddDoubleValueToList(DoubleList *aList, double value)
{
	int theResult = -1;

	if (NULL != aList)
	{
		DoubleNode *theNode = createDoubleNodeWithValue(value);

		if (NULL != theNode)
		{
			if (NULL == aList->head && aList->head == aList->tail)
			{
				aList->head = aList->tail = theNode;
			}
			else
			{

				DoubleNode *theTail = aList->tail;
				aList->tail = theNode;
				theTail->next = theNode;
				theNode->prev = theTail;
			}

			aList->counter ++;
			theResult = 0;
		}
	}

	return theResult;
}

double DoubleValueAtIndex(DoubleList *aList, int anIndex)
{
	int theResult = INT_MAX;

	if (NULL == aList || anIndex >= aList->counter)
	{
		return theResult;
	}

	DoubleNode *theNode = aList->head;
	int i = 0;

	do
	{
		if (i == anIndex)
		{
			break;
		}

		theNode = theNode->next;
		i++;

	}while (NULL != theNode);

	return theNode->value;
}


void PrintList(DoubleList *aList)
{
	printf("[List] with count (%d):", aList->counter);
	DoubleNode *theNode = aList->head;

	do
	{
		printf("(%.2f)-> ", theNode->value);
		theNode = theNode->next;

	}while (NULL != theNode);

    printf("NULL\n");
}

int InsertDoubleValueAtIndex(DoubleList *aList, double value, int anIndex)
{
	int theResult = -1;

	if (NULL == aList || anIndex >= aList->counter || anIndex < 0)
	{
		return theResult;
	}

	DoubleNode *theNode = aList->head;
	int i = 0;

	do
	{
		if (i == anIndex)
		{
			break;
		}

		theNode = theNode->next;
		i++;

	}while (NULL != theNode);


	DoubleNode *theNewNode = createDoubleNodeWithValue(value);
	if (NULL == theNewNode)
	{
		return theResult;
	}

	DoubleNode *theBNode = theNode;

	if (NULL != theBNode->prev)
	{
		theBNode->prev->next = theNewNode;
		theNewNode->prev = theBNode->prev;
	}

	theNewNode->next = theBNode;
	theBNode->prev = theNewNode;

	aList->counter ++;
	theResult = 0;

	return theResult;
}

DoubleNode *createDoubleNodeWithValue(double value)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = value;
	}

	return theNode;
}


int CountList( DoubleList *aList)
{
	int theResult = 0;

	if (NULL != aList)
	{
		theResult = aList->counter;
	}

	return theResult;
}


void SwapNodesByIndex(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return ;

	DoubleNode *theLeftNode = NodeAtIndex(aList, aLeftIndex);
	DoubleNode *theRightNode = NodeAtIndex(aList, aRightIndex);

	double theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}


DoubleNode *NodeAtIndex( DoubleList *aList, int anIndex)
{
	DoubleNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->counter)
	{
		int i = 0;
        DoubleNode *theNode = aList->head;

		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}

			i++; // increase index
			theNode = theNode->next; //<! - go to next node

		} while (NULL != theNode);
	}

	return theResult;
}


int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;

	while (1)
	{

		while (theLeft < aRightIndex && NodeAtIndex(aList, ++theLeft
		)->value < aPivot);

		
		while (theRight > aLeftIndex && NodeAtIndex(aList,--theRight)->value > aPivot);

		if (theLeft >= theRight) 
		{
			break;
		}
		else
		{


			SwapNodesByIndex(aList, theLeft, theRight);
		}
	}

	return theLeft;
}


void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return;
	}

	double thePivot = NodeAtIndex(aList, aRightIndex)->value;
	int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);


	quickSort(aList, aLeftIndex, thePartitionIndex - 1);


	quickSort(aList, thePartitionIndex + 1, aRightIndex);
}




DoubleNode *RemoveNodeAtIndex(DoubleList *aList, int anIndex)
{
	DoubleNode *theResult = NULL;

	if (NULL == aList)
		return NULL;

	if (anIndex < 0 || aList->counter <= anIndex)
		return NULL;

	if (0 == anIndex)
	{
		DoubleNode *theHead = aList->head;

		aList->head = aList->head->next;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->counter --;
		theResult = theHead;
	}
	else
	{
		DoubleNode *theOwnNode = NodeAtIndex(aList, anIndex - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->next;
			theOwnNode->next = theResult->next;

			aList->counter --;

			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}

	return theResult;
}

void DeleteSameNodes(DoubleList* aList)
{
    DoubleNode* theNode=aList->head;

    int index=0;



    while(theNode!=aList->tail->prev)
    {
           if(index==4)
        {
            break;
        }


        if(theNode->value==theNode->next->value)
        {
            RemoveNodeAtIndex(aList,index);
        }

        theNode=theNode->next;
        index++;

    }
}
