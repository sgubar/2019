#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tool.h"
#include <string.h>
#pragma warning(disable:4996)


static void freeNode(NodePtr aNode);
static NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);

TreePtr createTree()
{
	TreePtr theTree = (TreePtr)malloc(sizeof(Tree));

	if (NULL != theTree) //!<- check correctness of memmory allocatoin
	{
		theTree->root = NULL; //!<- by default the root is NULL - the tree is empty
	}

	return theTree;
}

void deleteTree(TreePtr aTree)
{

}

NodePtr findNode(TreePtr aTree, double aName)
{
	NodePtr theCurrentNode = aTree->root; //<! - start from root
	int theComparisionResult = 0;
	
	while (aName != theCurrentNode->note->name) //<! - walk through the tree
	{
		theCurrentNode = (aName< theCurrentNode->note->name)
			? theCurrentNode->leftChild
			: theCurrentNode->rightChild;

		if (NULL == theCurrentNode)
		{
			break;
		}
	}

	return theCurrentNode;
}

void insertNode(TreePtr aTree, double aName)
{
	// prepare new Node
	// 1. create new node
	NodePtr theNewNode = (NodePtr)malloc(sizeof(Node));
	theNewNode->note = NULL;
	theNewNode->rightChild = NULL;
	theNewNode->leftChild = NULL;
	

	// 2. create new note
	PhoneNotePtr theNote = (PhoneNotePtr)malloc(sizeof(PhoneNote));
	theNote->name = aName;

	//3. fill node
	theNewNode->note = theNote;

	if (NULL == aTree->root) //<! - tree is empty, so the root is our node
	{
		aTree->root = theNewNode;
	}
	else
	{
		// start to search appropriate place to insert the new node
		NodePtr theCurrent = aTree->root;
		NodePtr theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
			int theCompare = 0;
			if (aName == theCurrent->note->name)
				theCompare = 0;
			else if (aName < theCurrent->note->name)
				theCompare = -1;
			else
				theCompare = 1;
			if (theCompare < 0)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent) //<!- the our place: path is finished
				{
					theParent->leftChild = theNewNode;
					//printf("%f\n", theParent->leftChild->note->name);
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNewNode;
					//printf("%f\n", theParent->rightChild->note->name);
					break;
				}
			}
		}
		printf("root=%f\n", aTree->root->note->name);
	}
}

int deleteNode(TreePtr aTree, const double aName)
{
	int theResult = 1;

	//1. Find assumed node to delete
	NodePtr theCurrent = aTree->root;
	NodePtr theParent = aTree->root;

	int isLeftChild = 1;
	int theCompare = 0;
	while (aName!=theCurrent->note->name)
	{
		theParent = theCurrent;
		if (aName<theCurrent->note->name)
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
			// the node is node found
			return 0;
	}
	if (theCurrent == aTree->root)
	{
		NodePtr theSuccessor = getSuccessor(aTree, theCurrent);
		theSuccessor->leftChild = aTree->root->leftChild;
		aTree->root = theSuccessor;
		return theResult;
	}
	//if the node does not have children then just remove it
	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = NULL;
		else if (isLeftChild)
			theParent->leftChild = NULL;
		else
			theParent->rightChild = NULL;
	}
	else if (NULL == theCurrent->rightChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = theCurrent->leftChild;
		else if (isLeftChild)
			theParent->leftChild = theCurrent->leftChild;
		else
			theParent->rightChild = theCurrent->leftChild;
	}
	else if (NULL == theCurrent->leftChild)
	{
		if (aTree->root == theCurrent)
			aTree->root = theCurrent->rightChild;
		else if (isLeftChild)
			theParent->leftChild = theCurrent->rightChild;
		else
			theParent->rightChild = theCurrent->rightChild;
	}
	else
	{
		NodePtr theSuccessor = getSuccessor(aTree, theCurrent);
		if (aTree->root == theSuccessor)
			aTree->root = NULL;
		else if (isLeftChild)
			theParent->leftChild = theSuccessor;
		else
			theParent->rightChild = theSuccessor;


	}

	freeNode(theCurrent);
	theResult = 1;

	return theResult;
}

//#pragma mark -
void freeNode(NodePtr aNode)
{
	if (NULL != aNode)
	{
		if (NULL != aNode->note)
			free(aNode->note);
		free(aNode);
	}
}

NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode)
{
	NodePtr theSuccessParent = aDelNode;
	NodePtr theSuccessor = aDelNode;
	NodePtr theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present

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

void PrintTreeinorderPrint(NodePtr aNode)
{
	if (aNode == NULL)
		return;
	PrintTreeinorderPrint(aNode->leftChild);
	printf("%.3f ", aNode->note->name);
	PrintTreeinorderPrint(aNode->rightChild);
}