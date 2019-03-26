#define SIZE 3
#include "dktool.h"
void Printmatrix( int A[SIZE][SIZE], int size)
{

		int i,j;
		 for(i=0;i<SIZE;i++)
		 {
   		 printf("\n");
   		 for(j=0;j<SIZE;j++)
			{
     	 printf("% d ",A[i][j]);
    	 }
   		}
  	printf("\n");
  }
