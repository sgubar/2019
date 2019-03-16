#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "tools.h"
	
float variableA()
{
	float a;
	
		printf_s("Enter variable A\n");
		scanf_s("%f", &a);
	
	return a;
}
float variableB()
{
	
	float b;
	
		printf_s("Enter variable B\n");
		scanf_s("%f", &b);
	
	return b;
}
float variableC()
{
	float c;
	
		printf_s("Enter variable C\n");
		scanf_s("%f", &c);
	
	return c;
}
float division(int a, int b, int c)
{
	float m ;
	float q = 100 - b - c;

	if (q != 0)
	{
		q = q;
	}
	else
	{
		printf_s("Error\n");
	}

	m =   (a + b + c) / q;

	return m;
}

float suma(int a)
{
	int lowerbound = 0;
	int res = 0;

	for (lowerbound = 0; lowerbound <= a; lowerbound++)
	{
		res = res + stepin(a, lowerbound);
	}
	return res;
}
float stepin(int a, int lowerbound)
{
	int t;
	int y = a + lowerbound;
	t = pow(2, y);
	return t;
}
