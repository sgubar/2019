#include <stdio.h>
#include <stdlib.h>
#include "func.h"



int main ( )
{
	int a;
	char some[10];
	gets(some);
	for(a = 0; some[a] != '\0'; a ++);
	list *theList = init(a);
	for(;some[0] != '0';)
	{
			gets(some);
			for(a = 0; some[a] != '\0'; a ++);
			addelem(theList, a);
	}
	listprint(theList);
	sort(theList);
	printf("\n\n\n");
	listprint(theList);

}
