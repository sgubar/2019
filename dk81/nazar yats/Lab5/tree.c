#include "tree.h"

Tree *createTree()
{
	Tree *aTree = (Tree *)malloc(sizeof(Tree));
	
	if (NULL != aTree)
	{
		aTree->root = NULL;
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

Node *createNode(double aValue)
{
	Node *theNode = (Node *)malloc(sizeof(Node));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}

	//operations
void destroyNode(Node *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

Node *destroyTreeNode(Node *treeRoot, double value) 
{ 
    if (treeRoot == NULL)
		return treeRoot; 
  
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
        if (treeRoot->leftChild == NULL) 
        { 
            Node *tempNode = treeRoot->rightChild; 
            destroyNode(treeRoot);
            return tempNode; 
        } 
        else if (treeRoot->rightChild == NULL) 
        { 
            Node *tempNode = treeRoot->leftChild; 
            destroyNode(treeRoot);
            return tempNode; 
        }
        
        //node with children
        Node *tempNode = getSuccessor(treeRoot); 
        treeRoot->value = tempNode->value; 
        treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, tempNode->value); 
    } 
    return treeRoot; 
} 

Node *getSuccessor(Node *aDelNode)
{
	Node *theSuccessParent = aDelNode;
	Node *theSuccessor = aDelNode;
	Node *theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present
	
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

void addNode(Tree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	Node *theNode = createNode(aValue);
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
		Node *theCurrent = aTree->root;
		Node *theParent = NULL;

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

Node *findNode(Tree *aTree, double aValue)
{
	Node *theCurrentNode = NULL;
	
	if (NULL != aTree)
	{
		Node *theCurrentNode = aTree->root;	//start from root
		while (aValue != theCurrentNode->value) //walk through the tree
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

	//misc actions
void printTree(Node *aNode)
{
	if (NULL != aNode)
	{
		printTree(aNode->leftChild);
		printf("[%f]\n", aNode->value);
		printTree(aNode->rightChild);
	}
}
