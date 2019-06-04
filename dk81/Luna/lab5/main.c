#include "Tree.h"

void main() {
	TreePtr theTree = createTree();

	addNode(theTree, 10);
	addNode(theTree, 2);
	addNode(theTree, 12);
	addNode(theTree, 53);
	addNode(theTree, -3);
	addNode(theTree, -5);
	addNode(theTree, 100);
	addNode(theTree, -27);


	showTree(theTree->root);

	deleteNode(theTree, -5);
	printf("\n");
	showTree(theTree->root);

	NodePtr search = findNode(theTree, -3);
	if (search != NULL) {
		search->value = -6;
	}

	printf("\n");
	printf("\n");

	showTree(theTree->root);
	deleteTree(theTree->root);

	system("pause");
	return 0;
}
