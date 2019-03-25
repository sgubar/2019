/*Функция вычисляет математическое выражение*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <C:\Users\123\Documents\local_ishodniki\lab1_var2_mnozh_dil\header.h>

int main()
{
	int a, b, c, d=0;
	printf("This program calculates expression\n");
	printf("Enter data A\n");
	scanf("%i", &a);
	while (a < 0)
	{
		printf("Wrong data! 'A' should be >0\n");
		printf("Try again\n");
		scanf("%i", &a);
	}
	printf("Enter data B\n");
	scanf("%i", &b);
	printf("Enter data C\n");
	scanf("%i", &c);
	while (c == 0)
	{
		printf("Wrong data! 'C' shouldn`t be '0'\n");
		printf("Try again\n");
		scanf("%i", &a);
	}
	float res = module(a*c - b) / power(c, 3);
	printf("The result is: %f", res);
	system("pause");
	return 0;
}
