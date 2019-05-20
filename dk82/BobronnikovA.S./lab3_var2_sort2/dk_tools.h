#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Bos\Documents\local_ishodniki\lab3\header.h>

//65-90, 97-122
//Содержит quicksort и бинарный поиск
int enter_arr(int *charres, int size)
{
	int temp;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		do
		{
			temp = 65 + rand() % 57;
		} while (temp > 90 && temp < 97);
 		charres[i] = temp;
	}
	return 0;
}

int quicksort (int *charres, int index1, int index2)
{
	int l = index1, r = index2, bufer;
	int piv = charres[(l + r) / 2];
	while (l <= r)
	{
		while (charres[l] < piv)
			l++;
		while (charres[r] > piv)
			r--;
		if (l <= r)
		{
			bufer = charres[l];
			charres[l] = charres[r];
			charres[r] = bufer;
			l++; r--;
		}
	}
	if (index1 < r)
		quicksort(charres, index1, r);
	if (index2 > l)
		quicksort(charres, l, index2);
	return 0;
}

int binarysearch(int tofind, int *charres, int size)
{
    int low, high, middle;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (tofind < charres[middle])
            high = middle - 1;
        else if (tofind > charres[middle])
            low = middle + 1;
        else 
            return middle;
    }
    return -1;
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
