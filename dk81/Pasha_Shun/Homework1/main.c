/*
 * DZ-1
 * DK-81
 * Edited by Pasha Shun
 * 19.03.2019
 * Transponed array
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "header.h"


void Matrix(int **pInt, int row, int col);

void transponedMatrix(int **pInt, int row, int col);

int main() {
    int **matrix;  // указатель на указатель строки элементов
    int row, col;

    printf("Hello, please, set width of your matrix:\n");
    scanf("%d", &col);
    printf("Set high of your matrix:\n");
    scanf("%d", &row);

    if (row == 0 || col == 0){
        printf("Wrong input values");
        return 0;
    }
    matrix = createMatrix(row, col);

    setMatrix(matrix, row, col);
    printf("Here is your begining matrix:\n");
    Matrix(matrix, row, col);
    printf("Here is your transponed matrix:\n");
    transponedMatrix(matrix, row, col);

    return 0;
}


