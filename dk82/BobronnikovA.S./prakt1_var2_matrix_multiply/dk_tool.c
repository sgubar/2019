//Библиотека собственных инструментов
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
2 -3  1		-7  5 1    		-16	 16	-13	
5  4 -2		 2 -1 7		=	-35	 15	 21	
5  9  8		 4  3 6			 15	 40	 116
			 
2 -3 1 5 4 -2 5 9 8
-7 5 1 2 -1 7 4 3 6

-16	16 -13	 -35 15	21	 15	40 116
*/

//Функция для умножения целочисленных квадратных матриц заданного размера.
//Вводить две матрицы и размер.
void sq_arr_multiply(int arr_1[], int arr_2[], int size)
{
	int result_arr[9];
	for (int i = 0; i<=size*size; i++)
	{
		result_arr[i] = 0;
		for (int j = 0; j<=size; i++)
		{
			result_arr[i] = result_arr[i] + arr_1[j] * arr_2[j*size];
		}
	}
	for (int i=0; i<=size*size; i++)
	{
		printf("%i", result_arr[i]);
	}
}
