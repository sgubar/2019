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

	Elips* arr = createElipswithArray(mass);//создаем элипсы
	Elips* a = createElips(&A, &B, &R);//
	Elips* b = createElipsWithCoordinate(6, 3, 8, 1, 8, 6);

	area[0] = areaElips(a);//считаем площади элипсов
	area[1] = areaElips(b);
	area[2] = areaElips(arr);


	printElips(a);//выводим элипсы и их площадь
	printf("area[a]=%f\n\n", area[0]);
	if (arr != NULL)
	{
		printElips(arr);
		printf("area[arr]=%f\n\n", area[2]);
	}
	else printf("ellipse Isn't created\n\n");
	printElips(b);
	printf("area[b]=%f\n\n", area[1]);
	
	addElement(theArray, a);//добавляем в массив элипс
	printAr(theArray);

	addElement(theArray, b);
	printAr(theArray);
	
	addElement(theArray, arr);
	printAr(theArray);

	addElInd(theArray, b, 1);
	printAr(theArray);

	FILE* thefile = fopen("test.json", "a+");
	if (thefile != NULL)
		printf("file successfully created\n\n");
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