#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


intList *createList()
{
	intList *theList = (intList *)malloc(sizeof(intList));
	
	if (NULL != theList)
	{
	theList->head = NULL;
	theList->count = 0;
	}

	return theList;
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

intNode *addNode(intList *aList, intNode *aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}
	//if list empty
	if (NULL == aList->head)
	{
		aList->head = aNewNode;
		aList->head->nextNode = aNewNode;
	}
	//if list not empty
	else
	{
		intNode *theHead = aList->head->nextNode;
		aList->head->nextNode = aNewNode;
		aNewNode->nextNode = theHead;
	}

	aList->count += 1;
	
	return aNewNode;
}

void printList(intList *aList)
{
	if (NULL == aList->head)
	return;
	int i = 0;
	int n = 0;
	int j = countList(aList);
	intNode *theNode = aList->head;
	for (i; i < j+5; i++)
	{
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", n, theNode->value);
			if (n == j || (n+1==j && j == 1))
			continue;
			else
			{
				n++;
				if (n == j)
				n = 0;
			}	
		}
		theNode = theNode->nextNode;
	}
	printf("\n");
}

int countList(const intList *aList)
{
	int theResult = -1;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
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
	int i = 0;
	while (i < countList(aList))
	{
		intNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
	
		freeIntNode(theNodeToBeFree);
		i++;
	}

	//2. Free memory for the List structure
	free(aList);
}

void freeIntNode(intNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

void addNElementsInList(intList *aList, int n)
{
	if (n < 1)
	{
	return;
	}
	int i = 0;
	srand(time(NULL));
	for(n; n>0; n--)
	{
		addNode(aList, createNodeWithIntValue(rand()%10));
		i++;
	}
}

void bubbleSort(intList *aList)
{
    if(NULL != aList)
    {
        if (aList->count <= 1)
        return;
        
        int temp;
        unsigned int i = 0;
        intNode* theNode = aList->head;
        bool isSwaped = true;
        
		while (isSwaped)
		{
            isSwaped = false;
            theNode = aList->head;
            for (i = 0; i < aList->count-1; ++i)
			{
                if (theNode->value > theNode->nextNode->value)
                {
                    temp=theNode->value;
                    theNode->value=theNode->nextNode->value;
                    theNode->nextNode->value=temp;
                    isSwaped=true;
                }
                theNode=theNode->nextNode;
            }
        }

    }
    return;
}
	
/*
void bubbleSort(intList *aList)
	{
		if(NULL != aList)
		{
		int i, j;
		int temp;
		intNode* theNode = aList->head->nextNode;
		for(i = countList(aList); i>0; i--)
			{
				for(j = 0; j<i; j++)
					{
						if (theNode->value > theNode->nextNode->value)
							{
								temp = theNode->value;
								theNode->value = theNode->nextNode->value;
								theNode->nextNode->value = temp;
							}
						theNode = theNode->nextNode;
					}
			}
		}
	}
	*/
	

