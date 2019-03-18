#include <stdio.h>
#include "dk_tool.h"

int main() 
{
	int A[2][3] = {{1,2,3}, {4,7,0}};
	int B[3][3] = {{1,2,5}, {0,9,3}, {4,4,7}};
	int C[3][3] = {{0,1,0}, {2,3,0}, {6,4,8}};
	int arr[5] = {1,2,3,4,5};
	char str[8];
	
	/*C_mult(2, 3, A, 2);
	printf("\n");
	matrix_mult(3, B, C);
	printf("\n");
	matrix_sum(3, 3, B, C, '-');
	printf("\n");
	permutation(5, arr);
	printf("\n");*/
  gets(str);
	printf("%i \n", BIN_decoder(str));
	//printf("%i \n", OCT_decoder(str));
	//printf("%i \n", HEX_decoder(str));
		
	return 0;
}
