#include <stdio.h>
#include "dkmath.h"

int factorial (int number)
{
	int result = 1;
	int i;
	for (i = 1; i <= number; i++)
		result *= i;

	return result;
}
	
float power(float number, int step)
{
	float result = 1;
	int i;
	for (i = 0; i < mod(step); i++)
		result *= number;
    
	return (step > 0) ? (result) : (1.0/result);
}

float mod(float number)
{
	return (number < 0) ? (number * (-1)) : number;
}

