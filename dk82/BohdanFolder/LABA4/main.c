#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


int main(int argc, const char* argv[])
{
	List* list = createList();
	int elem;
	
	printf("Enter the number of elements:");
	scanf_s("%d", &elem);
	addElements(list, elem);

	printList(list);
	printf("Max = %d\n", searchMax(list));
	printf("Count = %d\n", countBeforeMax(list, searchMax(list)));
	printf("\n");
	bubbleSort(list, countBeforeMax(list, searchMax(list)));
	printList(list);

	destroyList(list);
	return 0;
}
