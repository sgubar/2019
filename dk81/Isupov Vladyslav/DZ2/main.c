#include <stdio.h>
#include "Square.h"

int main() {

    int side = 7;
    Point A = {5,20};

    Square *ABCD = createSquareSide(&A, side);
    printSquare(ABCD);
    printf("Area is %i", area(ABCD) );
    destroySquare(ABCD);

    return 0;


}