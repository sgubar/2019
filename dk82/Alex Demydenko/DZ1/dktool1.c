#define SIZE 3
#include "dktool.h"

void PrintmatrixB( int B[SIZE][SIZE], int size)
{
	int i,j;
	for(i=0;i<size;i++)
   {
      printf("\n");
      for(j=0;j<size;j++)
      printf(" %d ",B[i][j]);
   }
      printf("\n");
}
