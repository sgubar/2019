#include <stdio.h>
#include "tool.h"

int summ(int D)
{
	int result = 0;
	
	for (int i = 1; i <= D; i++)
	{
		result = result * i;
	}
	return result;
}

int hex_to_dec(char *F) 
{
	int len = strlen(F);
	int base = 1;
	int dec_val = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		if (F[i] >= '0' && F[i] <= '9')
		{
			dec_val = dec_val + (F[i] - 48)*base;
			base = base * 16;
		}
		else if (F[i] >= 'A' && F[i] <= 'F')
		{
			dec_val = dec_val + (F[i] - 55)*base;
			base = base * 16;
		}
		else if (F[i] >= 'a' && F[i] <= 'f')
		{
			dec_val = dec_val + (F[i] - 87)*base;
			base = base * 16;
		}
		else
		{
			printf("Try again. Use 0-9 and A-F(a-f)\n");
			return ERROR;
		}
	}
	return dec_val;
}

int formula(int F, int C, int D)
{
	int result = 0;
	result = summ(D) * (hex_to_dec(F) - C);
}

int enter(char *name)
{
	int result;
	
	printf("Enter your value %s: ", name);
	scanf_s("%i", &result);
	printf("\n");

	return result;
}