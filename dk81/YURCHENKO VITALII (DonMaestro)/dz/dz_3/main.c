#include <stdio.h>
#include "array.h"


void checkError(int *error, int number)
{
    if(*error == -1)
    {
        printf("%i: ", number);
        printf("массив заповнений\n");
        *error = 0;
    }

    if(*error != 0 && *error != -1)
    {
        printf("%i: ", number);
        printf("ERROR:Трикутник не прямокутний\n");
        *error = 0;
    }


    if(*error == -69)
    {
        printf("%i: ", number);
        printf("ERROR:ошибка з памятю\n");
        *error = 0;
    }
}


int main()
{

    FILE *JSON_file;

    int error = 0;

    Point A = {0,0};
    Point B = {0,4};
    Point C = {3,0};
    TriangleArray *theArray = createArray(10);




    ////////////////
    error = addTriang(theArray, &A, &B, &C);
    checkError(&error, 0);

    ////////////////
//    A.x = 7;
//    A.y = 4;

//    error = addTriang(theArray, &A, &B, &C);
//    checkError(&error, 1);

    ///////////////
    A.x = 0;
    A.y = 0;
    B.y = 8;

    error = addTriang(theArray, &A, &B, &C);
    checkError(&error, 2);

    //////////////////////////

    A.x = 0;
    A.y = 0;
    B.y = 4;
    C.x = 5;

    error = addTriang(theArray, &A, &B, &C);
    checkError(&error, 5);

////////////////////////

    error = printArray(theArray);
    checkError(&error, 3);


    JSON_file = fopen("triangle_array.json", "wt");

    writeJSON(JSON_file, theArray);

    fclose(JSON_file);

    destroyArray(theArray);
    return 0;
}
