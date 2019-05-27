#include "tree.h"

int main(int argc, char **argv)
{
	Tree *ATree = createTree();
	
	addNode(ATree, 15.5 );
	addNode(ATree, 5.5 );
	addNode(ATree, 17.5 );
	addNode(ATree, 2 );
	addNode(ATree, 10 );
	addNode(ATree, 19.5 );
	
	printTree(ATree->root);
	
	ATree->root = destroyTreeNode(ATree->root, 15.5);
	
	printf("\n");
	printTree(ATree->root);
	
	destroyTree(ATree);
	return 0;
}
