#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tool.h"

double q(int a, int b, int c);

int main(void) {
	printf("Your result: %f\n", q(3, 3, 1));
	system("pause");
	return 0;
}


double q(int a, int b, int c)
{
	double result = ((poweri(a, 2) + poweri(b, 2)) / (b + poweri(5, c))) + fac(b);
	return result;
}
