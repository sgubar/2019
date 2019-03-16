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

Dot *generateDot(int x, int y, char id) {
	Dot *d = (Dot *)malloc(sizeof(Dot));

	d->x = x;
	d->y = y;
	d->id = id;

	return d;
}

Trapezium *generateTrapezium(int radius) {
	time_t t;
	srand((unsigned)time(&t));
	Trapezium *trap = (Trapezium *)malloc(sizeof(Trapezium));
	
	trap->leftBottomCorner = generateDot(0, 0, 'A');
	trap->leftTopCorner = generateDot(rand() % radius + 1, rand() % radius + 1, 'B');
	trap->rightTopCorner = generateDot(trap->leftTopCorner->x + rand() % radius + 1, rand() % radius + 1, 'C');
	trap->rightBottomCorner = generateDot(trap->rightTopCorner->x + rand() % radius + 1, trap->rightTopCorner->y - rand() % radius - 1,'D');

	trap->square = calculateTrapeziumSquare(trap);

	return trap;
}

Trapezium *createTrapezium() {
	Trapezium *trap = (Trapezium *)malloc(sizeof(Trapezium));
	
	
			printf("Input left bottom dot - A:\n");
			trap->leftBottomCorner = createDot();
			trap->leftBottomCorner->id = 'A';

			printf("\nInput left top dot - B:\n");
			trap->leftTopCorner = createDot();
			trap->leftTopCorner->id = 'B';

			if (trap->leftTopCorner->y <= trap->leftBottomCorner->y) {
				printf("Top corner couldn't be lower than bottom corner!\n");
				return ERROR;
			}

			printf("\nInput right top dot - C:\n");
			trap->rightTopCorner = createDot();
			trap->rightTopCorner->id = 'C';

			if (trap->rightTopCorner->x <= trap->leftTopCorner->x) {
				printf("Left corner couldn't be righter than left corner!\n");
				return ERROR;
			}
			


			printf("\nInput right bottom dot - D:\n");
			trap->rightBottomCorner = createDot();
			trap->rightBottomCorner->id = 'D';

			if (trap->rightBottomCorner->y >= trap->rightTopCorner->y) {
				printf("Top corner couldn't be lower than bottom corner!\n");
				return ERROR;
			}
			else if (trap->rightBottomCorner->x <= trap->leftBottomCorner->x) {
				printf("Left corner couldn't be righter than left corner!\n");
				return ERROR;
			}

		trap->square = calculateTrapeziumSquare(trap);
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
	
		
	printf("Length Line AB: %f\n", calculateLineLength(t->leftBottomCorner, t->leftTopCorner));
	printf("Length Line BC: %f\n", calculateLineLength(t->leftTopCorner, t->rightTopCorner));
	printf("Length Line CD: %f\n", calculateLineLength(t->rightTopCorner, t->rightBottomCorner));
	printf("Length Line DA: %f\n", calculateLineLength(t->rightBottomCorner, t->leftBottomCorner));

	printf("\nSquare = %f\n", t->square);

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

	int resDotID = ERROR;

	for (int i = height+1; i >= -1; i--)
	{
		for (int j = -1; j <= width+1; j++)
		{
			resDotID = compareDot(trap->leftBottomCorner, j, i, offsetX, offsetY, resDotID);
			resDotID = compareDot(trap->leftTopCorner, j, i, offsetX, offsetY, resDotID);
			resDotID = compareDot(trap->rightTopCorner, j, i, offsetX, offsetY, resDotID);
			resDotID = compareDot(trap->rightBottomCorner, j, i, offsetX, offsetY, resDotID);

			if (resDotID != ERROR) {
				printf("%c", resDotID);
				resDotID = ERROR;
				continue;
			}else if (isOnLine(trap->leftBottomCorner, trap->leftTopCorner,j,i) == 1 || isOnLine(trap->leftTopCorner, trap->rightTopCorner, j, i) == 1 || isOnLine(trap->rightTopCorner, trap->rightBottomCorner, j, i) == 1 || isOnLine(trap->rightBottomCorner, trap->leftBottomCorner, j, i) == 1) {
				printf("*");
			}else{
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

int compareDot(Dot *d, int x, int y,int offsetX, int offsetY, int currentId){
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

int isOnLine(Dot *a, Dot *b, int x, int y) {
Dot *c = generateDot(x,y,'N');

    /*int as = calculateLineLength(a, b);
	int bs = calculateLineLength(b, c);
	int cs = calculateLineLength(c, a);

	float halfPerimetr = (as + bs + cs) / 2;
	float square = sqrt(halfPerimetr*(halfPerimetr - as)*(halfPerimetr - bs)*(halfPerimetr - cs));

	printf("%i , %i, %c, %c, s = %f\n", x, y, a->id,b->id, square);

	if (isnan(square))
	{
		return 1;
	}
	return 0;
	*/

	int dx1 = b->x - a->x;
	int dy1 = b->y - a->y;

	int dx = x - a->x;
	int dy = y - a->y;

	float s = dx1 * dy - dx * dy1;

	float ab = sqrt(dx1 * dx1 + dy1 * dy1);

	float h = s / ab;

	if (h <= 0.8 && h >= 0)
	{
		return 1;
	}
	return 0;
}

float calculateTrapeziumSquare(Trapezium *trap) {
	float a = trap->leftBottomCorner->x * trap->leftTopCorner->y + trap->leftTopCorner->x * trap->rightTopCorner->y + trap->rightTopCorner->x * trap->rightBottomCorner->y + trap->rightBottomCorner->x * trap->leftBottomCorner->y;
	float b = trap->leftBottomCorner->y * trap->leftTopCorner->x + trap->leftTopCorner->y * trap->rightTopCorner->x + trap->rightTopCorner->y * trap->rightBottomCorner->x + trap->rightBottomCorner->y * trap->leftBottomCorner->x;

	float result = a + b;
	return result;
}
