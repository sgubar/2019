#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

int main(int argc, const char* argv[])
{
	intNode *theNode2 = createNodeWithIntValue(2);
	intNode *theNode4 = createNodeWithIntValue(4);
	
	intList *theList = createList();
	printf("number of elements: %d\n", countList(theList));
	
	addNode(theList, theNode2);
	printf("number of elements: %d\n", countList(theList));

	addNode(theList, theNode4);
	printf("number of elements: %d\n", countList(theList));
	
	addNode(theList, createNodeWithIntValue(7));
	addNode(theList, createNodeWithIntValue(8));

	intNode *theNode = createNodeWithIntValue(5);
	
	insertNodeAtIndex(theList, theNode, 4);
	insertNodeAtIndex(theList, createNodeWithIntValue(10), 4);
	
	printList(theList);
	theNode = removedNodeAtIndex(theList, 4);
	insertNodeAtIndex(theList, theNode, 2);
	

	printf("After removing: \n");
	printList(theList);
	
	printf("Sorting: \n");
	quickSort(theList, 0, theList->count - 1);
	
	printList(theList);
	
	freeList(theList);
	return 0;
}


