#include "foool.h"
#include <stdio.h> 
#define N 2

int main() 
{ 
	int mat1[N][N] = { { 1, 1}, 
					   { 1, 1}}; 
				
	int mat2[N][N] = { { 1, 1}, 
					   { 1, 1}}; 
printf("mat1 \n");
vivod( mat1);
printf("mat1 \n");
vivod( mat2);
	int res[N][N]; // ðåçóëüòàò
	int i, j; 
	multiply(mat1, mat2, res); 

	printf("Result matrix is \n"); 
	vivod( res);

	return 0; 
} 
