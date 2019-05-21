#include "geom.h"
#include "sort.h"

//HELP
void help()
{
	printf("###SYNTAX###\n\n\t./triarr [size]\n\t\t[size] must be integer.\n\n");
}

//MAIN
int main(int argc, char **argv)
{	
	if (argc != 2 || atoi(argv[1]) <= 0)
	{
		help();
		return -1;
	}
	
	//random
	srand(time(NULL));
	FILE *f_unsorted;
	FILE *f_sorted;
	
	if ((f_unsorted = fopen("trianglesUnsorted.json", "w")) == NULL)
	{
		fileerror();
		return -1;
	}
	if ((f_sorted = fopen("trianglesSorted.json", "w")) == NULL)
	{
		fileerror();
		return -1;
	}
		
	Array *triArray = createTriangleArray(atoi(argv[1]));
	
	for (int i = 0; i < atoi(argv[1]); i++)
	{
		Point O = {0, 0};
		Point A = {0, 0 + rand() % 10};
		Point B = {0 + rand() % 10, 0 + rand() % 10};
		Triangle *OAB = createTriangleThroughPoints(&O, &A, &B);
		
		addElement(triArray, OAB);
	}
	printTriangleArray(triArray);
	writeArrayToJSON(f_unsorted, triArray);
	
	selectionSort(triArray, atoi(argv[1]));
	
	printTriangleArray(triArray);
	writeArrayToJSON(f_sorted, triArray);
	
	destroyTriangleArray(triArray);
	fclose(f_unsorted);
	fclose(f_sorted);
	
	return 0;
}
