#include "tree.h"

BinTree *createBinTree()
{
	BinTree *aTree = (BinTree *)malloc(sizeof(BinTree));
	
	if (NULL != aTree)
	{
		aTree->root = NULL;
		aTree->count = 0;
	}
	
	return aTree;
}

void destroyBinTree(BinTree *aTree)
{
	if (NULL != aTree)
	{
		free(aTree);
	}
}

Node *createNode(int aValue)
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

Node *destroyTreeNode(Node *treeRoot, int value) 
{ 
    if (treeRoot == NULL)
		return treeRoot; 
  
    if (value < treeRoot->value) 
        treeRoot->leftChild = destroyTreeNode(treeRoot->leftChild, value); 
  
    else if (value > treeRoot->value) 
        treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, value); 
  
    else
    { 
		//node either without any or with left or right child
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
        Node *tempNode = getSuccessor(treeRoot->rightChild); 
        treeRoot->value = tempNode->value; 
        treeRoot->rightChild = destroyTreeNode(treeRoot->rightChild, tempNode->value); 
    } 
    return treeRoot; 
} 

Node *getSuccessor(Node *treeRoot)
{ 
    Node *theCurrent = treeRoot; 
  
    while (theCurrent && theCurrent->leftChild != NULL) 
        theCurrent = theCurrent->leftChild; 
  
    return theCurrent; 
} 

void addNode(BinTree *aTree, int aValue)
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

Node *findNode(BinTree *aTree, int aValue)
{
	Node *theCurrentNode = NULL;
	
	if (NULL != aTree->root)
	{
		theCurrentNode = aTree->root;	//start from root
		while (aValue != theCurrentNode->value) //walk through the tree
		{	
					
			if (aValue < theCurrentNode->value)
				theCurrentNode = theCurrentNode->leftChild;
			else
				theCurrentNode = theCurrentNode->rightChild;
			
			if (NULL == theCurrentNode)
				break;
		}
	}
	
	return theCurrentNode;
}

	//misc actions
void printBinTree(Node *aNode)
{
	if (NULL != aNode)
	{
		printBinTree(aNode->leftChild);
		printBinTree(aNode->rightChild);
		printf("[%d]\n", aNode->value);
	}
}

void drawBinTree(Node *aNode, int x, int y, int d)
{
	if (NULL != aNode)
	{
		drawBinTree(aNode->leftChild, x - d/2, y + 4, d/2);
		drawBinTree(aNode->rightChild, x + d/2, y + 4, d/2);
		mvprintw(y, x - 1, "[%d]", aNode->value);
		
		if (NULL != aNode->leftChild)
		{
			attroff(A_BOLD);	
			
			mvaddch(y + 1, x, '|');
			mvaddch(y + 3, x - d/2, '|');
			
			mvaddch(y + 2, x - d/2, '.');
			
			for (int i = (x - d/2) + 1; i < x; i++)
				mvaddch(y + 2, i, '-');
				
			mvaddch(y + 2, x, '/');
			attron(A_BOLD);
		}
		if (NULL != aNode->rightChild)
		{
			attroff(A_BOLD);	
			
			mvaddch(y + 1, x, '|');
			mvaddch(y + 3, x + d/2, '|');
			
			mvaddch(y + 2, x + d/2, '.');
			
			for (int i = x + 1; i < (x + d/2); i++)
				mvaddch(y + 2, i, '-');
				
			mvaddch(y + 2, x, '\\');
			attron(A_BOLD);
		}
		if (NULL != aNode->leftChild && NULL != aNode->rightChild)
		{
			attroff(A_BOLD);	
			
			mvaddch(y + 1, x, '|');
			mvaddch(y + 3, x + d/2, '|');
			mvaddch(y + 3, x - d/2, '|');
			
			mvaddch(y + 2, x - d/2, '.');
			mvaddch(y + 2, x + d/2, '.');
			
			for (int i = (x - d/2) + 1; i < (x + d/2); i++)
				mvaddch(y + 2, i, '-');
				
			mvaddch(y + 2, x, '^');
			attron(A_BOLD);
		}
	}
}
