#include "tool.h"

void main(void) {

	int A, B, C;

	scanf_s("%i", &A);
	scanf_s("%i", &B);
	scanf_s("%i", &C);


	float Output = ((float)module(A * C - B) / (float)stage(C, 3)) * sum(stage(2, A), A);

	printf("%f\n", Output);


	system("pause");
}