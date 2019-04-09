#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N  3

int Matrix(void)
{ 
int i = 0;
int **A = (int**)malloc(N * sizeof(int*));
int **B = (int**)malloc(N * sizeof(int*));
int **C = (int**)malloc(N * sizeof(int*));

  for (i = 0; i < N; i++)
    {
      A[i] = (int*)malloc(N * sizeof(int));//
      B[i] = (int*)malloc(N * sizeof(int));
      C[i] = (int*)malloc(N * sizeof(int));
    }
  printf ("matrix A: \n");
 
	for (int i = 0; i < N; i ++)
	{
    printf("\n");
		for (int j = 0; j < N; j ++)
		  {
			  A[i][j] = rand()%10;
			  printf("%i ", A[i][j]);
		  }
	}
	printf ("\nmatrix B: \n");

	for (int i = 0; i < N; i ++)
	{
    printf("\n");
		for (int j = 0; j < N; j ++)
		{
			B[i][j]=rand()%10;
			printf("%i ", B[i][j]);
		}
	}
	printf("\ncalculation result:\n");

 	for (int i = 0; i < N; i++)
  {
    printf("\n");
 		for (int j = 0; j < N; j++)
 		{
 			C[i][j] = A[i][j] - B[i][j];
 			printf("%i ", C[i][j]);
 		}
 	}
    for (i = 0; i < N; i++)
    {
      free(A[i]);
      free(B[i]);
      free(C[i]);
    }
  free(A);
  free(B);
  free(C);
return 0 ;
}