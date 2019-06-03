#include "tool.h"
#include <stdlib.h>
#include <math.h>


Tree* createTree()
{
	Tree* aTree = (Tree*)malloc(sizeof(Tree));

	if (NULL != aTree)
	{
		aTree->root = NULL;
		aTree->count = 0;
	}

	return aTree;
}

Node* createNodeWithValue(int aValue)
{
	Node* theNode = (Node*)malloc(sizeof(Node));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void printTree(Node* aNode)
{
	if (NULL != aNode)
	{

		printTree(aNode->leftChild);
		printf("Node (%d)\n", aNode->value);
		printTree(aNode->rightChild);
	}
}

void insertValueToTree(Tree* aTree,int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	Node* theNode = createNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count++;
	}
	else
	{
		Node* theCurrent = aTree->root;
		Node* theParent = NULL;

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

		aTree->count++;
	}
}


Node* destroyTreeNode(Node* treeRoot, int aValue)
{
	if (treeRoot == NULL)
		return treeRoot;

	if (aValue < treeRoot->value)
	{
		treeRoot->leftChild = destroyTreeNode(treeRoot->leftChild, aValue);
	}
	else if (aValue > treeRoot->value)
	{
		treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, aValue);
	}
	else
	{
		if (treeRoot->leftChild == NULL)
		{
			Node* tempNode = treeRoot->rightChild;
			destroyNode(treeRoot);
			return tempNode;
		}
		else if (treeRoot->rightChild == NULL)
		{
			Node* tempNode = treeRoot->leftChild;
			destroyNode(treeRoot);
			return tempNode;
		}

		Node* tempNode = getSuccessor(treeRoot);
		treeRoot->value = tempNode->value;
		treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, tempNode->value);
	}
	return treeRoot;
}

Node* getSuccessor(Node* aDelNode)
{
	Node* theSuccessParent = aDelNode;
	Node* theSuccessor = aDelNode;
	Node* theCurrent = aDelNode->rightChild; 

	while (NULL != theCurrent)
	{
		theSuccessor = theCurrent;
		theSuccessParent = theSuccessor;
		theCurrent = theCurrent->leftChild;
	}

	if (theSuccessor != aDelNode->rightChild)
	{
		theSuccessParent->leftChild = theSuccessor->rightChild;
		theSuccessor->rightChild = aDelNode->rightChild;
	}

	return theSuccessor;
}


Node* findNodeWithValue(Tree* aTree, int aValue)
{
	Node* theCurrentNode = NULL;

	if (NULL != aTree)
	{
		Node* theCurrentNode = aTree->root; 
		while (aValue != theCurrentNode->value)
		{
			if (aValue < theCurrentNode->value)
			{
				theCurrentNode->leftChild;
			}
			else
			{
				theCurrentNode->rightChild;
			}

			if (NULL == theCurrentNode)
			{
				printf("Element does not exist");
				break;
			}
		}
	}

	return theCurrentNode;
}

void destroyNode(Node* aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

void destroyTree(Tree* aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}