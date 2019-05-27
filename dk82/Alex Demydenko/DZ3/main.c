#include "dz3.h"

int main(int argc, char **argv)
{
	FILE *fo;
	if ((fo = fopen("circles.json", "w")) == NULL)
	{
		return -1;
	}
	
	Point A = {2,4};
	Point B = {0,5};    
	Point C = {8,3};  
	Array *array = createCircleArray(getSize());                               
	
	Circle *OA = createCircleWithPoint(&A);
	Circle *OB = createCircleWithPoint(&B);
	Circle *OC = createCircleWithPoint(&C);
	
	addElement(array, OA);
	addElement(array, OB);
	addElement(array, OC);
	
	printCircleArray(array);
	
	addElementAtIndex(array, OA, 2);
	
	writeArrayToJSON(fo, array);
	
	printCircleArray(array);
	
	destroyCircleArray(array); 
	
	system("PAUSE");
	return 0;
}
