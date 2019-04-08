#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"


void add_rand_trian(TriangleArray *theArray, int max_numeric)
{
    //max_numeric = 1000;
    Point A;
    Point B;
    Point C;


    C.x = rand() % max_numeric;
    C.y = rand() % max_numeric;

    A.y = C.y;
    B.x = C.x;

    do
    {
        A.x = rand() % max_numeric;
        B.y = rand() % max_numeric;
    }while(A.x == C.x || B.y == C.y);



    //printf("%i  %i\n%i  %i\n%i  %i\n\n", A.x, A.y, B.x, B.y, C.x, C.y);
    addTriang(theArray, &A, &B, &C);

}




int main()
{


    int max_trian = 10000;

    //printf("%i\n", RAND_MAX);

    FILE *JSON_file;



    TriangleArray *theArray;


    //
    srand(time(NULL));

    printf("%i\n", max_trian);

    theArray = createArray(max_trian);


    for(int number_trian = 0; number_trian < max_trian; number_trian++)
    {
        add_rand_trian(theArray, 1000);
    }







    JSON_file = fopen("triangle_array.json", "wt");
    writeJSON(JSON_file, theArray);
    fclose(JSON_file);




    //////////////////////////////////////////////
////////////////sorting/////////////////////////
    //sorting_array(max_array, theArray);

    sorting_triangle(theArray);

////////////////////////////////////////////////////




    JSON_file = fopen("triangle_array_sorting.json", "wt");
    writeJSON(JSON_file, theArray);
    fclose(JSON_file);




    for(int i = 0; i < theArray->count; i++)
        printf("%.1f  ", theArray->triang[i]->square);

    printf("\n");
    //printArray(theArray[number_array]);

    printf("\n\nsize = %lu\n", sizeof(theArray));

    destroyArray(theArray);



    return 0;
}




