#include <stdio.h>
#define ERROR -124

typedef struct cfgDot {
	int x;
	int	y;
}Dot;

typedef struct cfgCircle {
	Dot *O;
	int radius;
}Circle;

Circle *createCircle (Dot *O, int radius);
void destroyCircle (Circle *circle);

void printCircle (Circle *circle);

