#include <stdio.h>
#include <Math.h>
#define ERROR -4364368

typedef struct tagDot {
	int x;
	int y;
}Dot;

typedef struct tagTrapezium {
	 Dot *leftBottomCorner;
	 Dot *leftTopCorner;
	 Dot *rightTopCorner;
	 Dot *rightBottomCorner;
}Trapezium;

Dot *createDot();
Trapezium *createTrapezium();
void deleteDot(Dot *dot);
void deleteTrapezium(Trapezium *figure);
void showTrapezium(Trapezium *figure);
void showDot(Dot *d);
void printTrapezium(Trapezium *trap);

Dot* findLeftDot(Trapezium *trap);
Dot* findRightDot(Trapezium *trap);
Dot* findTopDot(Trapezium *trap);
Dot* findBottomDot(Trapezium *trap);

int compareDot(Dot *a,int x, int y,int offsetX, int offsetY);

float calculateLineLength(Dot *a, Dot *b);