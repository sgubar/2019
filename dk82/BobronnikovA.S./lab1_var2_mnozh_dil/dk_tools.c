#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <C:\Users\123\Documents\local_ishodniki\lab1_var2_mnozh_dil\header.h>


//Функции модуля
int module (int a)
{
	return(abs (a));
}
//Функция степени
int power (int a, int pow)
{
	int i, res = 1;
	for(i = 0; i<pow; i++)
	{
		res = a*res;
	}
	return (res);
}
//Функция суммы степеней двойки от d до a
int sum_of_2_pow_d(int a, int d)
{
	int res = 0;
	for (d; d <=a; d++)
	{
		res = res + power(2, d);
	}
	return (res);
}
