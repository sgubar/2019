#include <stdio.h>
#include <stdlib.h>
#include "lab3_func.h"
#include <time.h>


int main()
{
    int size = 0;
    float ssort_t, esort_t, ssearch_t, esearch_t;

    printf("   Enter size of array : ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("   Enter again: ");
        scanf("%d", &size);
    }

    char arr[size];
    random(arr, size);
    Record_File(arr, size, "array.txt");
    ssort_t = clock()/(float)CLOCKS_PER_SEC * 1000;
    QuickSort(arr, 0, size - 1);
    esort_t = clock()/(float)CLOCKS_PER_SEC * 1000;
    Record_File(arr, size, "QuickSort.txt");

    int i;
    printf("\n\n   Your sorted array : \n");
    for(i = 0; i < size; i++)
    {
        printf(" [%c] ", arr[i]);
    }
    printf("\n\n   Time of QuickSort is [%f] sec\n\n", esort_t - ssort_t);
    printf("\n\n   Size : [%d]", size);
    printf("\n\n   Enter Symbol : ");

    getchar();
    char symbol = getchar();

    int position;
    ssearch_t = clock()/(float)CLOCKS_PER_SEC * 1000;
    position = biSearch(symbol, arr, size);
    esearch_t = clock()/(float)CLOCKS_PER_SEC * 1000;
    printf("\n\n   Time of Binary search is [%f] sec\n\n", esearch_t - ssearch_t);
    printf("\n\n   Position of [%c] is (%d)\n\n", symbol, position);

    return 0;
}
