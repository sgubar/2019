#include <stdlib.h>
#include "ellipse.h"
#include "eArray.h"
#include <Windows.h>
int main(int argc, char const* argv[])
{
	eArr* theArray = createArray(5);
	float area = 0.0;
	Point A = { 6,3 };		
	Point B = { 2,10 };
	Point R = { 8,6 };
	Point mass[3] = { {5,5 }, {2, 3}, {9, 1} };
	//Point *ptr = mass;

	/*point *mass[3] = { &a, &b, &c };
	point **ptr = mass;*/

	/*	if (perp(&R, &A, &B) != 0 && perp(&mass[0], &mass[1], &mass[2]))
		{
			MessageBox(NULL, "ERROR404", "ERROR", MB_OK | MB_ICONEXCLAMATION);
			return 0;
		}*/
	Elips* arr = createElipswithArray(mass);//
	Elips* a = createElips(&A, &B, &R);//
	Elips* b = createElipsWithCoordinate(2, 1, 2, 4, 6, 4);

	area = areaElips(a);

	printElips(a);
	printElips(arr);
	printElips(b);
	
	addElement(theArray, a);
	printAr(theArray);
	
	addElement(theArray, b);
	printAr(theArray);

	//addElement(theArray, arr);
	//printAr(theArray);

	FILE* thefile = fopen_s(&thefile,"/Users/Cicloida/source/repos/dz2/dz2/Debug/test.json", "a+");
	writeArrayToJSON(thefile, theArray);

	if (thefile != NULL) {
		fflush(thefile);
		//fclose(thefile);
		fclose(thefile);
	}
	else printf("file is clear\n");
	freeArray(theArray);
	destroyElips(a);
	destroyElips(b);
	destroyElips(arr);
	printf("area=%f\n", area);
	system("pause");
	return 0;
}