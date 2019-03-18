#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tool.h"

int main(int argc, char * argv[])
{
	char a[100];
	char b[100];
	int strF;
	

	printf("Enter your string :");
	scanf_s("%c", &a);
	while (getchar() != '\n');
	printf("\n");
	
	printf("Enter find string :");
	scanf_s("%c", &b);
	printf("\n");

	strF = find(a, b);
	printf("Result: %d", strF);

	system("pause");
	return 0;
}