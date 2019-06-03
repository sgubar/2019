#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

Tree *createTree()
{
	Tree *aTree = (Tree *)malloc(sizeof(Tree));

	if (NULL != aTree)
	{
		aTree->root = NULL;// корень
		aTree->count = 0;
	}

	return aTree;
}

void destroyTree(Tree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

FloatNode *createNode(float aValue)
{
	FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}


void destroyNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

FloatNode *destroyTreeNode(FloatNode *treeRoot, float value)
{
	if (treeRoot == NULL)
	{
		return treeRoot;
	}

	if (value < treeRoot->value)
	{
		treeRoot->leftChild = destroyTreeNode(treeRoot->leftChild, value);
	}
	
	else if (value > treeRoot->value)
	{
		treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, value);
	}
	
	else
	{
		if (treeRoot->leftChild == NULL) //if there is atleast 1 child
		{
			FloatNode *tempNode = treeRoot->rightChild;
			destroyNode(treeRoot);
			
			return tempNode;
		}
		else if (treeRoot->rightChild == NULL)
		{
			FloatNode *tempNode = treeRoot->leftChild;
			destroyNode(treeRoot);
			
			return tempNode;
		}

		//if there are 2 children
		FloatNode *tempNode = getSuccessor(treeRoot->rightChild);
		treeRoot->value = tempNode->value;
		treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, tempNode->value);
	}
	
	return treeRoot;
}

FloatNode *getSuccessor(FloatNode *treeRoot)
{
	FloatNode *theCurrent = treeRoot;

	while (theCurrent && theCurrent->leftChild != NULL)
		theCurrent = theCurrent->leftChild;

	return theCurrent;
}

void addNode(Tree *aTree, float aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	FloatNode *theNode = createNode(aValue);
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
		FloatNode *theCurrent = aTree->root;
		FloatNode *theParent = NULL;

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

FloatNode *findNode(Tree *aTree, float aValue)
{
	FloatNode *theCurrentNode = NULL;

	if (NULL != aTree)
	{
		FloatNode *theCurrentNode = aTree->root;	//start from root
		while (aValue != theCurrentNode->value)		//walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
				? theCurrentNode->leftChild : theCurrentNode->rightChild;


			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}

	return theCurrentNode;
}


void printTree(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		printTree(aNode->leftChild);
		printTree(aNode->rightChild);
		printf("[%f]\n", aNode->value);
	}
}
