#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PhoneNote
{
	char *name;
}PhoneNote, *PhoneNotePtr;

typedef struct Node
{
	PhoneNotePtr note;
	struct Node *leftChild;
	struct Node *rightChild;
}Node, *NodePtr;

typedef struct Tree
{
	NodePtr root;
}Tree, *TreePtr;

TreePtr createTree();

void displayTree(NodePtr aNode);

NodePtr findNode(TreePtr aTree, const char *aName);
void insertNode(TreePtr aTree, char *aName);
int deleteNode(TreePtr aTree, const char *aName);