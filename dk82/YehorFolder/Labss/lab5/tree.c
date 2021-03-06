#include "Tree.h"
#include <stdlib.h>
#include <string.h>
DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->counter = 0;
	}

	return theTree;
}


void destroyDoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}



void destroyNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}


DoubleNode *createDoubleNodeWithValue(double aValue)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}


void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->counter ++;
	}
	else
	{
		DoubleNode *theCurrent = aTree->root;
		DoubleNode *theParent = NULL;

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

		aTree->counter ++;
	}
}

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue)
{
	DoubleNode *theCurrentNode = NULL;

	if (NULL != aTree)
	{
		DoubleNode *theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}

	return theCurrentNode;
}



 void PrintTreeInPreOrder(DoubleNode* aNode)
{


        if(aNode==NULL)
            return;


        printf("%.2f " ,aNode->value);
        PrintTreeInPreOrder(aNode->leftChild);

        PrintTreeInPreOrder(aNode->rightChild);



}




DoubleNode* getSuccessor(DoubleTree* aTree, DoubleNode* aDelNode)
{
	DoubleNode* theSuccessParent = aDelNode;
	DoubleNode* theSuccessor = aDelNode;
	DoubleNode* theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present

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


int deleteNodeWithValue(DoubleTree* aTree, int aValue)
{
  int theResult = 1;

  //1. Find assumed node to delete
  DoubleNode* theCurrent = aTree->root;
  DoubleNode* theParent = aTree->root;

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
 		DoubleNode* theSuccessor = getSuccessor(aTree, theCurrent);
	   	theSuccessor->leftChild = aTree->root->leftChild;
		aTree->root = theSuccessor;
		aTree->counter--;
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
    DoubleNode* theSuccessor = getSuccessor(aTree, theCurrent);

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
  aTree->counter--;
  free(theCurrent);
  theResult = 1;

  return theResult;
}
