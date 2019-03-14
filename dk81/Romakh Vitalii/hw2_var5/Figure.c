#include "Figure.h"
#include <stdio.h>


Dot *createDot() {
	Dot *d = (Dot *)malloc(sizeof(Dot));
	
	int x, y;

	printf("Input x:\n");
	scanf_s("%i",&x);

	printf("Input y:\n");
	scanf_s("%i", &y);

	d->x = x;
	d->y = y;

	return d;
}

Trapezium *createTrapezium() {
	Trapezium *trap = (Trapezium *)malloc(sizeof(Trapezium));
	
	
			printf("Input left bottom dot - D:\n");
			trap->leftBottomCorner = createDot();

			printf("\nInput left top dot - A:\n");
			trap->leftTopCorner = createDot();

			if (trap->leftTopCorner->y <= trap->leftBottomCorner->y) {
				printf("Top corner couldn't be lower than bottom corner!\n");
			}

			printf("\nInput right top dot - B:\n");
			trap->rightTopCorner = createDot();

			if (trap->rightTopCorner->x <= trap->leftTopCorner->x) {
				printf("Left corner couldn't be righter than left corner!\n");
			}
			else if (trap->rightTopCorner->y <= trap->leftBottomCorner->y) {
				printf("Top corner couldn't be lower than bottom corner!\n");
			}


			printf("\nInput right bottom dot - C:\n");
			trap->rightBottomCorner = createDot();

			if (trap->rightBottomCorner->y >= trap->rightTopCorner->y) {
				printf("Top corner couldn't be lower than bottom corner!\n");
			}
			else if (trap->rightBottomCorner->x <= trap->leftBottomCorner->x) {
				printf("Left corner couldn't be righter than left corner!\n");

			}


		return trap;
}

void showDot(Dot *d) {
	printf("x = %i\n",d->x);
	printf("y = %i\n", d->y);
}

void showTrapezium(Trapezium *t) {

	printTrapezium(t);

	printf("\n---------------------------------------------\n");

	printf("Left Bottom Dot - A:\n");
	showDot(t->leftBottomCorner);

	printf("Left Top Dot - B:\n");
	showDot(t->leftTopCorner);

	printf("Right Top Dot - C:\n");
	showDot(t->rightTopCorner);

	printf("Right Bottom Dot - D:\n");
	showDot(t->rightBottomCorner);

	printf("Length Line AB: %f\n",calculateLineLength(t->leftTopCorner, t->rightTopCorner));
	printf("Length Line BC: %f\n", calculateLineLength(t->rightTopCorner, t->rightBottomCorner));
	printf("Length Line CD: %f\n", calculateLineLength(t->rightBottomCorner, t->leftBottomCorner));
	printf("Length Line DA: %f\n", calculateLineLength(t->leftBottomCorner, t->leftTopCorner));

	printf("\n");
}

void deleteDot(Dot *dot) {
	free(dot);
}

void deleteTrapezium(Trapezium *trapezium) {
	deleteDot(trapezium->leftBottomCorner);
	deleteDot(trapezium->leftTopCorner);
	deleteDot(trapezium->rightTopCorner);
	deleteDot(trapezium->rightBottomCorner);

	free(trapezium);
}

float calculateLineLength(Dot *a, Dot *b) {
	int deltaX = b->x - a->x;
	int deltaY = b->y - a->y;

	float result = sqrt(deltaX*deltaX + deltaY* deltaY);
	return result;
}


void printTrapezium(Trapezium *trap) {
	Dot* leftDot = findLeftDot(trap);
	Dot* rightDot = findRightDot(trap);
	Dot* topDot = findTopDot(trap);
	Dot* bottomDot = findBottomDot(trap);

	int offsetX = leftDot->x;
	int offsetY = bottomDot->y;

	int width = rightDot->x - leftDot->x;
	int height = topDot->y - bottomDot->y;

	for (int i = height; i >= 0; i--)
	{
		for (int j = width; j >= 0; j--)
		{
			if (compareDot(leftDot,j,i,offsetX,offsetY) == 1|| compareDot(rightDot, j, i,offsetX, offsetY) == 1 || compareDot(topDot, j, i, offsetX, offsetY) == 1 || compareDot(bottomDot, j, i, offsetX, offsetY) == 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

Dot* findLeftDot(Trapezium *trap) {
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

Dot* findRightDot(Trapezium *trap) {
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

Dot* findTopDot(Trapezium *trap) {
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

Dot* findBottomDot(Trapezium *trap) {
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

int compareDot(Dot *d, int x, int y,int offsetX, int offsetY){
	//Сделать проверку меньше или больше нуля соответсвено отнять или добавить оффсет
	if (d->x - offsetX == x && d->y - offsetY == y) {
		return 1;
	}
	else {
		return 0;
	}
}