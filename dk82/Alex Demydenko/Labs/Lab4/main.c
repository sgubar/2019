#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define SIZE 9
#define DEL_IDX 3 
int main(int argc, char **argv)
{
	srand(time(NULL));
	

 List *ListOfNumbers = createList();
	
	for (int i = 0; i < SIZE; i++)
	{
		addNode(ListOfNumbers, createNode(i));
	}

	printf("\n###List###\n");
	printList(ListOfNumbers);
	printf("\n");
	 DeleteIndex (ListOfNumbers,DEL_IDX);
	
/*	int i = 1;
	while (ListOfNumbers->count >= DEL_IDX)
	{
		destroyNodeAtIndex(ListOfNumbers, DEL_IDX - 1);
		
		printf("###%d###\n", i);
		printList(ListOfNumbers);
		printf("\n");
		
		i++;		
	}
	*/
	
	destroyList(ListOfNumbers);

	return 0;
}
