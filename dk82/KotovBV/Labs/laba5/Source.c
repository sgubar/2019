#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "tool.h"
#pragma warning(disable:4996)
int main(int argc, const char* argv[])
{
	TreePtr theTree = createTree();

	insertNode(theTree, 5);
	insertNode(theTree, 1.233);
	insertNode(theTree, 7);
	insertNode(theTree, 6.335);
	insertNode(theTree, 7.335);
	insertNode(theTree, 4);
	insertNode(theTree, 3);
	PrintTreeinorderPrint(theTree->root);
	NodePtr theFindNode = findNode(theTree, 5.0);
	//printf("\n%d\n", deleteNode(theTree, 6.335));
	if (deleteNode(theTree, 5.0))
	{
		//theFindNode = findNode(theTree, 5.0);
		printf("find result: %f\n", theFindNode->note->name);
	}
	PrintTreeinorderPrint(theTree->root);

	// insert code here...
	printf("Hello, World!\n");
	return 0;
}

