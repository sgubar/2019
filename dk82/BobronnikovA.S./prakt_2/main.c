#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
	float x;
	float y;
};

struct Rectangle {

	struct Point coordinatesof0;
	struct Point coordinatesof1;
	struct Point coordinatesof2;
};

struct Rectangle Enter()
{
	struct Rectangle Rectangle;
	printf("Enter 6 coordinates for 3 points of rectangle\nMake sure 'y' of first coordinate = 'y' of second\n");
	printf("Make sure 'x' of first coordinate = 'x' of third\n");

	printf("Enter 'x' for first:\n");
	scanf("%f", &Rectangle.coordinatesof0.x);
	printf("Enter 'y' for first:\n");
	scanf("%f", &Rectangle.coordinatesof0.y);

	printf("Enter 'x' for second:\n");
	scanf("%f", &Rectangle.coordinatesof1.x);
	printf("Enter 'y' for second:\n");
	do
		scanf("%f", &Rectangle.coordinatesof1.y);
	while (Rectangle.coordinatesof1.y != Rectangle.coordinatesof0.y);

	printf("Enter 'x' for third:\n");
	do
		scanf("%f", &Rectangle.coordinatesof2.x);
	while (Rectangle.coordinatesof2.x != Rectangle.coordinatesof0.x);
	printf("Enter 'y' for third:\n");
	scanf("%f", &Rectangle.coordinatesof2.y);

	return Rectangle;
}

float Area(struct Rectangle Rectangle)
{
	return sqrt(pow((Rectangle.coordinatesof1.x - Rectangle.coordinatesof0.x), 2) + pow((Rectangle.coordinatesof1.y - Rectangle.coordinatesof0.y), 2)) *
		sqrt(pow((Rectangle.coordinatesof2.x - Rectangle.coordinatesof0.x), 2) + pow((Rectangle.coordinatesof2.y - Rectangle.coordinatesof0.y), 2));
}

int Display(struct Rectangle Rectangle)
{
	printf("This rectangle has properties:\n");
	printf("Coordinates of points:\n");
	printf("%f %f\n%f %f\n%f %f\n", Rectangle.coordinatesof0.x, Rectangle.coordinatesof0.y, Rectangle.coordinatesof1.x,
	Rectangle.coordinatesof1.y, Rectangle.coordinatesof2.x, Rectangle.coordinatesof2.y);
	printf("Area: %f\n", Area(Rectangle));
}

int Delete()
{

}

int main()
{
	printf("This program works with structures Rectangle\n");
	
	struct Rectangle First;
	struct Rectangle Second;
	struct Rectangle Third;
	int choose = 0;
	while (choose != 911)
	{
		printf("Choose option:\n1 -> Enter FIRST rectangle\n2 -> Info about FIRST rectangle\n3 -> Delete FIRST rectangle\n");
		printf("4 -> Enter SECOND rectangle\n5 -> Info about SECOND rectangle\n6 -> Delete SECOND rectangle\n");
		printf("7 -> Enter THIRD rectangle\n8 -> Info about THIRD rectangle\n9 -> Delete THIRD rectangle\n");
		printf("911 -> Exit the program...\n");
		scanf("%i", &choose);
		switch (choose)
		{
		case 1:
		{
			First = Enter();
			break;
		}
		case 2:
		{
			Display(First);
			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{
			Second = Enter();
			break;
		}
		case 5:
		{
			Display(Second);
			break;
		}
		case 6:
		{

			break;
		}
		case 7:
		{
			Third = Enter();
			break;
		}
		case 8:
		{
			Display(Third);
			break;
		}
		case 9:
		{

			break;
		}
		case 911:
			break;
		default:
		{
			printf("Wrong choose...\n");
			break;
		}
		}
	}
	system("pause");
	return 0;
}
