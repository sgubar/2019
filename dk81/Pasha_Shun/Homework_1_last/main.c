//
// Created by World_conspiracy on 30.03.2019.
//
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"


int main() {
    int** Tmatrix;
    int **matrix;
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
    Tmatrix = createTMatrix(row, col);
    setMatrix(matrix, row, col);
    transponMatrix(matrix, Tmatrix, row, col);
    Show_matrix(Tmatrix, row, col);

    return 0;
}