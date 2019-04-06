#include <stdio.h>
#include <stdlib.h>
#include "StructTriagle.h"


int main()
{


Point A={1,1};
Point B={2,2};
Point C={0,0};
Point array[3]={6,-2,3,7,0,5};
Triangle *MNP=CreateTriangleByArray(array);
Triangle *ABC=CreateTriangleByPoints(&A,&B,&C);
Triangle *XYZ=CreateTriangleByCoordinates(6,7,-1,2,-1,9);

printTriangle(MNP);
if (NULL != ABC)
    printTriangle(ABC);
printTriangle(XYZ);
double square1=TriangleSquare(MNP);
printf("\n\nSquare of created Triangle1 is %.2f \n",square1);
if (NULL != ABC)
{
    double square2=TriangleSquare(ABC);
    printf("\nSquare of created Triangle2 is %.2f \n",square2);
}
double square3=TriangleSquare(XYZ);
printf("\nSquare of created Triangle2 is %.2f \n",square3);
destroyTriangle(MNP);
if (NULL != ABC)
    destroyTriangle(ABC);
destroyTriangle(XYZ);
    return 0;
}
