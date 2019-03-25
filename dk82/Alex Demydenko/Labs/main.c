#include <stdio.h>
#include "dkmath.h"

int main()
{
	int B, C;
	float A, Q;

	printf("Enter A:\n");
	scanf("%f", &A);
	
	do
	{
		printf("Enter B (int only; > 0):\n");
		scanf("%d", &B);
	}
	while (B < 0);
	
	printf("Enter C:\n");
	scanf("%d", &C);

	Q=((power(A, 2) + power(B, 2)) / (B + power(5, C))) + factorial(B);
	printf("Q is %.4f\n", Q);
	
    return 0;
}
