#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
#include "dk_tools.h" 
 
List *createList() 
{ 
  List *theList = (List *)malloc(sizeof(List)); 
   
  if (NULL != theList) 
  { 
    theList->count = 0; 
    theList->head = NULL; 
    theList->end = NULL; 
  } 
   
  return theList; 
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
    Node *theNodeA = theNode; 
    theNode = theNode->nextNode; 
   
    destroyNode(theNodeA); 
  } 
 
  free(aList); 
} 
 
void printList(List* aList)
{
  if (aList != NULL)
  {
  Node* theNode = aList->head;
  while(theNode != NULL)
  {
    printf("%d\n", theNode->value);
    theNode = theNode->nextNode;
  }
    printf("\n");
  }
  else 
  {
  return;
  }
}

Node* createNode(int aValue) 
{ 
Node *theResult = (Node*)malloc(sizeof(Node)); 
 
  theResult->value = aValue; 
  theResult->nextNode = NULL; 
 
  return theResult;   
} 
 
void destroyNode(Node* aNode) 
{ 
  if (NULL != aNode) 
  {
    free (aNode); 
  }
}
 
void addNodeToList(List *aList, int aValue) 
{ 
   
  if (NULL == aList) 
    return; 
    
    Node* theNode = createNode(aValue);
   
  if (aList->head == NULL && aList->end == NULL) 
  { 
    aList->head = aList->end = theNode;   
  } 
  else 
  { 
    aList->end->nextNode = theNode; //
    aList->end = theNode; 
  } 
  aList->count ++; 
} 
 

 
float serArifmet(List* aList) 
{ 
  float mid = 0.0;  
  int k=0;
  
  Node* theNode = aList->head; 
  k = 0;
  while (theNode!=NULL ) 
  { 
    k += theNode->value; 
    theNode = theNode -> nextNode;
  } 
  mid = k / aList->count; 
  return mid; 
}


void destroyNodeWhoFirstMin(List* aList , float mid)
 {
   Node* theNode = aList -> head;
   int i = 0;
   Node* TheDeleteNode=NULL;
   while(i < aList -> count)
   {
   if (theNode->value < mid)
   {
     	if (theNode == aList->head)
     	   {
     	   	TheDeleteNode = theNode;
     	   	aList->head = theNode->nextNode;
         	destroyNode(TheDeleteNode);
			}
		else
			{
				Node* parentNode = getParentNode(aList, theNode);
				parentNode->nextNode = theNode->nextNode;
				destroyNode(theNode);
			}
    break;     
    }
    theNode = theNode->nextNode;
    i++;
  }
 }
 
Node* getParentNode(List* aList, Node* aNode)
{
	if(NULL != aList && NULL != aNode)
	{
	Node* theNode = aList->head;
	while(NULL != theNode->nextNode)
	{
	if(theNode->nextNode == aNode)
	return theNode;
	else
	theNode = theNode->nextNode;
	}
	}
}

