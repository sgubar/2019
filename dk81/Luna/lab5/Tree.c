#include "Tree.h"

NodePtr createNode(double value) {
	NodePtr node = (NodePtr)malloc(sizeof(Node));

	node->value = value;

	node->leftChild = NULL;
	node->rightChild = NULL;

	return node;
}

TreePtr createTree() {
	TreePtr tree = (TreePtr)malloc(sizeof(Tree));
	tree->root = NULL;

	return tree;
}

void addCreatedNode(TreePtr tree, NodePtr newNode) {
	if (NULL == tree || NULL == newNode) {
		return -1;
	}


	if (NULL == tree->root)
	{
		tree->root = newNode;
	}
	else
	{
		// start to search appropriate place to insert the new node
		NodePtr theCurrent = tree->root;
		NodePtr theParent = NULL;

		while (1)
		{
			theParent = theCurrent;


			if (newNode->value < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent) //<!- the our place: path is finished
				{
					theParent->leftChild = newNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = newNode;
					break;
				}
			}
		}
	}
}

void addNode(TreePtr tree, double value) {
	if (NULL == tree) {
		return -1;
	}

	NodePtr newNode = createNode(value);

	if (NULL == tree->root)
	{
		tree->root = newNode;
	}
	else
	{
		// start to search appropriate place to insert the new node
		NodePtr theCurrent = tree->root;
		NodePtr theParent = NULL;

		while (1)
		{
			theParent = theCurrent;


			if (newNode->value < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent) //<!- the our place: path is finished
				{
					theParent->leftChild = newNode;

					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = newNode;

					break;
				}
			}
		}
	}
}



void deleteNode(TreePtr tree, double value) {
	int theResult = 1;

	//1. Find assumed node to delete
	NodePtr theCurrent = tree->root;
	NodePtr theParent = tree->root;

	int isLeftChild = 1;


	while (value != theCurrent->value)
	{
		theParent = theCurrent;
		if (value < theCurrent->value)
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

	//if the node does not have children then just remove it
	if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
	{
		if (tree->root == theCurrent)
		{
			tree->root = NULL;
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
		if (tree->root == theCurrent)
		{
			tree->root = theCurrent->leftChild;
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
		if (tree->root == theCurrent)
		{
			tree->root = theCurrent->rightChild;
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
		NodePtr theSuccessor = getSuccessor(tree, theCurrent);
		if (tree->root == theSuccessor)
		{
			tree->root = NULL;
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

	freeNode(theCurrent);
	theResult = 1;

	return theResult;

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


void showTree(NodePtr treeNode) {
	if (treeNode == NULL) return;

	if (NULL != treeNode->leftChild) {
		showTree(treeNode->leftChild);
	}

	if (treeNode->value) printf("%.2f ", treeNode->value);

	if (NULL != treeNode->rightChild) {
		showTree(treeNode->rightChild);
	}
}


void freeNode(NodePtr aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

void deleteTree(NodePtr rootNode) {
	NodePtr leftChild = rootNode->leftChild;

	if (leftChild != NULL) {
		deleteTree(leftChild);
	}

	NodePtr rightChild = rootNode->rightChild;

	if (rightChild != NULL) {
		deleteTree(rightChild);
	}

	freeNode(rootNode);
}

NodePtr findNode(TreePtr tree, double value) {
	if (NULL == tree) {
		return NULL;
	}

	NodePtr result;
	NodePtr currentNode = tree->root;

	while (1)
	{
		if (value > currentNode->value) {
			currentNode = currentNode->rightChild;
			if (NULL == currentNode) {
				return NULL;
			}
		}
		else if (value < currentNode->value) {
			currentNode = currentNode->leftChild;
			if (NULL == currentNode) {
				return NULL;
			}
		}
		else {
			return currentNode;
		}
	}

	return NULL;
}
