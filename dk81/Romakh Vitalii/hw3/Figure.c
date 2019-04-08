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
	
	trap->ab = calculateLineLength(trap->leftBottomCorner, trap->leftTopCorner);
	trap->bc = calculateLineLength(trap->leftTopCorner, trap->rightTopCorner);
	trap->cd = calculateLineLength(trap->rightTopCorner, trap->rightBottomCorner);
	trap->da = calculateLineLength(trap->rightBottomCorner, trap->leftBottomCorner);
	trap->square = calculateTrapeziumSquare(trap);

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

	trap->square = calculateTrapeziumSquare(trap);
	return trap;
}

void showDot(Dot *d) { //Вывести точку на экран
	printf("x = %i\n", d->x);
	printf("y = %i\n", d->y);
}

void showTrapezium(Trapezium *t) { //Вывести данные про фигуру на экран

	printTrapezium(t); // Вывести фигуру на экран

	printf("\n---------------------------------------------\n");

	printf("Left Bottom Dot - A:\n");
	showDot(t->leftBottomCorner);

	printf("Left Top Dot - B:\n");
	showDot(t->leftTopCorner);

	printf("Right Top Dot - C:\n");
	showDot(t->rightTopCorner);

	printf("Right Bottom Dot - D:\n");
	showDot(t->rightBottomCorner);


	printf("Length Line AB: %f\n", t->ab);
	printf("Length Line BC: %f\n", t->bc);
	printf("Length Line CD: %f\n", t->cd);
	printf("Length Line DA: %f\n", t->da);

	printf("\nSquare = %f\n", t->square);

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


void printTrapezium(Trapezium *trap) { // Вывод на экран

	// Я ищу крайные точки для того чтобы найти высоту и длину для цикла для того чтобы напечатать ттрапецию
	Dot* leftDot = findLeftDot(trap);
	Dot* rightDot = findRightDot(trap);
	Dot* topDot = findTopDot(trap);
	Dot* bottomDot = findBottomDot(trap);



	int offsetX = leftDot->x;
	int offsetY = bottomDot->y;

	int width = rightDot->x - leftDot->x;
	int height = topDot->y - bottomDot->y;

	int resDotID = ERROR;

	for (int i = height + 1; i >= -1; i--)
	{
		for (int j = -1; j <= width + 1; j++)
		{
			resDotID = compareDot(trap->leftBottomCorner, j, i, offsetX, offsetY, resDotID);  // Для того чтобы понять какая точка находится в координатах.
			resDotID = compareDot(trap->leftTopCorner, j, i, offsetX, offsetY, resDotID);
			resDotID = compareDot(trap->rightTopCorner, j, i, offsetX, offsetY, resDotID);
			resDotID = compareDot(trap->rightBottomCorner, j, i, offsetX, offsetY, resDotID);

			if (resDotID != ERROR) {
				printf("%c", resDotID);
				resDotID = ERROR;
				continue;
			}
			else {
				printf(" ");
			}

		}
		printf("\n");
	}
}

Dot* findLeftDot(Trapezium *trap) { // Поиск крайней левой точки
	if (trap->leftBottomCorner->x < trap->leftTopCorner->x) {
		return trap->leftBottomCorner;
	}
	else if (trap->leftBottomCorner->x > trap->leftTopCorner->x) {
		return  trap->leftTopCorner;
	}
	else {
		return trap->leftTopCorner;
	}
}

Dot* findRightDot(Trapezium *trap) { // Поиск крайней правой точки
	if (trap->rightBottomCorner->x < trap->rightTopCorner->x) {
		return trap->rightTopCorner;
	}
	else if (trap->rightBottomCorner->x > trap->rightTopCorner->x) {
		return trap->rightBottomCorner;
	}
	else {
		return trap->rightTopCorner;
	}
}

Dot* findTopDot(Trapezium *trap) {// Поиск крайней верхней точки
	if (trap->leftTopCorner->y < trap->rightTopCorner->y) {
		return trap->rightTopCorner;
	}
	else if (trap->leftTopCorner->y > trap->rightTopCorner->y) {
		return trap->leftTopCorner;
	}
	else {
		return trap->leftTopCorner;
	}
}

Dot* findBottomDot(Trapezium *trap) { // Поиск крайней нижней точки
	if (trap->leftBottomCorner->y < trap->rightBottomCorner->y) {
		return trap->leftBottomCorner;
	}
	else if (trap->leftBottomCorner->y > trap->rightBottomCorner->y) {
		return trap->rightBottomCorner;
	}
	else {
		return trap->rightBottomCorner;
	}
}

int compareDot(Dot *d, int x, int y, int offsetX, int offsetY, int currentId) { //Функия создана для того чтобы определить одинакова ли точка d и точка с координатами x и y, offsetX и offsetY даны для того чтобы перевести точку с х и у в систему координат точки d
	if (currentId != ERROR) {
		return currentId;
	}
	if (d->x - offsetX == x && d->y - offsetY == y) {
		return d->id;
	}
	else {
		return ERROR;
	}
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

void printToFileTrapezium(FILE *file, Trapezium *trapezium) {
	if (trapezium == NULL) {
		return ERROR;
	}
	


	fprintf(file, "		  {\n");

	
	fprintf(file, "		    \"AB\": %f,\n", trapezium->ab);
	fprintf(file, "		    \"BC\": %f,\n", trapezium->bc);
	fprintf(file, "		    \"CD\": %f,\n", trapezium->cd);
	fprintf(file, "		    \"DA\": %f,\n", trapezium->da);
	fprintf(file, "		    \"square\": %f,\n", trapezium->square);


	fprintf(file, "			  \"dots\": [\n");
	

		fprintf(file, "				{\n");
		fprintf(file, "					\"id\": \"%c\", \n", trapezium->leftBottomCorner->id);
		fprintf(file, "					\"x\": %i, \n",trapezium->leftBottomCorner->x);
		fprintf(file, "					\"y\": %i \n", trapezium->leftBottomCorner->y);
		fprintf(file, "				},\n");
			

		fprintf(file, "				{\n");
		fprintf(file, "					\"id\": \"%c\", \n", trapezium->leftTopCorner->id);
		fprintf(file, "					\"x\": %i, \n", trapezium->leftTopCorner->x);
		fprintf(file, "					\"y\": %i \n", trapezium->leftTopCorner->y);
		fprintf(file, "				},\n");


		fprintf(file, "				{\n");
		fprintf(file, "					\"id\": \"%c\", \n", trapezium->rightTopCorner->id);
		fprintf(file, "					\"x\": %i, \n", trapezium->rightTopCorner->x);
		fprintf(file, "					\"y\": %i \n", trapezium->rightTopCorner->y);
		fprintf(file, "				},\n");


		fprintf(file, "				{\n");
		fprintf(file, "					\"id\": \"%c\", \n", trapezium->rightBottomCorner->id);
		fprintf(file, "					\"x\": %i, \n", trapezium->rightBottomCorner->x);
		fprintf(file, "					\"y\": %i \n", trapezium->rightBottomCorner->y);
		fprintf(file, "				}\n");


	fprintf(file, "		]\n");



	fprintf(file, " }");

}
