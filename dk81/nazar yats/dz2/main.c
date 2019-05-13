#include <stdio.h>
#include "header.h"

int main()
{
    Point A = {1,1};
    Point B = {1,5};
    Point C = {7,5};
    Point D = {7,1};

    Rectangle *ABCD = createRectangle(&A, &B, &C, &D);


    if(CheckRectangle(ABCD) != 0)
    {
        printf("ERROR: YOU VASIA\n");
        destroyRectangle(ABCD);
        return -1;
    }
    else
        printRectangle(ABCD);

    destroyRectangle(ABCD);
    return 0;
}
