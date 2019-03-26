#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
#include <time.h>
#include "dktool.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[])
{
	
  int A[SIZE][SIZE];
  int B[SIZE][SIZE];
  /*
  int i,j;
  
  srand(time(NULL));
  	for(i=0;i<SIZE;i++){
    	for (j = 0; j < SIZE; j++){
    		A[i][j]=0 + rand() % 2;
		}
	}
  /*
   for(i=0;i<SIZE;i++){
   
      printf("\n");
      	for(j=0;j<SIZE;j++)
      printf("% d ",A[i][j]);
   }
  printf("\n");
  */
  Matrixinputting(A,SIZE);
  TransponateMatrix(A, B, SIZE);
  PrintmatrixB(B,SIZE);
  Printmatrix(A,SIZE);
  /*  
  for(i=0;i<size;i++)
    for(j=0;j<size;j++)
    B[j][i]=A[i][j];
 
for(i=0;i<size;i++)
   {
      printf("\n");
      for(j=0;j<size;j++)
      printf("% d ",B[i][j]);
   }
      printf("\n");
      */
    return (0);
}
