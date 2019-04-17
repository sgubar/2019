#include "geom.h"

//HELP
void help()
{
	printf("###SYNTAX###\n\n\t./triangle [name] [Ax] [Ay] [Bx] [By] [Cx] [Cy]\n\t\t[name] must be three characters long.\n\n");
}

//MAIN
int main(int argc, char **argv)
{	
	//foolproof
	if (argc != 8){
		help();
		return -1;
	}
	
	if (strlen(argv[1]) != 3){
		help();
		return -1;
	}	
	
	//making points
	Point A = {atof(argv[2]), atof(argv[3])};
	Point B = {atof(argv[4]), atof(argv[5])};
	Point C = {atof(argv[6]), atof(argv[7])};
	
	printPoint(&A);
	printPoint(&B);
	printPoint(&C);
	
	//making a triangle through points
	Triangle *ABC = createTriangleThroughPoints(&A, &B, &C);

	printf("\nTriangle %s\n", argv[1]);
	printTriangle(ABC);
	
	destroyTriangle(ABC);
	
	/*
	//making a triangle through vectors
	//making vectors
	Vector *AC = createVector(&A, &C);
	Vector *AB = createVector(&A, &B);
	Vector *BC = createVector(&B, &C);

	//making a triangle
	Triangle *ABC = createTriangleThroughVectors(&AB, &AC, &BC);

	printf("\nTriangle %s\n", argv[1]);
	printTriangle(ABC);
	
	destroyTriangle(ABC);*/
	
	return 0;
}
