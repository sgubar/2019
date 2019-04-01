#include <stdio.h>

typedef struct tagDot {
	int x;
	int y;
}Dot;

typedef struct tagTriangle {
	Dot *a;
	Dot *b;
	Dot *c;
}Triangle;

typedef struct tagTriangleArray {
	int dlina;
	int kolichestvo;
	Triangle **arr;
}TriangleArray;

Dot *createDot(int x, int y);
Triangle *createTriangle(Dot *a, Dot *b, Dot *c);
void deleteTriangle(Triangle *triugolnik);
void outputData(Triangle *triugolnik); //вывод на экран 
float Square(Triangle *triangle);

float CulcSide(Dot *a, Dot *b); //расчитываем растояние между двумя точками 
void outputDot(Dot *a);

TriangleArray *createArray(int dlina);
void deleteTriangleArray(TriangleArray *arr);
int adding(TriangleArray *arr,Triangle *edinorog);
int vstavka(int indeks, TriangleArray *arr, Triangle *edinorog);
void printArray(TriangleArray *arr);

int saveToJSON(TriangleArray *zebra);
void outputDataToFile(Triangle *triugolnik, FILE *fp);
void outputDotToFile(Dot *a, FILE *fp);
