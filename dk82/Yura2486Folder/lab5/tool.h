#ifndef tool_h
#define tool_h

#include <stdio.h>

typedef struct tagNode
{
	float value;
	struct tagNode *leftChild;
	struct tagNode *rightChild;
}intNode;

typedef struct tagTree
{
	intNode *root;
	int count;
}intTree;

intTree *createIntTree();
intNode *findNodeWithValue(intTree *aTree, float aValue);
intNode *createIntNodeWithValue(float aValue);
intNode *findParentNode(intTree *aTree, intNode* aNode);
intNode* getSuccessor(intTree* aTree, intNode* currentNode);

int countNodesWithTree(intTree *aTree);
int deleteNodeWithValue(intTree *aTree, float aValue);

void destroyIntTree(intTree *aTree);
void insertIntValueToTree(intTree *aTree, float aValue);
void printTree1(intNode *aNode, int count);
void printTree(intTree *aTree); //helping function
void destroyNode(intNode *aNode);


#endif /* tool_h */

