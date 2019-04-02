#include "mathf.h"

int ryad(int b)
{
	int result=0;
	for (int i = 0; i <=b; i++)
		result += fact(i);
	return result;
}

int fact(int d)
{
	int sum = 1;
	if (d !=0)
		for (int i = 1; i <= d; i++)
			sum*= i;
	return sum;
}

float drob(int a,int b, int c)
{
	float result = 0.0;
	result = (float)(a * b)/(b+c*c);
	return result;
}

float sum(float x1, int x2)
{
	float result = 0.0;
	result = x1 + x2;
	return result;
}