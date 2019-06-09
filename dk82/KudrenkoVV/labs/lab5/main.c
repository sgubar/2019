#include "tool.h"

void main() {
	TreePtr theTree = createTree();
	insertNode(theTree, "aab");
	insertNode(theTree, "aaa");
	insertNode(theTree, "acc");
	insertNode(theTree, "baa");
	displayTree(theTree->root);
	system("pause");
	return 0;
}