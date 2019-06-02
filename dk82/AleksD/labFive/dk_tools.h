#ifndef dk_tools_h

#define dk_tools_h
#include <stdio.h>

typedef struct tagNode
{
	float value;
	struct tagNode* leftChild;
	struct tagNode* rightChild;
}Node;

typedef struct tagTree
{
	int count;
	Node* root;
}Tree;


Tree* createTree();

void destroyTree(Tree* aTree);
void printTree(Tree *aTree);
void printTree1(Node *aNode, int count);
void addNodeInTree(Tree* aTree , float aValue);
void destroyNode(Node* aNode);
int deleteNodeWithValue(Tree *aTree, float aValue);

Node* getSuccessor(Tree* aTree, Node* aDelNode);
Node* findNodeByIndex(Tree* aTree , float aValue);
Node* createNode(float aValue);

#endif dk_tools_h

