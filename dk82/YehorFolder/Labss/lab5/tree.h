#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
	DoubleNode *root;
	int counter;
} DoubleTree;


DoubleTree *createDoubleTree();

void destroyDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);

void PrintTreeInPreOrder(DoubleNode* aNode);

void destroyNode(DoubleNode *aNode);

DoubleNode *createDoubleNodeWithValue(double aValue);

int deleteNodeWithValue(DoubleTree* aTree, int aValue);

DoubleNode* getSuccessor(DoubleTree* aTree, DoubleNode* aDelNode);
#endif // TREE_H_INCLUDED
