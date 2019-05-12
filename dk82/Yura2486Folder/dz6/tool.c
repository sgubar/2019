#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int partitionIt(intList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;
	
	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && nodeAtIndex(aList, ++theLeft)->value > aPivot);
	
		// search the lowest element
		while (theRight > aLeftIndex && nodeAtIndex(aList,--theRight)->value < aPivot);
	
		if (theLeft >= theRight) // pointer are the same
		{
			break;
		}
		else
		{
			//lets to swap elements
		
			swapNodesByIndex(aList, theLeft, theRight);
		}
	}
	
	return theLeft; // return break position
}


void quickSort(intList *aList, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}
	
	int thePivot = nodeAtIndex(aList, aRightIndex)->value;
	int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);
	
	//left part sorting
	quickSort(aList, aLeftIndex, thePartitionIndex - 1);
	
	//right part sorting
	quickSort(aList, thePartitionIndex + 1, aRightIndex);
}

intNode *createNodeWithIntValue(int aValue)
{
	intNode *theResult = (intNode *)malloc(sizeof(intNode));
	
	if (theResult != NULL)
	{
	theResult->value = aValue;
	theResult->nextNode = NULL;
	}
	
	return theResult;
}

void freeIntNode(intNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

const int kSLListError = -1;

intList *createList()
{
	intList *theList = (intList *)malloc(sizeof(intList));
	
	if (NULL != theList)
	{
	theList->head = NULL; 
	theList->tail = NULL; 
	theList->count = 0;
	}

	return theList;
}

void freeList(intList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}

	//1. Remove all elements
	intNode *theNode = aList->head;
	
	while (NULL != theNode)
	{
		intNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
	
		freeIntNode(theNodeToBeFree);
	}

	//2. Free memory for the List structure
	free(aList);
}

intNode *addNode(intList *aList, intNode *aNewNode)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}
	
	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		intNode *theTail = aList->tail;
		aList->tail = aNewNode;
	
		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;
	
	return aNewNode;
}

int countList(const intList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

intNode *nodeAtIndex(const intList *aList, int anIndex)
{
	intNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		intNode *theNode = aList->head;
	
		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}
		
			i++; // increase index
			theNode = theNode->nextNode; //<! - go to next node
		
		} while (NULL != theNode);
	}
	
	return theResult;
}

intNode *insertNodeAtIndex(intList *aList, intNode *aNewNode, int anIndex)
{
	intNode *theResult = NULL;
	
	if (NULL == aList || NULL == aNewNode)
		return NULL;
	
	if (anIndex < 0 || aList->count < anIndex)
		return NULL;
	
	if (0 == anIndex)
	{
		if (NULL == aList->head && NULL == aList->tail)
		{
			addNode(aList, aNewNode);
			theResult = aNewNode;
		}
		else
		{
			intNode *theHead = aList->head;
			aList->head = aNewNode;
			aList->head->nextNode = theHead;
			aList->count ++;
			theResult = aNewNode;
		}
	}
	else if (aList->count == anIndex)
	{
		addNode(aList, aNewNode);
		theResult = aNewNode;
	}
	else
	{
		int theOwnerIndex = anIndex - 1;
		intNode *theOwnNode = nodeAtIndex(aList, theOwnerIndex);
	
		if (NULL != theOwnNode)
		{
			intNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;
		
			aList->count ++;
			theResult = aNewNode;
		}
	}
	
	return theResult;
}

intNode *removedNodeAtIndex(intList *aList, int anIndex)
{
	intNode *theResult = NULL;
	
	if (NULL == aList)
		return NULL;
	
	if (anIndex < 0 || aList->count <= anIndex)
		return NULL;
	
	if (0 == anIndex)
	{
		intNode *theHead = aList->head;
	
		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;
	
		aList->count --;
		theResult = theHead;
	}
	else
	{
		intNode *theOwnNode = nodeAtIndex(aList, anIndex - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->nextNode;
			theOwnNode->nextNode = theResult->nextNode;
		
			aList->count --;
		
			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}
	
	return theResult;
}

void swapNodesByIndex(intList *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return ;
	
	intNode *theLeftNode = nodeAtIndex(aList, aLeftIndex);
	intNode *theRightNode = nodeAtIndex(aList, aRightIndex);
	
	int theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}

void printList(const intList *aList)
{
	int i = 0;
	for (i; i < countList(aList); i++)
	{
		intNode *theNode = nodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}


