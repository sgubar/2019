#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tool.h"

#pragma warning(disable:4996)
int main()
{
	setlocale(LC_ALL, "Rus");
	double average = 0.0;
	List* theList = createList();
	
	addLineToList(theList, 33);
	addLineToList(theList, 35);
	addLineToList(theList, 42);
	addLineToList(theList, 30);
	addLineToList(theList, 7);
	addLineToList(theList, 42);
	
	Node* theNode = theList->first;
	while (theNode != NULL)
	{
		average += theNode->arr;
		theNode = theNode->next;
	}
	average = average / theList->count;
	
	printf("Average=%f\n", average);
	
	theNode = theList->first;
	SLRemovedNodeAtIndex(theList, average);
	theNode = theList->first;
	while (theNode != NULL)
	{
		printf("%d\n", theNode->arr);
		theNode = theNode->next;
	}
	
	system("pause");
	return 0;
}