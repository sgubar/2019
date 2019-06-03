#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include <string.h>
#include "lists.h"
#pragma warning(disable:4996)


void getArr(FILE* f)
{
	char buffer[1000];
	char* c;
	int j = 0;
	int i = 0;
	i = lenRow(f);
	FILE* fo;
	fo = fopen("Result.txt", "wt");
	f = fopen("text.txt", "rt");
	for (int k = 0; k < i; k++)
	{
		List* theList = createList();
		fgets(buffer, 256, f);
		j = strlen(buffer);
		printf("%s", buffer);
		c = strtok(buffer, " ");
		while (c != NULL) //
		{
			printf("\n%s", c);
			addLineToList(theList, c);
			c = strtok(NULL, " ,.\n");
		}
		for (int lent = 0; lent < theList->count / 2; lent++)
			swap(theList, lent, theList->count - lent - 1);
		Node * theNode = theList->first;
		printf("\n");
		while (theNode != NULL)
		{
			fprintf(fo, "%s  ", theNode->arr);
			printf("%s  ", theNode->arr);
			theNode = theNode->next;
		}
		destroyList(theList);
		printf("\n");
		fprintf(fo, "\n");
		j++;
	}
	fflush(f);
	fclose(f);
	fclose(fo);
}

int lenRow(FILE* fo)
{
	int line_count = 0;
	while (!feof(fo))
	{
		if (fgetc(fo) == '\n')
			line_count++;
	}
	fclose(fo);
	return line_count;
}