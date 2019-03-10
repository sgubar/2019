#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void matr_print(int * p_m, int col, int row)
{
	for (int i = 1; i < col * row + 1; i++)
	{
		if (*p_m < 0)
			printf("[%d]", *p_m);
		else
			printf("[ %d]", *p_m);
		
		if (i % row == 0)
		{
			printf("\n");
		}
		
		p_m++;
	}
	printf("\n");
}

void matr_rand(int * p_m, int col, int row)
{
	for (int i = 0; i < col * row; i++){
		*p_m = 0 + rand() % 2;
		p_m++;
	}
}

void matr_add(int * p_mA, int * p_mB, int * p_mC, int col, int row)
{
	for (int i = 0; i < col * row; i++){
		*p_mC = *p_mA + *p_mB;
		p_mA++;
		p_mB++;
		p_mC++;
	}
}

void matr_sub(int * p_mA, int * p_mB, int * p_mC, int col, int row)
{
	for (int i = 0; i < col * row; i++){
		*p_mC = *p_mA - *p_mB;
		p_mA++;
		p_mB++;
		p_mC++;
	}
}

void matr_multBy(int * p_mC, int col, int row)
{
	int num;
	printf("Enter an integer:\n");
	scanf("%d", &num);
	
	for (int i = 0; i < col * row; i++){
		*p_mC = *p_mC * num;
		p_mC++;
	}
}
