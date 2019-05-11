#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char* argv[])
{
	int row, col;
	int multyplier;

	printf("Row: ");
	scanf_s("%d", &row);
	printf("Col: ");
	scanf_s("%d", &col);

	int* matrix = fillarray(row, col);
	printarray(row, col, matrix);

	if (NULL != matrix)
	{
		printf("Multyplier: ");
		scanf_s("%d", &multyplier);

		multiply(multyplier, matrix, row, col);
		printarray(row, col, matrix);
		free(matrix);
	}

}

