#include <stdio.h>
#include <stdlib.h>
#include "StructTriagle.h"


int main()
{


Point array[3]={1,1,3,7,0,-1};
Point A={1,1};
Point B={3,7};
Point C={0,-1};
Triangle *MNP=CreateTriangleByArray(array);
Triangle *ABC=CreateTriangleByPoints(&A,&B,&C);
Triangle *XYZ=CreateTriangleByCoordinates(1,1,3,7,0,-1);

printTriangle(MNP);
printTriangle(ABC);
printTriangle(XYZ);
double square1=TriangleSquare(MNP);
printf("\n\nSquare of created Triangle1 is %.2f \n",square1);
double square2=TriangleSquare(ABC);
printf("\nSquare of created Triangle2 is %.2f \n",square2);
double square3=TriangleSquare(MNP);
printf("\nSquare of created Triangle1 is %.2f \n",square3);
destroyTriangle(MNP);
destroyTriangle(ABC);
destroyTriangle(XYZ);
    return 0;
}
