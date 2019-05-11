#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"
#include <stdlib.h>
#include <malloc.h>



int* fillarray(int row, int col)
{
	if (0 == row || 0 == col)
	{
		printf("You have not set the matrix correctly\n");
		return 0;
	}
	else
	{
		int* matrix = (int*)malloc(row * col * sizeof(int));

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("a[%d][%d] = ", i, j);
				scanf_s("%d", (matrix + i * col + j));
			}
		}
		return(matrix);
	}

}

void printarray(int row, int col, int* matrix)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%5d ", *(matrix + i * col + j));
		}
		printf("\n");
	}
}

int* multiply(int multyplier, int* matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(matrix + i * col + j) = *(matrix + i * col + j) * multyplier;
		}
	}
	return(matrix);
}
