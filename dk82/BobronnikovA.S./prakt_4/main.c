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
	float area;
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

int Add(struct Rectangle* arrx)
{
	int size = sizeof(arrx) / sizeof(struct Rectangle) + 1;
	struct Rectangle* arr = (struct Rectangle*)malloc(sizeof(struct Rectangle*) * size);
	memcpy(arr, arrx, size * sizeof(struct Rectangle));
	return arr;
}

int Delete(struct Rectangle* arrx)
{
	int size = sizeof(arrx) / sizeof(struct Rectangle) - 1;
	struct Rectangle* arr = (struct Rectangle*)malloc(sizeof(struct Rectangle*) * size);
	memcpy(arr, arrx, size * sizeof(struct Rectangle));
	return arr;
}

int jsonwrite(struct Rectangle* arr, int size, FILE* file)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "'Rectangle': '%i'\n", i);
		fprintf(file, "'Coordinatesof0': [\n");
		fprintf(file, "	'x': %f\n", arr[i].coordinatesof0.x);
		fprintf(file, "	'y': %f\n", arr[i].coordinatesof0.y);
		fprintf(file, "]\n");
		fprintf(file, "'Coordinatesof1': [\n");
		fprintf(file, "	'x': %f\n", arr[i].coordinatesof1.x);
		fprintf(file, "	'y': %f\n", arr[i].coordinatesof1.y);
		fprintf(file, "]\n");
		fprintf(file, "'Coordinatesof2': [\n");
		fprintf(file, "	'x': %f\n", arr[i].coordinatesof2.x);
		fprintf(file, "	'y': %f\n", arr[i].coordinatesof2.x);
		fprintf(file, "]\n");
		fprintf(file, "'Area': %f\n\n", Area(arr[i]));
	}
}

int jsonshow(struct Rectangle* arr, int size)
{
	/*{
	"firstName": "Иван",
	"lastName" : "Иванов",
	"address" : {
	"streetAddress": "Московское ш., 101, кв.101",
	"city" : "Ленинград",
	"postalCode" : "101101"
	},
	"phoneNumbers" : [
	"812 123-1234",
	"916 123-4567"
	]
	}*/
	for (int i = 0; i < size; i++)
	{
		printf("'Rectangle': '%i'\n", i);
		printf("'Coordinatesof0': [\n");
		printf("	'x': %f\n", arr[i].coordinatesof0.x);
		printf("	'y': %f\n", arr[i].coordinatesof0.y);
		printf("]\n");
		printf("'Coordinatesof1': [\n");
		printf("	'x': %f\n", arr[i].coordinatesof1.x);
		printf("	'y': %f\n", arr[i].coordinatesof1.y);
		printf("]\n");
		printf("'Coordinatesof2': [\n");
		printf("	'x': %f\n", arr[i].coordinatesof2.x);
		printf("	'y': %f\n", arr[i].coordinatesof2.x);
		printf("]\n");
		printf("'Area': %f\n\n", Area(arr[i]));
	}
	return 0;
}

int selectionsort(struct Rectangle* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j].area > arr[i].area)
			{
				struct Rectangle temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 0;
}

int main()
{
	int size;
	printf("This program works with array of structures Rectangle\n");
	printf("Enter size of array you plan:\n");
	scanf("%i", &size);
	struct Rectangle * arr;
	arr = malloc(sizeof(struct Rectangle) * size);
	int choose = 0, i;
	while (choose != 911)
	{
		printf("Choose the index of rectangle:\n");
		scanf("%i", &i);
		printf("Choose option:\n1 -> Enter rectangle by index\n2 -> Info about rectangle\n");
		printf("3 -> Add new rectangle\n4 -> Delete last rectangle\n");
		printf("5 -> Show rectangle array in JSON format\n6 -> Write to file rectangle array in JSON format\n");
		printf("7 -> Sort rectangle array with selectionsort\n");
		printf("911 -> Delete array and exit the program...\n");
		scanf("%i", &choose);
		switch (choose)
		{
		case 1:
		{
			arr[i] = Enter();
			arr[i].area = Area(arr[i]);
			break;
		}
		case 2:
		{
			Display(arr[i]);
			break;
		}
		case 3:
		{
			Add(arr);
			break;
		}
		case 4:
		{
			Delete(arr);
			break;
		}
		case 5:
		{
			jsonshow(arr, size);
			break;
		}
		case 6:
		{
			FILE* S1;
			S1 = fopen("S1.txt", "w");
			jsonwrite(arr, size, S1);
			fclose(S1);
			break;
		}
		case 7:
		{
			selectionsort(arr, size);
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
	free(arr);
	system("pause");
	return 0;
}
