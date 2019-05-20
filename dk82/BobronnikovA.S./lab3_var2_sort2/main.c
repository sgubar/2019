/* Програма заполняет массив символов случайным образом, затем высчитывает время,
затраченное на сортировку quicksort и бинарного поиска */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <C:\Users\Bos\Documents\local_ishodniki\lab3\header.h>

int main()
{
	FILE *F1;
	F1 = fopen("1.txt", "w");
	fclose(F1);
	int size, tofind, res;
	printf("Enter number of array:\n");
	scanf("%i", &size);
	printf("Enter number to find:\n");
	scanf("%i", &tofind);
	int *charres;
	charres = malloc(size * sizeof(int));
	enter_arr(charres, size);
	savetofile(charres, size);
		clock_t start = clock();
	quicksort(charres, 0, size-1);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", seconds);
	savetofile(charres, size);
		start = clock();
	res = binarysearch(tofind, charres, size);
		end = clock();
		seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("%f\n", seconds);
	printf("The result is %i\n", res);
	F1 = fopen("1.txt", "a");
	fprintf(F1, "The result is %i\n", res);
	fclose(F1);
	free(charres);
system("pause");
return 0;
}
