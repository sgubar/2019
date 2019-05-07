//
// Created by Владислав on 22.04.2019.
//

#include "Sort.h"

//sort
void bubleSort(char *String)
{
    if (NULL != String)
        for (int i = (int) strlen(String) - 1; i > 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (String[j] > String[j + 1])
                {
                    char tmp = String[j];
                    String[j] = String[j + 1];
                    String[j + 1] = tmp;
                }
            }
        }
}

void choiseSort(char *String)
{
    if(NULL != String)
        for (int i = 0; i < strlen(String) - 1; i++)
        {
            int min_i = i;
            for (int j = i + 1; j < strlen(String); j++)
            {
                if (String[j] < String[min_i])
                {
                    min_i = j;
                }
            }
            char temp = String[i];
            String[i] = String[min_i];
            String[min_i] = temp;
        }
}
void insertSort(char *String)
{
    if(NULL != String)
    {
        int location;
        char newElement;

        for (int i = 1; i < strlen(String); i++)
        {
            newElement = String[i];
            location = i - 1;
            while (location >= 0 && String[location] > newElement)
            {
                String[location + 1] = String[location];
                location = location - 1;
            }
            String[location + 1] = newElement;
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




