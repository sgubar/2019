#define SIZE 3
#include "dktool.h"

void TransponateMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int size)
{
	int i, j;
	for(i=0;i<size;i++)
    	for(j=0;j<size;j++)
   		   B[j][i]=A[i][j];
}
