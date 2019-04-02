#include <stdio.h>
#include <stdlib.h>
#include "mathf.h"
#include <locale.h>

int main()
{
	int a, b, c;
	setlocale(LC_ALL, "rus");
	printf("¬ведите число а:");
	scanf_s("%d", &a);
	printf("¬ведите число b (b>=0):");
	scanf_s("%d", &b);
	if (b < 0)
		return 0;
	printf("¬ведите число c:");
	scanf_s("%d", &c);
	printf("\n%f", sum(drob(a, b, c), ryad(b)));
	system("pause");
	return 0;
}