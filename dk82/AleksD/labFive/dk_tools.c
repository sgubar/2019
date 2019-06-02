#include "dk_tools.h"
#include <stdlib.h>

Tree* createTree()
{
	Tree* theTree = (Tree *)malloc(sizeof(Tree));
	if (NULL != theTree)
	{
		theTree -> root = NULL;
		theTree -> count = 0;
	}
	return theTree;
}

Node* createNode(float aValue)
{
	Node* theNode = (Node *)malloc(sizeof(Node));
	if (NULL != theNode)
	{
		theNode -> leftChild = NULL;
		theNode -> rightChild = NULL;
		theNode-> value = aValue;
	}
	return theNode;
}

void destroyNode(Node* aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free (aNode);
	}
}

void destroyTree(Tree* aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree -> root);
		free (aTree);
	}
}

void addNodeInTree(Tree* aTree , float aValue)
{
	if (aTree == NULL)
	{
		return ;
	}
	Node* theNode = createNode(aValue);
	
	if (theNode == NULL)
	{
		return ;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
    {
		Node* tempNode = aTree -> root;
		Node* parentNode = NULL;
		
		while (1)
		{
			parentNode = tempNode;
			
			if (aValue < tempNode->value)
			{
				tempNode = tempNode-> leftChild;
					
				if(NULL == tempNode)
				{
					parentNode -> leftChild = theNode;
					break;
				}
			}
			
			else 
			{
				tempNode = tempNode-> rightChild;
				
				if(NULL == tempNode)
				{
					parentNode -> rightChild = theNode;
					break;
				}
			}		
		}
		aTree -> count ++;	
	}
}

void printTree(Tree *aTree)
{
	printTree1(aTree->root, aTree->count);
	printf("\n");
}

void printTree1(Node *aNode, int count)
{
	static int i = 0;
	if (i == count)
    i = 0;
	if (NULL != aNode)
	{
	   printTree1(aNode->leftChild, count);
	    printf("Tree[%d] = %.2f\n", i, aNode->value);
	   i++;
	   printTree1(aNode->rightChild, count);
    }
    if (i == count)
    i = 0;
}

Node* findNodeByIndex(Tree* aTree , float aValue)
{
	if (aTree == NULL)
	{
		return ;
	}

	Node* theNode = aTree -> root;

	while (aValue != theNode  -> value)
	{	
		if (aValue < theNode -> value)
		{
			theNode = theNode -> leftChild;
		}
		else
		{
			theNode = theNode -> rightChild;
		}
		if (theNode == NULL)
		{
			printf("\nthe Node is not found :( \n");
			break ;
		}
	}
	if (theNode != NULL)
	{
		printf("the Node is found :)\n");
		return theNode;
	}
}

int deleteNodeWithValue(Tree* aTree, float aValue)
{
  int theResult = 1;

  //1. Find assumed node to delete
  Node* theNode = aTree->root;
  Node* theParent = aTree->root;

  int isLeftChild = 1;


  while (aValue!=(int)theNode->value)
  {
    theParent = theNode;
    if (aValue<(int)theNode->value)
    {
      isLeftChild = 1; 
      theNode = theNode->leftChild;
    }
    else
    {
      isLeftChild = 0; 
      theNode = theNode->rightChild;
    }

    if (NULL == theNode)
    {
      
      return 0;
    }
  }
      if (theNode == aTree->root)
 	{
 		Node* theSuccessor = getSuccessor(aTree, theNode);
	   	theSuccessor->leftChild = aTree->root->leftChild;
		aTree->root = theSuccessor;
		aTree->count--;
		return theResult;
	}

  //if the node does not have children then just remove it
  if (NULL == theNode->leftChild && NULL == theNode->rightChild)
  {
    if (aTree->root == theNode)
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
  else if (NULL == theNode->rightChild)
  {
    if (aTree->root == theNode)
    {
      aTree->root = theNode->leftChild;
    }
    else if (isLeftChild)
    {
      theParent->leftChild = theNode->leftChild;
    }
    else
    {
      theParent->rightChild = theNode->leftChild;
    }
  }
  else if (NULL == theNode->leftChild)
  {
    if (aTree->root == theNode)
    {
      aTree->root = theNode->rightChild;
    }
    else if (isLeftChild)
    {
      theParent->leftChild = theNode->rightChild;
    }
    else
    {
      theParent->rightChild = theNode->rightChild;
    }
  }
  else
  {
    Node* theSuccessor = getSuccessor(aTree, theNode);

    if (aTree->root == theSuccessor)
    {
      aTree->root = NULL;
    }
    else if (isLeftChild)
    {
      theParent->leftChild = theSuccessor;
      theSuccessor -> leftChild = theNode -> leftChild;
    }
    else
    {
      theParent->rightChild = theSuccessor;
        theSuccessor -> rightChild = theNode -> rightChild;
    }

  }
  aTree->count--;
  free(theNode);
  theResult = 1;

  return theResult;
}

Node* getSuccessor(Tree* aTree, Node* aDelNode)
{
	Node *theSuccessParent = aDelNode;
	Node *theSuccessor = aDelNode;
	Node *theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present
	
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


