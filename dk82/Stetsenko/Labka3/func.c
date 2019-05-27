#include <stdio.h>
#include <stdlib.h>
#include "lab3_func.h"


void QuickSort(char *arr, int first, int last)
{
	int mid, left, right;

    left = first;
    right = last;

  mid = arr[(left + right) / 2];
  while (left <= right)
  {
    while (arr[left] < mid) left++;

    while (arr[right] > mid) right--;

    if (left <= right)
	{
        swap(&arr[left], &arr[right]);
        left++;
        right--;
	}
  }
  if (first < right) QuickSort(arr, first, right);

  if (left < last) QuickSort(arr, left, last);
}


void Record_File(char *arr, int asize, char *fname)
{
	FILE *file;
	file= fopen(fname, "w");

	int i;
	for(i = 0; i < asize; i++)
	{
	    fprintf(file, "%c", arr[i]);
	}
	fclose(file);
}

int biSearch(char Value, char *arr, int asize)
{
    int left = 0;
    int right = asize-1;
    int central;

    while (left <= right)
    {
        central = (left+right)/2;
        if(Value == arr[central])
        {
            return central;
        }
        else if(Value < arr[central])
        {
            right = central-1;
        }
        else if(Value > arr[central])
        {
            left = central + 1;
        }
    }
    printf("\nCan't find such symbol =(");
    return -1;
}

void random(char *arr, int size)

{
    srand(time(NULL));
    int a, i;

    for(i = 0; i < size; i++)
    {
        a = rand() % 2;
        if(a == 1)
        {
            arr[i] = rand() % 26 + 65;
        }
        else
        {
            arr[i] = rand() % 26 + 97;
        }
    }
}


void swap(char *one, char *two)
{
	char three = *one;
	*one = *two;
	*two = three;
}
