/* Програма заполняет массив символов случайным образом, затем высчитывает время,
затраченное на сортировку тремя способами*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <C:\Users\Bos\Documents\local_ishodniki\lab2_var2_sort1\header.h>

int main()
{
	FILE *F1;
	F1 = fopen("1.txt", "w");
	fclose(F1);
	int size;
	printf("Enter number of array:\n");
	scanf("%i", &size);
	int *charst;
	charst = malloc(size * sizeof(int));
	int *charres;
	charres = malloc(size * sizeof(int));
	enter_arr(charst, size);
	memcpy(charres, charst, size * sizeof(int));
	bubblesort(charres, size);
	savetofile(charres, size);
	memcpy(charres, charst, size * sizeof(int));
	selectionsort(charres, size);
	savetofile(charres, size);
	memcpy(charres, charst, size * sizeof(int));
	insertionsort(charres, size);
	savetofile(charres, size);
	free(charst);
	free(charres);
system("pause");
return 0;
}
