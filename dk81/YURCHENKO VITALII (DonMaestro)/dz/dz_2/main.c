#include <stdio.h>
#include "header.h"

int main()
{
    Point A = {0,0};
    Point B = {0,5};
    Point C = {8,0};

    Triangle *ABC = createTriangle(&A, &B, &C);


    if(CheckTriangle(ABC) != 0)
    {
        printf("ERROR:Трикутник не прямокутний\n");
        destroyTriangle(ABC);
        return -1;
    }
    else
        printTriangle(ABC);

    destroyTriangle(ABC);
    return 0;
}
