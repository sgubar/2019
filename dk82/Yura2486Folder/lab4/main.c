#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

int main(int argc, const char* argv[])
{
	intList *list1 = createList();
	addNElementsInList(list1, 10);
	
	printList(list1);
	bubbleSort(list1);
	printList(list1);
	
	freeList(list1);
	return 0;
}
