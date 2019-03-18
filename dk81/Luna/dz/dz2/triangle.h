#include <stdio.h>

typedef struct tagDot{
	int x;
	int y;
}Dot;

typedef struct tagTriangle{
	Dot *a;
	Dot *b;
	Dot *c;
}Triangle;

Dot *createDot(int x, int y);
Triangle *createTriangle(Dot *a, Dot *b, Dot *c);
void deleteTriangle(Triangle *triugolnik);
void outputData(Triangle *triugolnik);
float Square(Triangle *triangle);

float CulcSide(Dot *a, Dot *b);
void outputDot(Dot *a);




