#include <stdio.h>
#include "dk_tools.h"

int main(int argc, char * argv[]) {
	int** matrix;

	int lines;
	int colums;
	int range;
	int num;

	printf("Input lines quantity\n");
	scanf_s("%i",&lines);
	if (lines < 0) lines *= -1;

	printf("Input colums quantity\n");
	scanf_s("%i", &colums);
	if (colums < 0) colums *= -1;

	printf("Input range\n");
	scanf_s("%i", &range);


	printf("Input number for multiplying\n");
	scanf_s("%i", &num);

	if (lines == 0 || colums == 0 || range == 0) {
		printf("Wrong input\n");
	}


	matrix = createMatrix(lines, colums);
	fillMatrix(matrix, lines, colums, range);
	matrixToString(matrix, lines,colums);
	multiplyMatrixByNum(matrix, lines, colums, num);

	printf("---------------------------\n");

	matrixToString(matrix, lines, colums);
	system("pause");
}