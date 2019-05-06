#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Bos\Documents\local_ishodniki\lab2_var2_sort1\header.h>

//65-90, 97-122
int enter_arr(int *charst, int size)
{
	int temp;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		do
		{
			temp = 65 + rand() % 57;
		} while (temp > 90 && temp < 97);
 		charst[i] = temp;
	}
	return 0;
}

int bubblesort(int *charres, int size) 
{
	clock_t start = clock();
	for (int i = 0; i < size; i++)
	{
		for (int j = size-1; j > i; j--)
		{
			if (charres[j - 1] > charres[j]
			{
				int temp = charres[j - 1];
				charres[j - 1] = charres[j];
				charres[j] = temp;
			}
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", seconds);
	return 0;
}

int selectionsort(int *charres, int size) 
{
	clock_t start = clock();
	for (int i = 0; i < size; i++) 
	{
		for (int j = i + 1; j < size; j++) 
		{
			if (charres[j] < charres[i])
			{
				int temp = charres[i];
				charres[i] = charres[j];
				charres[j] = temp;
			}
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", seconds);
	return 0;
}

int insertionsort(int *charres, int size) 
{
	clock_t start = clock();
	int temp;
	for (int i = 0; i < size; i++)
	{
		temp = charres[i];
		for (int j = i - 1; j >= 0 && charres[j]>temp; j--) charres[j + 1] = charres[j];
		charres[j + 1] = temp;
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", seconds);
	return 0;
}

int savetofile(int *charres, int size)
{
	FILE *F1;
	F1 = fopen("1.txt", "a");
	char c[] = "a";
	for (int i = 0; i < size; i++)
	{
		c[0] = charres[i];
		fprintf(F1, "%c ", c[0]);
	}
	fprintf(F1, "\n***\n");
	fclose(F1);
	return 0;
}
