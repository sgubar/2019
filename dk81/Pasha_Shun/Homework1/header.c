//
// Created by World_conspiracy on 19.03.2019.
//
#include <stdlib.h>
#include <stdio.h>
#include "header.h"


int** createMatrix(int row, int col) {

    int ** matrix = (int*) malloc(row * sizeof(int));

    for (int i = 0; i < row; i++)
    {
        matrix[i] = malloc(col * sizeof(int));
    }

    return matrix;
}
void setMatrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("matrix [%d][%d]:", i, j);
            scanf("%d", &matrix[i][j]);
            printf("\n");
        }
    }
}
void Matrix(int** matrix, int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
void transponedMatrix(int** matrix, int row, int col) {
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}