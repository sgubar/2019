#include <stdio.h>
#include "tool.h"
//#define node 10

int main(int argc, const char * argv[]) 
{
	intTree* tree1 = createIntTree();
	insertIntValueToTree(tree1, 10);
	insertIntValueToTree(tree1, 4);
	insertIntValueToTree(tree1, 3);
	insertIntValueToTree(tree1, 2);
	insertIntValueToTree(tree1, 11);
	insertIntValueToTree(tree1, 13);
	insertIntValueToTree(tree1, 14);
	insertIntValueToTree(tree1, 16);
	insertIntValueToTree(tree1, 17);
	insertIntValueToTree(tree1, 15);
	
	printTree(tree1);
	printf("%d\n\n", findNodeWithValue(tree1, 13)->value);
	deleteNodeWithValue(tree1, 17);
	printTree(tree1);
	deleteNodeWithValue(tree1, 15);
	deleteNodeWithValue(tree1, 16);
	printTree(tree1);
	deleteNodeWithValue(tree1, 4);
	deleteNodeWithValue(tree1, 2);
	deleteNodeWithValue(tree1, 10);
	printTree(tree1);

	destroyIntTree(tree1);
	return 0;
}
