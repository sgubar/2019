#include <stdio.h>
#include "function.h"

int sum_of (int d, int n, int additive)
{
	int num = 0;
	for (int i = d; i <= n; i++)
		num += additive;
	
	return num;
}

double square (double num)
{
	return (num * num);
}

int factorial (int number)
{
	int result = 1;
	for (int i = 1; i <= number; i++)
		result *= i;

	return result;
}
