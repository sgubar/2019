//
// Created by World_conspiracy on 30.03.2019.
//
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int** createMatrix(int row, int col) {

    int ** matrix = (int**) malloc(row * sizeof(int*));

    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }

    return matrix;
}

int** createTMatrix(int row, int col) {

    int ** Tmatrix = (int**) malloc(row * sizeof(int*));

    for (int i = 0; i < row; i++)
    {
        Tmatrix[i] = malloc(col * sizeof(int));
    }

    return Tmatrix;
}

void setMatrix(int** matrix, int row, int col) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //printf("LoL\n");
           printf("[%d] [%d]", i, j);
           scanf("%d", &matrix[i][j]);
        }
    }
}

int** transponMatrix(int** matrix, int** Tmatrix, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            Tmatrix[i][j] = matrix[j][i];
            int temp = col;
            col = row;
            row = temp;
        }
    }
    return Tmatrix;
}

void Show_matrix(int** Tmatrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            printf("%4d", Tmatrix[i][j]);
        }
        printf("\n");
    }
}
