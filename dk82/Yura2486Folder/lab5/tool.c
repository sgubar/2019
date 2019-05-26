#include "tool.h"
#include <stdlib.h>

intTree *createIntTree()
{
	intTree *theTree = (intTree *)malloc(sizeof(intTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyIntTree(intTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void destroyNode(intNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

void insertIntValueToTree(intTree *aTree, float aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	intNode *theNode = createIntNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		intNode *theCurrent = aTree->root;
		intNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
		
			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
	
		aTree->count ++;
	}
}

intNode *findNodeWithValue(intTree *aTree, float aValue)
{
	intNode *theCurrentNode = NULL;
	intNode* nodeError = createIntNodeWithValue(-1);
	
	if (NULL != aTree)
	{
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{	
			if (aValue < theCurrentNode->value)
			   {
   			   	theCurrentNode = theCurrentNode->leftChild;
			   }
			   else
			   {
			   	theCurrentNode = theCurrentNode->rightChild;
			   }
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	
	if (NULL == theCurrentNode)
	{
		printf("Node exist\n");
		return nodeError;
	}
	else
	return theCurrentNode;
}

int deleteNodeWithValue(intTree *aTree, float aValue)
{
  int theResult = 1;

  //1. Find assumed node to delete
  intNode* theCurrent = aTree->root;
  intNode* theParent = aTree->root;

  int isLeftChild = 1;

  while (aValue!=(int)theCurrent->value)
  		{
		theParent = theCurrent;
    	if (aValue<(int)theCurrent->value)
   		    {
      		isLeftChild = 1; //<!- go to the left
      		theCurrent = theCurrent->leftChild;
    		}
    	else
    	{
      	isLeftChild = 0; //<!- right node
	 	theCurrent = theCurrent->rightChild;
	 	}
    	if (NULL == theCurrent)
 	   {
       // the node is node found
       return 0;
       }
  	   }
  if (theCurrent == aTree->root)
   {
 	intNode* theSuccessor = getSuccessor(aTree, theCurrent);
	theSuccessor->leftChild = aTree->root->leftChild;
	aTree->root = theSuccessor;
	aTree->count--;
	return theResult;
	}

  //if the node does not have children then just remove it
  if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
  	 {
      if (aTree->root == theCurrent)
      	{
      	aTree->root = NULL;
    	}
    else if (isLeftChild)
		 {
      	 theParent->leftChild = NULL;
    	 }
    else
    	{
     	 theParent->rightChild = NULL;
   	 	 }
  		 }
	 else if (NULL == theCurrent->rightChild)
  	 {
    if (aTree->root == theCurrent)
    {
      aTree->root = theCurrent->leftChild;
    }
    else if (isLeftChild)
    {
      theParent->leftChild = theCurrent->leftChild;
    }
    else
    {
      theParent->rightChild = theCurrent->leftChild;
    }
  }
  else if (NULL == theCurrent->leftChild)
  {
    if (aTree->root == theCurrent)
    {
      aTree->root = theCurrent->rightChild;
    }
    else if (isLeftChild)
    {
      theParent->leftChild = theCurrent->rightChild;
    }
    else
    {
      theParent->rightChild = theCurrent->rightChild;
    }
  }
  else
  {
    intNode* theSuccessor = getSuccessor(aTree, theCurrent);

    if (aTree->root == theSuccessor)
    {
      aTree->root = NULL;
    }
    else if (isLeftChild)
    {
      theParent->leftChild = theSuccessor;
    }
    else
    {
      theParent->rightChild = theSuccessor;
    }

  }
  aTree->count--;
  free(theCurrent);
  theResult = 1;

  return theResult;
}

intNode* getSuccessor(intTree* aTree, intNode* aDelNode)
{
	intNode *theSuccessParent = NULL;
	intNode *theSuccessor = NULL;
	intNode *theCurrent = NULL;
	theSuccessParent = aDelNode;
	theSuccessor = aDelNode;
	theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present
	
	while (NULL != theCurrent)
	{
		theSuccessParent = theSuccessor;
		theSuccessor = theCurrent;
		theCurrent = theCurrent->leftChild;
	}
	
	if (theSuccessor != aDelNode->rightChild)
	{
		theSuccessParent->leftChild = theSuccessor->rightChild;
		theSuccessor->rightChild = aDelNode->rightChild;
	}

	return theSuccessor;
}

intNode *findParentNode(intTree *aTree, intNode* aNode)
{	
	intNode *theCurrentNode = NULL;
	intNode* nodeError = createIntNodeWithValue(-1);
	
	if (NULL != aTree)
	{
		theCurrentNode = aTree->root;
		
		if (theCurrentNode->rightChild == aNode || theCurrentNode->leftChild == aNode)
		   {
		   return theCurrentNode;
		   }
		
		while ((NULL != theCurrentNode->rightChild && aNode->value != theCurrentNode->rightChild->value) || (NULL != theCurrentNode->leftChild && aNode->value != theCurrentNode->leftChild->value))
		{	
			if (aNode->value < theCurrentNode->value)
			   {
   			   	theCurrentNode = theCurrentNode->leftChild;
			   }
            else
			   {
			   	theCurrentNode = theCurrentNode->rightChild;
			   }
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	
	if (NULL == theCurrentNode)
	{
		printf("Parent node exist\n");
		return nodeError;
	}
	else
	return theCurrentNode;
}

void printTree1(intNode *aNode, int count)
{
	static int i = 0;
	if (i == count)
    i = 0;
	if (NULL != aNode)
	{
	   printf("Tree[%d] = %.2f\n", i, aNode->value);
	   i++;
	   printTree1(aNode->leftChild, count);
	   printTree1(aNode->rightChild, count);
    }
    if (i == count)
    i = 0;
}

intNode *createIntNodeWithValue(float aValue)
{
	intNode *theNode = (intNode *)malloc(sizeof(intNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}

void printTree(intTree *aTree)
{
	printTree1(aTree->root, aTree->count);
	printf("\n");
}

