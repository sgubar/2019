#include <stdio.h>
#include "Figure.h"

Dot *createDot(int xCoor, int yCoor) {
	Dot *d = (Dot *)malloc(sizeof(Dot));

	int x = xCoor;
	int y = yCoor;

	return d;
}

Dot *inputDot(int xCoor, int yCoor) { //создание точки вручную через консоль
	Dot *d = (Dot *)malloc(sizeof(Dot));

	int x = xCoor;
	int y = yCoor;

	if (x == ERROR) {
		printf("Input x:\n");
		scanf_s("%i", &x);
	}

	if (y == ERROR) {
		printf("Input y:\n");
		scanf_s("%i", &y);
	}

	d->x = x;
	d->y = y;

	return d;
}

Dot *generateDot(int x, int y, char id) { //Конструктор точки
	Dot *d = (Dot *)malloc(sizeof(Dot));

	d->x = x;
	d->y = y;
	d->id = id;

	return d;
}

Trapezium *generateTrapezium(int radius) {  //Генерация трапеции, разброс точок с расстоянием до радиуса
	time_t t;
	srand((unsigned)time(&t));
	Trapezium *trap = (Trapezium *)malloc(sizeof(Trapezium));

	trap->leftBottomCorner = generateDot(0, 0, 'A');
	trap->leftTopCorner = generateDot(rand() % radius + 1, rand() % radius + 1, 'B');
	trap->rightTopCorner = generateDot(trap->leftTopCorner->x + rand() % radius + 1, trap->leftTopCorner->y, 'C');
	trap->rightBottomCorner = generateDot(trap->rightTopCorner->x + rand() % radius + 1, trap->leftBottomCorner->y, 'D');

	return trap;
}

Trapezium *createTrapezium() { // создание Трапеции вручную через консоль
	Trapezium *trap = (Trapezium *)malloc(sizeof(Trapezium));


	printf("Input left bottom dot - A:\n");
	trap->leftBottomCorner = inputDot(ERROR, ERROR);
	trap->leftBottomCorner->id = 'A';

	printf("\nInput left top dot - B:\n");
	trap->leftTopCorner = inputDot(ERROR, ERROR);
	trap->leftTopCorner->id = 'B';

	if (trap->leftTopCorner->y <= trap->leftBottomCorner->y) {
		printf("Top corner couldn't be lower than bottom corner!\n");
		return ERROR;
	}

	printf("\nInput right top dot x - C:\n");
	trap->rightTopCorner = inputDot(ERROR, trap->leftTopCorner->y);
	trap->rightTopCorner->id = 'C';

	if (trap->rightTopCorner->x <= trap->leftTopCorner->x) {
		printf("Left corner couldn't be righter than left corner!\n");
		return ERROR;
	}



	printf("\nInput right bottom dot x - D:\n");
	trap->rightBottomCorner = inputDot(ERROR, trap->leftBottomCorner->y);
	trap->rightBottomCorner->id = 'D';

	if (trap->rightBottomCorner->x <= trap->leftBottomCorner->x) {
		printf("Left corner couldn't be righter than left corner!\n");
		return ERROR;
	}
	return trap;
}

void showDot(Dot *d) { //Вывести точку на экран
	printf("x = %i\n", d->x);
	printf("y = %i\n", d->y);
}

void showTrapezium(Trapezium *t) { //Вывести данные про фигуру на экран

	printf("\n---------------------------------------------\n");

	printf("Left Bottom Dot - A:\n");
	showDot(t->leftBottomCorner);

	printf("Left Top Dot - B:\n");
	showDot(t->leftTopCorner);

	printf("Right Top Dot - C:\n");
	showDot(t->rightTopCorner);

	printf("Right Bottom Dot - D:\n");
	showDot(t->rightBottomCorner);

	printf("\nSquare = %f\n", calculateTrapeziumSquare(t));

	printf("\n");
}

void deleteDot(Dot *dot) { // удаление точки
	free(dot);
}

void deleteTrapezium(Trapezium *trapezium) {// удаление трапеции
	deleteDot(trapezium->leftBottomCorner);
	deleteDot(trapezium->leftTopCorner);
	deleteDot(trapezium->rightTopCorner);
	deleteDot(trapezium->rightBottomCorner);

	free(trapezium);
}

float calculateLineLength(Dot *a, Dot *b) {// расчёт длины отрезка между двумя точками
	int deltaX = b->x - a->x;
	int deltaY = b->y - a->y;

	float result = sqrt(deltaX*deltaX + deltaY * deltaY);
	return result;
}


float calculateTrapeziumSquare(Trapezium *trap) {//Расчет площади трапеции
	float a = trap->leftBottomCorner->x * trap->leftTopCorner->y + trap->leftTopCorner->x * trap->rightTopCorner->y + trap->rightTopCorner->x * trap->rightBottomCorner->y + trap->rightBottomCorner->x * trap->leftBottomCorner->y;
	float b = trap->leftBottomCorner->y * trap->leftTopCorner->x + trap->leftTopCorner->y * trap->rightTopCorner->x + trap->rightTopCorner->y * trap->rightBottomCorner->x + trap->rightBottomCorner->y * trap->leftBottomCorner->x;

	float result = a + b;
	return result;
}

TrapeziumArray *createTrapeziumArray(int length) {
	TrapeziumArray* trapeziumArray = (TrapeziumArray*)malloc(sizeof(TrapeziumArray));

	if (length > 0) {
		Trapezium** trapArr = (Trapezium**)malloc(sizeof(Trapezium) * length);
		trapeziumArray->trapeziumArr = trapArr;
		trapeziumArray->length = length;
		trapeziumArray->numberUsed = 0;
	}
	else {
		free(trapeziumArray);
		return ERROR;
	}

	return trapeziumArray;
}

void deleteTrapeziumArray(TrapeziumArray *trapeziumArray) {
	if (trapeziumArray != NULL) {
		for (int i = 0; i < trapeziumArray->length; i++)
		{
			deleteTrapezium(trapeziumArray->trapeziumArr[i]);
		}
		free(trapeziumArray->length);
		free(trapeziumArray->numberUsed);
	}
}


int addElementToTrapeziumArray(TrapeziumArray *array, Trapezium *element) {
	if (array->numberUsed <= array->length - 1 && element != NULL) {
		array->trapeziumArr[array->numberUsed] = element;
	//	printf("Size of element %d \n", sizeof(element));
	//	printf("Addres = %p , %d \n", &array->trapeziumArr[array->numberUsed], &array->trapeziumArr[array->numberUsed]);
		array->numberUsed++;
		return array->numberUsed;
	}
	else {
		return ERROR;
	}
}

int changeElementInTrapeziumArray(TrapeziumArray *array, Trapezium *element, int index) {
	if (index <= array->length - 1 && element != NULL) {
		Trapezium *deletedTrapezium = array->trapeziumArr[index];
		deleteTrapezium(deletedTrapezium);
		array->trapeziumArr[index] = element;
		return index;
	}
	else {
		return ERROR;
	}
}

Trapezium* getElementFromTrapeziumArray(TrapeziumArray *array, int index) {
	if (array != NULL && index >= 0) {
		if (index >= array->length) {
			return ERROR;
		}
		else {
			return array->trapeziumArr[index];
		}
	}
}

void printArr(TrapeziumArray *arr) {
	if (arr == NULL) {
		return ERROR;
	}

	if (arr->numberUsed == 0) {
		printf("Array is empty\n");
	}

	for (int i = 0; i < arr->numberUsed; i++)
	{
		showTrapezium(arr->trapeziumArr[i]);
	}
}


void simplifiedPrintArray(TrapeziumArray *arr) {
	printf("\n[ ");
	for (int i = 0; i < arr->numberUsed; i++)
	{
		printf("%.2f ", calculateTrapeziumSquare(arr->trapeziumArr[i]));
	}
	printf("]\n\n");

}

int comparator(void *base, int indexA, int indexB) {
	if (base == NULL || indexA < 0 || indexB < 0)
	{
		return ERROR;
	}

	Trapezium **trArr = base;
	
	float sqrA = calculateTrapeziumSquare(trArr[indexA]);
	float sqrB = calculateTrapeziumSquare(trArr[indexB]);

	if (sqrA > sqrB) {
		return 1;
	}else if (sqrA < sqrB)
	{
		return -1;
	}
	else {
		return 0;
	}

}
