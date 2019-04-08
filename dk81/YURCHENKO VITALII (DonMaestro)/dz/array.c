#include "array.h"
#include "header.h"
#include <stdlib.h>


TriangleArray *createArray(int anumber)
{
    TriangleArray *result = NULL;

    if(anumber > 0)
    {
        result = (TriangleArray *)malloc(sizeof(TriangleArray));

        if(NULL != result)
        {
            result->triang = (Triangle **)malloc(sizeof(Triangle *)*anumber);

            if(result->triang != NULL)
            {
                result->number = anumber;
                result->count = 0;
            }
            else
            {
                free(result);
                result = NULL;
            }
        }
    }

    return result;
}



int addTriang(TriangleArray *NTriang, Point *A, Point *B, Point *C)
{


    if(NTriang != NULL && NTriang->count < NTriang->number)
    {
        NTriang->triang[NTriang->count] = createTriangle(A, B, C);

        if(CheckTriangle(NTriang->triang[NTriang->count]) == 0)
        {
            NTriang->count++;
            return 0;
        }
        else
            return CheckTriangle(NTriang->triang[NTriang->count]);

    }
    else if(NTriang == NULL)
        return -69;

    return -1;
}






int printArray(TriangleArray *Array)
{


    if(Array != NULL)
    {
        printf("number = %i\n\n", Array->number);
        //printf("", Array->triang)
        for(int number = 0; number < Array->count; number++)
        {
            printf("count = %i\n", number);
            printTriangle(Array->triang[number]);
            printf("\n");
        }
    }
    else
        return -69;

    return 0;
}





void writeJSON(FILE *file, TriangleArray *array)
{
    if (NULL == array || NULL == file)
    {
        return;
    }

    fprintf(file, "{\n\"number\" : %d,\n\"count\" : %d,\n", array->number, array->count);
    fprintf(file, "\"triangle\" : [\n");

    for (int number = 0; number < array->count - 1; number++)
    {
        writeJSON_Trian(file, array->triang[number]);
        fprintf(file, ",");
        fprintf(file, "\n");
    }
    writeJSON_Trian(file, array->triang[array->count - 1]);
    fprintf(file, "\n");

    fprintf(file, "]\n}");
}



void destroyArray(TriangleArray *array)
{
    if(array != NULL)
    {
        for(int number = 0; number < array->number; number++)
            destroyTriangle(array->triang[number]);

        free(array->triang);
        free(array);
    }
}
