#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tool.h"

int main(int argc, char * argv) 
{
	char F[100];
	printf("Enter value for F: ");
	scanf("%s", F);
	int F_dec = hex_to_dec(F);
	printf("%d\n", F_dec);

	int C = enter("C");
	int D = enter("D");
	
	int result;
	result = formula(F, C, D);
	printf("Your result: %d", result);
	printf("\n");
	
	system("pause");
} 