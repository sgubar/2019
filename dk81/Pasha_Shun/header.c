//
// Created by World_conspiracy on 04.05.2019.
//

#include "header.h"

int enter_size_array()
{
    int size;
    printf("Enter a size of array(0-2 147 483 647): ");
    scanf("%d", &size);

    if (size <= 0 || size > 2147483647){
        printf("Wrong valuables");
        return 0;
    }
    return size;
}

void fill_array(char *array, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(i%2 == 1) array[i] = rand()%('z' + 1 - 'a')+'a';
        else array[i] = rand()%('9' + 1 - '0')+'0';
    }
}

char* loadFile (char* path , int  size) {
    FILE *infile = fopen (path, "r");

        int i = 0;
        char *output_array = malloc (sizeof (char) * (size+1));
        for (i = 0;i < size;i++)
        {
            fscanf (infile, "%c", &output_array[i]);
        }
        fclose (infile);

        return output_array;

}

void input_array_in_file(char *aray, int size, char *name)
{
    FILE *file;
    file= fopen(name, "w+");
    int i;
    for(i = 0; i < size; i++)
    {
        fprintf(file, "%c", aray[i]);
    }

    fclose(file);
}

void bubble_sort(char *aray, int size)
{
    int k,i;
    for(k = 0; k < size - 1; k++)
    {
        for( i = 0; i < size - 1 - k; i++)
        {
            if(aray[i] < aray[i+1])
            {
                int temp = aray[i+1];
                aray[i+1] = aray[i];
                aray[i] = temp;
            }
        }
    }
}

void insertion_sort(char *aray, int size)
{
    char newElement;
    int  location,i;

    for ( i = 1; i < size; i++)
    {
        newElement = aray[i];
        location = i - 1;
        while(location >= 0 && aray[location] < newElement)
        {
            aray[location+1] = aray[location];
            location = location - 1;
        }
        aray[location+1] = newElement;
    }
}

void selection_sort(char *aray, int size)
{
    char temp;
    int k,i,j;
    for(i = 0; i < size; ++i)
    {
        k = i;
        temp = aray[i];
        for(j = i + 1; j < size; ++j)
        {
            if (aray[j] > temp)
            {
                k = j;
                temp = aray[j];
            }
        }
        aray[k] = aray[i];
        aray[i] = temp;
    }
}