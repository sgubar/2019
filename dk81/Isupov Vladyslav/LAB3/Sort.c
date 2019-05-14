//
// Created by Владислав on 22.04.2019.
//

#include "Sort.h"

//search

int linearSearch(char *String, char pattern)
{
    if(String != NULL)
    {
        for (int i = 0; i < strlen(String); ++i)
        {
         if(String[i] == pattern)
             return i;
        }
        return -1;
    }
}

//sort
void shellSort(char *String) //
{
    if(String != NULL)
    {
        register int i, j, gap, k;
        int  count = (int)strlen(String);
        char x, a[5];

        a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

        for(k=0; k < 5; k++) {
            gap = a[k];
            for(i=gap; i < count; ++i) {
                x = String[i];
                for(j=i-gap; (x < String[j]) && (j >= 0); j=j-gap)
                    String[j+gap] = String[j];
                String[j+gap] = x;
            }
        }
    }
}


//service
void writeRandTempToFile(int size, FILE *aFile)
{
    if (NULL != aFile)
    {
        char b;
        for (int i = 0; i < size; ++i)
        {
            b = (char)(32+rand()%96);
            //printf( "%c", b);
            fprintf(aFile, "%c", b);
        }
    }
}

void readTempFromFile(char *String, int size, FILE *aFile)
{


    if (NULL != aFile && NULL != String)
    {
        for (int i = 0; i < size; ++i)
        {
            String[i] = (char)fgetc(aFile);
        }
    }
}

int scanWithChecking()
{
    char buf[32];
    int val = 0;
    fgets(buf, 31, stdin);
    if(sscanf(buf, "%d", &val) != 1)
    {
        printf("Error! Invalid value!\n");
        return -1;
    }

    else
        return val;
}




