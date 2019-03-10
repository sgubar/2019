/*Первые наработки. ПРОМЕЖУТОЧНЫЙ ВАРИАНТ.*/
/*Умножение двух квадратных матриц*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <C:\Users\Bos\Documents\Visual Studio 2017\ishodniki\dk_tool.c>

int main()
{
	printf("This program multiplies two square matrix\n");
	/*printf("Enter size of arrays: ");
	scanf("%i", &size);*/
	int size = 3;
	int arr_1[9] = { 2, -3, 1, 5, 4, -2, 5, 9, 8};
	int arr_2[9]={-7, 5, 1, 2, -1, 7, 4, 3, 6};
	/*printf("Enter first matrix\n");
	for (int i=0; i<=size*size; i++)
	{
		printf("Enter the next element of matrix");
		scanf("%i", arr_1[i]);
	}
	printf("Enter second matrix\n");
	for (int i=0; i<=size*size; i++)
	{
		printf("Enter the next element of matrix");
		scanf("%i", arr_2[i]);
	}*/
	sq_arr_multiply(arr_1, arr_2, size);
	system("pause");
	return 0;
}
