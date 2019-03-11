#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "tool.h"

float getA()
	{
		int flag = 0;
		float a;
		printf("Enter number A\n");
		
		
		while (flag == 0)
			{
				scanf("%f", &a);
				//a = getchar();
				if (a>=0 && a == floor(a))
					{
					flag = 1;
					}
				else
					{
					printf("Input error\nEnter number A\n");
					}
			}
		return a;
	}

float getB()
	{
		int flag = 0;
		float b;
		printf("Enter number B\n");
		
		
		while (flag == 0)
			{
				scanf("%f", &b);
				if (b!=0)
					{
					flag = 1;
					}
				else
					{
					printf("Input error\nEnter number B\n");
					}
			}
		return b;
	}

float getC()
	{
		int flag = 0;
		float c;
		printf("Enter number C\n");
		
		
		while (flag == 0)
			{
				scanf("%f", &c);
				if (c>0 && c == floor(c))
					{
					flag = 1;
					}
				else
					{
					printf("Input error\nEnter number C\n");
					}
			}
		return c;
	}
	
int sumOfFactorials(int a, int c)
	{
		int d = 0;
		int result = 0;
		
		for (d = 0; d<=c; d++)
			{
				result = result + factorial(a, d);
			}
		return result;
	}
	
int factorial(int a, int d)
	{
		int result = 1;
		int m = a+d;
		while (m>0)
			{
			result = result * m;
			m--;
			}
		
		return result;
	}

