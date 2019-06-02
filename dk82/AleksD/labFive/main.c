#include <stdio.h>
#include "dk_tools.h"
#define SIZE 8
int main(int argc, const char * argv[]) 
{
	 srand(time(NULL));
	Tree* tree = createTree();
	int i ;
    float random;
    float value;
	for (i = 0 ; i < SIZE ; i ++ )
	 {
	   random = 1 + rand() % 50;
	   	addNodeInTree(tree , random);
	 }


	 printTree(tree);
 	printf("enter value who you want to search and delete\n");
 	scanf("%f",&value);
	findNodeByIndex(tree,value);
	deleteNodeWithValue(tree, value);
	printTree(tree);
	destroyTree(tree);
	return 0;
}

