#include "functions.h"

float sqrt(int n)
{
	float a=0.0;
	while(a*a < n)
	a += 1;
		
	while(a*a > n)
	a -= 0.001;
	
	return a;
}

int factorial(int n)
{
	int a=1;
	while(n != 0)
	{
		a *= n;
		n--;
	}
	return a;
}

int sum_fact(int n, int f)
{
	int i=0, sum=0;
	while(i<=n)
	{
		sum += factorial(f+i);
		i++;
	}
	return sum;
}
