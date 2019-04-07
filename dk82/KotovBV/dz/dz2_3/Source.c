#include <stdlib.h>
#include "ellipse.h"
#include "eArray.h"
#include <Windows.h>
#pragma warning(disable:4996)
int main(int argc, char const* argv[])
{
	eArr* theArray = createArray(5);
	float area[] = { 0.0, 0.0,0.0 };
	Point A = { 6,3 };		
	Point B = { 2,10 };
	Point R = { 8,6 };
	Point mass[3] = { {5,5 }, {2, 3}, {9, 1} };
	//Point *ptr = mass;
	/*point *mass[3] = { &a, &b, &c };
	point **ptr = mass;*/

	Elips* arr = createElipswithArray(mass);//??????? ??????
	Elips* a = createElips(&A, &B, &R);//
	Elips* b = createElipsWithCoordinate(2, 1, 2, 4, 6, 4);

	area[0] = areaElips(a);//??????? ??????? ???????
	area[1] = areaElips(b);
	area[2] = areaElips(arr);


	printElips(a);//??????? ??????
	printElips(arr);
	printElips(b);
	
	addElement(theArray, a);//????????? ? ?????? ?????
	printAr(theArray);
	printf("area[a]=%f\n", area[0]);
	

	addElement(theArray, b);
	printAr(theArray);
	printf("area[b]=%f\n", area[1]);

	
	addElement(theArray, arr);
	printf("area[arr]=%f\n", area[2]);


	FILE* thefile = fopen("test.json", "a+");
	if (thefile != NULL)
		printf("file successfully created\n");
	else
		return 0;

	writeArrayToJSON(thefile, theArray);

	fflush(thefile);
	fclose(thefile);
	freeArray(theArray);
	destroyElips(a);
	destroyElips(b);
	destroyElips(arr);
	system("pause");
	return 0;
}