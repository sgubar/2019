#include <stdio.h>
#include "tool.h"
#include <string.h>

int main(int argc, const char * argv[])
{
	FILE *fo = fopen("C:/Users/User/Documents/Dev-c++/struct_square/test.json", "w+");
	//float area = 0;

	Array *theArray1 = createArray(3);
	Array *theArray2 = createArray(3);
	Array *theArray3 = createArray(3);
	
	Point A = {0,0};
	Point B = {0,5};
	
	Point C = {0,0};
	Point D = {0,6};
	
	Point E = {0,0};
	Point F = {0,3};
	
	Square AB = {&A, &B};
	Square CD = {&C, &D};
	Square EF = {&E, &F};
	
	addElement(theArray1, &AB);
	addElement(theArray1, &CD);
	addElement(theArray1, &EF);
	addElement(theArray2, &AB);
	addElement(theArray2, &CD);
	addElement(theArray2, &EF);
	addElement(theArray3, &AB);
	addElement(theArray3, &CD);
	addElement(theArray3, &EF);
	printArray(theArray1);
	printArray(theArray2);
	printArray(theArray3);
	writeArrayToJSON(fo, theArray1);
	writeArrayToJSON(fo, theArray2);
	writeArrayToJSON(fo, theArray3);

	bubbleSort(theArray1);
	selectionSort(theArray2);
	insertionSort(theArray3);
	
	printf("\n\nSorted Arrays of Squares\n");
		
	printArray(theArray1);
	printArray(theArray2);
	printArray(theArray3);
	
	fprintf(fo, "\n\n\n");
	
	writeArrayToJSON(fo, theArray1);
	writeArrayToJSON(fo, theArray2);
	writeArrayToJSON(fo, theArray3);
	
	freeArray(theArray1);
	freeArray(theArray2);
	freeArray(theArray3);

	fflush(fo);
	fclose(fo);
	
	return 0;
}
