#include "theList.h"
#include "theNode.h"
#include <stdlib.h>

const int ListError = -1;


IntList *CreateList()
{

	IntList *theList = (IntList *)malloc(sizeof(IntList));


	theList->head = NULL;
	theList->tail = NULL;
	theList->acount = 0;



	return theList;
}

void FreeList(IntList *aList)
{

	if (NULL == aList)
	{
		return;
	}


	IntNode *theNode = aList->head;

	while (NULL != theNode)
	{
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		FreeNode(theNodeToBeFree);
	}
	free(aList);
}

IntNode *AddNode(IntList *aList, IntNode *aNewNode)
{

	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}
	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		IntNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->acount += 1;

	return aNewNode;
}

int CountList(const IntList *aList)
{
	int theResult = ListError;

	if (NULL != aList)
	{
		theResult = aList->acount;
	}

	return theResult;
}

IntNode *NodeAtIndex(const IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->acount)
	{
		int i = 0;
		IntNode *theNode = aList->head;

		do
		{
			if (i == anIndex)
			{
				theResult = theNode;
				break;
			}

			i++;
			theNode = theNode->nextNode;

		} while (NULL != theNode);
	}

	return theResult;
}

IntNode *InsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL == aList || NULL == aNewNode)
		return NULL;

	if (anIndex < 0 || aList->acount < anIndex)
		return NULL;

	if (0 == anIndex)
	{
		if (NULL == aList->head && NULL == aList->tail)
		{
			AddNode(aList, aNewNode);
			theResult = aNewNode;
		}
		else
		{
			IntNode *theHead = aList->head;
			aList->head = aNewNode;
			aList->head->nextNode = theHead;
			aList->acount ++;
			theResult = aNewNode;
		}
	}
	else if (aList->acount == anIndex)
	{
		AddNode(aList, aNewNode);
		theResult = aNewNode;
	}
	else
	{
		int theOwnerIndex = anIndex - 1;
		IntNode *theOwnNode = NodeAtIndex(aList, theOwnerIndex);

		if (NULL != theOwnNode)
		{
			IntNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;

			aList->acount ++;
			theResult = aNewNode;
		}
	}

	return theResult;
}

IntNode *RemovedNodeAtIndex(IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL == aList)
		return NULL;

	if (anIndex < 0 || aList->acount <= anIndex)
		return NULL;

	if (0 == anIndex)
	{
		IntNode *theHead = aList->head;

		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->acount --;
		theResult = theHead;
	}
	else
	{
		IntNode *theOwnNode = NodeAtIndex(aList, anIndex - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->nextNode;
			theOwnNode->nextNode = theResult->nextNode;

			aList->acount --;

			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}

	return theResult;
}

void doPrintList(const IntList *aList)
{
    int i;
	for (i = 0; i < CountList(aList); i++)
	{
		IntNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d]->data = %d\n", i, theNode->data);
		}
	}
}

void SwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return ;

	IntNode *theLeftNode = NodeAtIndex(aList, aLeftIndex);
	IntNode *theRightNode = NodeAtIndex(aList, aRightIndex);

	int theTmp = theLeftNode->data;
	theLeftNode->data = theRightNode->data;
	theRightNode->data = theTmp;
}

int FindtheSameNodeIndex(IntList *aList)
{
    IntNode *theNode;
    int tmp, i, m, j;
    for(i = 0; i < CountList(aList); i++)
    {
        j = i + 1;
        m = 0;
        theNode = aList->head;
        if(i > 0)
        {
            do
            {
                theNode = theNode->nextNode;
                m++;
            }
            while(m < i);
        }
        tmp = theNode->data;
        theNode = theNode->nextNode;
        for( ;j < CountList(aList); j++)
        {
            if(theNode->data == tmp)
            {
                return j;
            }
            else
            {
                theNode = theNode->nextNode;
            }
        }
    }
    return -1;
}
