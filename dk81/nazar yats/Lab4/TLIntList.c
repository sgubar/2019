
#include "TLIntList.h"
#include <limits.h>
#include <stdlib.h>

static IntNode *createIntNodeWithValue(char *anIntValue);

#pragma mark -
IntList *TLCreateIntList()
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

void TLDestroyIntList(IntList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		IntNode *theNode = aList->head;
	
		do
		{
			IntNode *theNodeToDelete = theNode;
			theNode = theNode->next;
		
			free (theNodeToDelete);
		
		}while (NULL != theNode);
	
		free(aList);
	}
}

int TLAddIntValueToList(IntList *aList, char *anIntValue)
{
	
	
	int theResult = -1;
	
	if (NULL != aList)
	{
		IntNode *theNode = createIntNodeWithValue(anIntValue);
	
		if (NULL != theNode)
		{
			if (NULL == aList->head && aList->head == aList->tail)
			{
				aList->head = aList->tail = theNode;
			}
			else
			{
				IntNode *theTail = aList->tail;
				aList->tail = theNode;
				theTail->next = theNode;
				theNode->prev = theTail;
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	
	return theResult;
}

// print list
void TLPrintList(IntList *aList)
{
	int min = 0;
	int i;
	IntNode *theNode = aList->head;
	
	do
	{
		for(i=0; theNode->value[i] != '\0' && i < 25; i++){}
		//printf("%i\n", i);
		//printf("%c\n", theNode->value[i]);
		if(min == 0)
		{
			min = i;
		}
		else if (i < min)
		{
			min = i;
		}
		
		theNode = theNode->next;
	
	}while (NULL != theNode);
	
	printf ("\n");
	
	
	theNode = aList->head;
	do
	{
		for(i=0; theNode->value[i] != '\0' && i < 25; i++){}
		//printf("%i\n", i);
		if(i == min)
		{
			printf("%s", theNode->value );
		}	
			
			theNode = theNode->next;
	}while (NULL != theNode);
	
	//printf("%i\n", min);

}

IntNode *createIntNodeWithValue(char *anIntValue)
{
	int i;
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
	for(i=0; i < 25; i++){
		//theNode->value[i] = ' ';
		theNode->value[i] = anIntValue[i];
	}
	}
	
	return theNode;
}
