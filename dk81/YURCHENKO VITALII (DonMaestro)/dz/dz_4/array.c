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
                printf("ERROR: trian\n");
                result = NULL;
            }
        }
        else if(NULL == result)
            printf("ERROR: array\n");
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
            NTriang->triang[NTriang->count]->square = square_triang(NTriang->triang[NTriang->count]);
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





void sorting_triangle(TriangleArray *array)
{

    Triangle *newElement;
    int location;


    for(int number_trian = 1; number_trian < array->count; number_trian++)
    {
        printf("%i\n", number_trian);

        newElement = array->triang[number_trian];
        location = number_trian - 1;
        while(location >= 0 && array->triang[location]->square > newElement->square)
        {
            array->triang[location + 1] = array->triang[location];
            location = location - 1;
        }
        array->triang[location + 1] = newElement;
    }

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

    fprintf(file, "]\n}\n");
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

























void sorting_array(int max_array, TriangleArray *array[])
{

    TriangleArray *newElement;
    int location;


//    for(int number_array = 0; number_array < 10; number_array++)
//       {
//           printf("%i\n", array[number_array]->count);
//           //printArray(theArray[number_array]);
//       }printf("\n");



    for(int number_array = 1; number_array < max_array; number_array++)
    {
        newElement = array[number_array];
        location = number_array - 1;
        while(location >= 0 && array[location]->count > newElement->count)
        {
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = newElement;
    }



//    for(int number_array = 0; number_array < 10; number_array++)
//       {
//           printf("%i\n", array[number_array]->count);
//           //printArray(theArray[number_array]);
//       }printf("\n");

}
