#include "geom.h"

//HELP
void help()
{
	printf("###SYNTAX###\n\n\t./triarr [size]\n\t\t[size] must be integer.\n\n");
}

//FILE
void fileerror()
{
	printf("###ERROR###\n\n\tJSON file can not be opened or created.\n\n");
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
	FILE *file;
	
	if ((file = fopen("triangles.json", "w")) == NULL)
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
		//printf("dbg_addElement (%d) = %d\n", i, addElement(triarr, OAB));
	}
	printTriangleArray(triArray);
	
	//replacing triangle N
	Point O = {0, 0};
	Point A = {0, 0 + rand() % 10};
	Point B = {0 + rand() % 10, 0 + rand() % 10};
	Triangle *OAB = createTriangleThroughPoints(&O, &A, &B);
	
	addElementAtIndex(triArray, OAB, 0);
	//printf("dbg_addElementAtIndex (%d) = %d\n", 0, addElementAtIndex(triarr, OAB, 0));
	
	printTriangleArray(triArray);
	writeArrayToJSON(file, triArray);
	
	destroyTriangleArray(triArray);
	fclose(file);
	
	return 0;
}
