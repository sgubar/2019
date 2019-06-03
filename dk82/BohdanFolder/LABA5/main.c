#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char* argv[])
{
	Tree* ShortTree = createTree();
	
	printf("Symmetric Tree:\n");
	insertValueToTree(ShortTree, 8);
	insertValueToTree(ShortTree, 5);
	insertValueToTree(ShortTree, 13);
	insertValueToTree(ShortTree, 2);
	insertValueToTree(ShortTree, 10);
	insertValueToTree(ShortTree, 9);

	printTree(ShortTree->root);

	ShortTree->root = destroyTreeNode(ShortTree->root, 2);
	
	printf("\n");
	printTree(ShortTree->root);


	destroyTree(ShortTree);
	return 0;
}