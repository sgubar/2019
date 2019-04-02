#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
	int **q,k,l,**q2,**sum;
	printf("Enter k:");
	scanf_s("%d", &k);//высота массива
	printf("Enter l:");
	scanf_s("%d", &l);//длинна строки
	q = (int**)malloc(sizeof(int*)*k);//динамический двумерный массив
	q2=(int**)malloc(sizeof(int*)*k);//динамический двумерный массив
	for (int i = 0; i < k; i++)
	{
		q[i] = (int*)malloc(sizeof(int)*l);//в каждой строке мы задаем длину этой строки (в каждой строке массива создаём ещё один масив)
		for (int j = 0; j <l; j++)
		{
			printf("k[%d][%d]=", i, j);
			scanf_s("%d", &q[i][j]);    //заполняем каждую строчку
		}
	}
	for (int i = 0; i < k; i++)
	{
		q2[i] = (int*)malloc(sizeof(int)*l);
		for (int j = 0; j < l; j++)
		{
			printf("k[%d][%d]=", i, j);
			scanf_s("%d", &q2[i][j]);
		}
	}
	sum = plusm(q, q2, k, l);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			printf("%d    ", sum[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}