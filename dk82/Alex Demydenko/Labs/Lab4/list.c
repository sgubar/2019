#include "list.h"


Node *createNode(int aValue)
{
	Node *theResult = (Node *)malloc(sizeof(Node));
	
	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void destroyNode(Node *aNode)
{
	if (NULL != aNode)
		free(aNode);
}



List *createList()
{
	List *theList = (List *)malloc(sizeof(List));

	theList->head = NULL;
	theList->tail = theList->head;
	theList->count = 0;
	
	return theList;
}

void destroyList(List *aList)
{
	if (NULL == aList)
		return;

	Node *theNode = aList->head;
	while (aList->count != 0)
	{
		Node *theNodeToKill = theNode;
		theNode = theNode->nextNode;
		
		destroyNode(theNodeToKill);
		aList->count --;
	}
	
	free(aList);
}

	//operations
Node *addNode(List *aList, Node *aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
		return NULL;
	
	if (aList->head == aList->tail)
	{
		aList->head = aNewNode;	
	}
	else
	{
		Node *prevNode = nodeAtIndex(aList, aList->count - 1);
		prevNode->nextNode = aNewNode;
		aNewNode->nextNode = aList->tail;
	}
	aList->count ++;
	
	return aNewNode;
}


Node *nodeAtIndex(const List *aList, int anIndex)
{
	Node *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		Node *theNode = aList->head;
	
		do
		{
			if (i == anIndex)
			{
				theResult = theNode;
				break;
			}
		
			i++;
			theNode = theNode->nextNode;
		
		} while (i < aList->count);
	}
	
	return theResult;
}

void printList(const List *aList)
{
	if (NULL == aList)
		return;
		
	if (aList->count <= 0)
		return;
	
	Node *theNode = aList->head;
	
	for (int i = 0; i < aList->count; i++)
	{
		if (NULL != theNode)
		{
			printf("node.[%d] = |%d|\n", i, theNode->value);
			theNode = theNode->nextNode;
		}
	}
}


void destroyNodeAtIndex(List *aList, int anIndex)
{	
	if (NULL == aList)
		return;
	
	if (anIndex < 0 || aList->count < anIndex)
		return;
	
	if (aList->head == aList->tail)
		return;
	
	if (0 == anIndex)
	{
		
		aList->head = aList->head->nextNode;
		
		aList->count --;
	}
	else
	{
		Node *currentNode = NULL;
		Node *prevNode = nodeAtIndex(aList, anIndex - 1);
		if (NULL != prevNode)
		{
			currentNode = prevNode->nextNode;
			if (NULL != currentNode->nextNode)
			{
				prevNode->nextNode = currentNode->nextNode;
			}
			else
			{
				prevNode->nextNode = aList->tail;
			}
			aList->count --;
		}
		return;
	}
}
void DeleteIndex (List *aList, int anIndex)
{
	if (NULL == aList)
		return;
	
	if (anIndex < 1 || aList->count < anIndex)
		return;
	
	int i = 1;
	while (aList->count >= anIndex)
	{
		destroyNodeAtIndex(aList, anIndex - 1);
		
		printf("###%d###\n", i);
		printList(aList);
		printf("\n");
		
		i++;		
	}
}
