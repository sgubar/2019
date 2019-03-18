#include "mathi.h"

void main()
{
	int a, b, c;

	printf("value A = ");
	scanf_s("%i", &a);

	while (1) {
		printf("value B = ");
		scanf_s("%i", &b);
		if (b < 0) {
			printf("invalid input, b must be greater than 0\n");
		}
		else
			break;
	}

	printf("value C = ");
	scanf_s("%i", &c);

	double result = operation(a, b, c);
	printf("\nThe result is %.2lf\n", result);

	system("pause");
}

