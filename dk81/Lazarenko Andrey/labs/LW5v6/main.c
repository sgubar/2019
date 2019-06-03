#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char **argv)
{
	Tree *aTree = createTree();

	addNode(aTree, 5.1);

	addNode(aTree, 9.1);
	addNode(aTree, 8.1);
	addNode(aTree, 7.1);
	addNode(aTree, 6.1);
	addNode(aTree, 4.1);
	addNode(aTree, 3.1);
	addNode(aTree, 2.1);
	addNode(aTree, 1.1);

	printTree(aTree->root);

	aTree->root = destroyTreeNode(aTree->root, 5.1);

	printf("\n");
	printTree(aTree->root);

	destroyTree(aTree);
	system("pause");
	return 0;
}
