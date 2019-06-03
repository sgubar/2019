#ifndef tool_h
#define tool_h

#include <stdio.h>

typedef struct __PhoneNote
{
	double name;
}PhoneNote, * PhoneNotePtr;

typedef struct __Node
{
	PhoneNotePtr note;
	struct __Node* leftChild;
	struct __Node* rightChild;
}Node, * NodePtr;

typedef struct __Tree
{
	NodePtr root;
}Tree, * TreePtr;

TreePtr createTree();
void deleteTree(TreePtr aTree);

int countTree(TreePtr aTree);
void displayTree(TreePtr aTree);

NodePtr findNode(TreePtr aTree, const double aName);
void insertNode(TreePtr aTree, double aName);
int deleteNode(TreePtr aTree, const double aName);
NodePtr getSuccessor(TreePtr aTree, NodePtr aDelNode);
void PrintTreeinorderPrint(NodePtr aNode);
#endif /* tree_h */