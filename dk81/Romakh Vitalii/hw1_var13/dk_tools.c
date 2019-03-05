#include "dk_tools.h"

int** createMatrix(int lines, int colums) {
	
	int ** matrix = (int*)malloc(lines * sizeof(int));

	for (int i = 0; i < lines; i++)
	{
		matrix[i] = malloc(colums * sizeof(int));
	}

	return matrix;
}

void fillMatrix(int** matrix, int lines, int colums, int maxRange) {
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < colums; j++)
			matrix[i][j] = rand() % maxRange;
			{
		}
	}
}

void matrixToString(int** matrix, int lines, int colums) {
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < colums; j++)
			printf("[%i]",matrix[i][j]);
			{
			printf("\n");
		}
	}
}

void multiplyMatrixByNum(int** matrix, int lines, int colums, int num) {
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < colums; j++)
			matrix[i][j] *= num;
			{
		}
	}
}