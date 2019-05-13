#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tool.h"

int main(int argc, char * argv[])
{
	printf("Enter your string :");
	char str[1000];
	gets(str);
	printf("\n");
	
	printf("Enter your string :");
	char toFind[1000];
	gets(toFind);
	printf("\n");
	
	printf("Result: %i\n", find(str, toFind));

	system("pause");
	return 0;
}