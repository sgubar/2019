#include <stdio.h>
#include "functions.h"

int main() 
{
	int A, B, C;
	
	printf("Enter number A: ");	
	scanf("%i ", &A);
	printf("Enter number B: ");
	scanf("%i ", &B);
	printf("Enter number C: ");
	scanf("%i ", &C);
	
	if(B == 0)
	{
		printf("ERROR: division by zero!");
	}else{
		printf("%.3f ", A * sqrt(B+C) / B + sum_fact(C, A) );
	}
	return 0;
}
