#define SIZE 3
#include "dktool.h"
#include <time.h>
void Matrixinputting(int A[SIZE][SIZE], int size)
{
int i,j
;
	srand(time(NULL));
  	for(i=0;i<SIZE;i++){
    	for (j = 0; j < SIZE; j++){
    		
    		A[i][j]= rand();

		}
	}
}
