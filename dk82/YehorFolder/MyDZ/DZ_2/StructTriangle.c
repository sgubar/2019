#include "StructTriagle.h"
#include <math.h>

Point *CopyPointWithPoint(Point *aPoint);
Point *CreatPointByCoordinate(int x, int y);



Triangle *CreateTriangleByCoordinates(int x1,int y1,int x2,int y2,int x3,int y3)
{
    Triangle *theResult=(Triangle*)malloc(sizeof(Triangle));

    if(theResult!=0)
    {
        theResult->A=CreatPointByCoordinate(x1,y1);
        theResult->B=CreatPointByCoordinate(x2,y2);
        theResult->C=CreatPointByCoordinate(x3,y3);
    }

    return theResult;
}

void destroyTriangle(Triangle* aTriangle)
{
 if (aTriangle!=NULL)
 {
     free(aTriangle->A);
     free(aTriangle->C);
     free(aTriangle->C);

     free(aTriangle);
 }


}



Point *CreatPointByCoordinate(int x, int y)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}

	return theResult;
}


Point *CopyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}

	return theResult;
}


Triangle *CreateTriangleByPoints(Point* A,Point* B, Point* C)
{
      if (0 == isValidate(A, B, C))
      {
        return NULL;
      }

         Triangle* theResult=NULL;


            theResult=(Triangle*)malloc(sizeof(Triangle));

            if(theResult!=NULL)
            {
            theResult->A=CopyPointWithPoint(A);
            theResult->B=CopyPointWithPoint(B);
            theResult->C=CopyPointWithPoint(C);
            }
      return theResult;
}




double TriangleSquare(Triangle* aTriangle)
{
    double AB=0,BC=0,AC=0;
    double Square;
    if(aTriangle!=NULL)
    {
    AB=sqrt((double)pow(aTriangle->B->x-aTriangle->A->x,2)+(double)pow(aTriangle->B->y-aTriangle->A->y,2));

    BC=sqrt((double)pow(aTriangle->C->x-aTriangle->B->x,2)+(double)pow(aTriangle->C->y-aTriangle->B->y,2));

    AC=sqrt((double)pow(aTriangle->C->x-aTriangle->A->x,2)+(double)pow(aTriangle->C->y-aTriangle->A->y,2));

    }

   if(AB+BC<=AC || AB+AC<=BC || BC+AC<=AB )
    {
        printf("\nInvalid triangle points!!!\n");
        destroyTriangle(aTriangle);
        return -1;
    }
    else{
        double HalfPerimetr=(AB+BC+AC)/2;
        Square=(double)sqrt((HalfPerimetr-AB)*(HalfPerimetr-AC)*(HalfPerimetr-BC)*HalfPerimetr);
        return Square;
    }
}



Triangle *CreateTriangleByArray(Point* arr)
{
    Triangle* theResult=NULL;

        if(arr!=NULL)
        {
            theResult=(Triangle*)malloc(sizeof(Triangle));

            if(theResult!=NULL)
            {
            theResult->A=CopyPointWithPoint(&arr[0]);
            theResult->B=CopyPointWithPoint(&arr[1]);
            theResult->C=CopyPointWithPoint(&arr[2]);
            }
        }
     return theResult;
}

void printTriangle(Triangle* aTriangle)
{
    printf("\nWe now have a triangle with given coordinates: \n");
    printf("[%d;%d] ",aTriangle->A->x,aTriangle->A->y);
    printf("[%d;%d] ",aTriangle->B->x,aTriangle->B->y);
    printf("[%d;%d] ",aTriangle->C->x,aTriangle->C->y);
}


int isValidate(Point* A,Point* B,Point* C){

    double AB=0,BC=0,AC=0;

    if(NULL!=A && NULL!=B && NULL!=C){
        return 0;
    }

    AB=sqrt((double)pow(B->x-A->x,2)+(double)pow(B->y-A->y,2));

    BC=sqrt((double)pow(C->x-B->x,2)+(double)pow(C->y-B->y,2));

    AC=sqrt((double)pow(C->x-A->x,2)+(double)pow(C->y-A->y,2));


    int result = (AB+BC<=AC || AB+AC<=BC || BC+AC<=AB) ? 0 : 1;

    return result;
}
