#include <stdio.h>
#include "tool.h"
//#define node 10

int main(int argc, const char * argv[]) 
{
	intTree* tree1 = createIntTree();
	insertIntValueToTree(tree1, 10.0);
	insertIntValueToTree(tree1, 4.1);
	insertIntValueToTree(tree1, 3.0);
	insertIntValueToTree(tree1, 2.0);
	insertIntValueToTree(tree1, 11.0);
	insertIntValueToTree(tree1, 13.0);
	insertIntValueToTree(tree1, 14.0);
	insertIntValueToTree(tree1, 16.0);
	insertIntValueToTree(tree1, 17.0);
	
	printTree(tree1);
	printf("%.2f\n\n", findNodeWithValue(tree1, 13.0)->value);
	deleteNodeWithValue(tree1, 10.0);
	printTree(tree1);
	deleteNodeWithValue(tree1, 3.0);
	printTree(tree1);
	deleteNodeWithValue(tree1, 16.0);
	printTree(tree1);
	deleteNodeWithValue(tree1, 17.0);
	printTree(tree1);
	insertIntValueToTree(tree1, 15.0);
	printTree(tree1);
	deleteNodeWithValue(tree1, 15.0);
	printTree(tree1);
	destroyIntTree(tree1);
	return 0;
}
