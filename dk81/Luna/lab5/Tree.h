#include "stdio.h"


typedef struct tagNode {
	double value;
	struct tagNode *leftChild;
	struct tagNode *rightChild;
}Node, *NodePtr;

typedef struct tagTree {
	NodePtr root;
}Tree, *TreePtr;

NodePtr createNode(double value);
TreePtr createTree();

NodePtr findNode(TreePtr tree, double value);
void freeNode(NodePtr aNode);
NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);
void addCreatedNode(TreePtr tree, NodePtr node);
void addNode(TreePtr tree, double value);
void deleteNode(TreePtr tree, double value);

void showTree(NodePtr treeNode);
void deleteTree(NodePtr RootNode);
