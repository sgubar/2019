#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"


int main() {
    printf("Enter size of temp: \n");
    int size = scanWithChecking();
    char *string = NULL;
    char pattern;
    string = malloc( sizeof(*string) * size );
    FILE *fa;

    fa = fopen("test.txt", "w");
    writeRandTempToFile(size, fa);
    fclose(fa);
    fa = fopen("test.txt", "r");
    readTempFromFile(string, size, fa);

    printf("\nEnter pattern for searching: \n");
    scanf("%c", &pattern);
    printf("Item Index : [%i]\n", linearSearch(string, pattern));

    clock_t start = clock();
    shellSort(string);
    clock_t stop = clock();

    fa = fopen("test.txt", "w");
    fputs(string, fa);
    fclose(fa);

    printf("\n Time of sorting: %f sec", (float)(stop - start)/CLOCKS_PER_SEC);

    return 0;
}