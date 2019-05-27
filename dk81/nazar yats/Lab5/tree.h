#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_h
#define LIST_h

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//structures
typedef struct tagNode Node;

struct tagNode
{
	double value;
	Node *leftChild;
	Node *rightChild;
};

typedef struct tagTree
{
	Node *root;
	int count;
}Tree;

Tree *createTree();
void destroyTree(Tree *aTree);
Node *createNode(double aValue);
void destroyNode(Node *aNode);

Node *destroyTreeNode(Node *treeRoot, double aValue);
Node *getSuccessor(Node *treeRoot);
void addNode(Tree *aTree, double aValue);
Node *findNode(Tree *aTree, double aValue);

void printTree(Node *aNode);

#endif
