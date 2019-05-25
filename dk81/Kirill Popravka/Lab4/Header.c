#include "Header.h"

int structSize(void)
{
	int length;
	printf("write lenght of struct: ");
	scanf("%i", &length);
	printf("\n");

	if (length >= 3) 
	{
		return length;
	}
	else
	{
		exit(1);
	}
}


