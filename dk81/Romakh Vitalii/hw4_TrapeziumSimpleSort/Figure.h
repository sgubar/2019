#include <stdio.h>
#include <math.h>
#include "Meta.h"

typedef struct tagDot {
	int x;
	int y;
	char id;
}Dot;

typedef struct tagTrapezium {
	Dot *leftBottomCorner;
	Dot *leftTopCorner;
	Dot *rightTopCorner;
	Dot *rightBottomCorner;
}Trapezium;

typedef struct tagTrapeziumArray
{
	int numberUsed;
	int length;
	Trapezium **trapeziumArr;
}TrapeziumArray;

Dot *createDot(int x, int y);
Dot *generateDot(int x, int y, char id);
Dot *inputDot(int xCoor, int yCoor);

TrapeziumArray *createTrapeziumArray(int length);
int addElementToTrapeziumArray(TrapeziumArray *array, Trapezium *element);
Trapezium* getElementFromTrapeziumArray(TrapeziumArray *array, int index);
void deleteTrapeziumArray(TrapeziumArray *trapeziumArray);
int changeElementInTrapeziumArray(TrapeziumArray *array, Trapezium *element, int index);
void printArr(TrapeziumArray *arr);
void simplifiedPrintArray(TrapeziumArray *arr);

Trapezium *createTrapezium();
Trapezium *generateTrapezium(int radius);
void deleteDot(Dot *dot);
void deleteTrapezium(Trapezium *figure);
void showTrapezium(Trapezium *figure);
void showDot(Dot *d);


float calculateTrapeziumSquare(Trapezium *trap);
float calculateLineLength(Dot *a, Dot *b);

//int comparator(const void *tr1, const void *tr2);
int comparator(void *base, int indexA, int indexB);