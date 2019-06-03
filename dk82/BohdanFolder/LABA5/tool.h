#ifndef tool_h
#define tool_h
#include <stdio.h>

typedef struct tagNode Node;

struct tagNode
{
	int value;
	Node* leftChild;
	Node* rightChild;
};

typedef struct tagTree
{
	Node* root;
	int count;
}Tree;

Tree* createTree();
Node* createNodeWithValue(int aValue);
void printTree(Node* aNode);
void insertValueToTree(Tree* aTree, int aValue);
Node* destroyTreeNode(Node* treeRoot, int aValue);
Node* getSuccessor(Node* aDelNode);
Node* findNodeWithValue(Tree* aTree, int aValue);
void destroyNode(Node* aNode);
void destroyTree(Tree* aTree);



#endif