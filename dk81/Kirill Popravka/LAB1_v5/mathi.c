#include "mathi.h"

int stage(int inValue, int inStage)
{
	int value = 1;

	for (int i = 0; i < inStage; i++)
	{
		value *= inValue;
	}

	return value;
}

int factorial(int inValue)
{
	int value = 1;

	for (int i = 0; i < inValue; i++)
	{
		value *= (inValue - i);
	}

	return value;
}

double operation(int a, int b, int c)
{
	double res = ((stage(a, 2) + stage(b, 2)) / (b + stage(5, c))) + factorial(b);
	return res;
}
