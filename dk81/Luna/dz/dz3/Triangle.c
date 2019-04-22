#include <math.h>
#include "triangle.h"
#define ERROR  -525;

Dot *createDot(int x, int y) {
	Dot *dot = malloc(sizeof(Dot));
	dot->x = x;
	dot->y = y;

	return dot;
}

Triangle *createTriangle(Dot *a, Dot *b, Dot *c) {
	float ab = CulcSide(a, b);
	float bc = CulcSide(b, c);
	float ac = CulcSide(a, c);

	if (ab + bc <= ac || ab + ac <= bc || bc + ac <= ab)
	{
		printf_s("Oshibka");
		return ERROR;
	}

	Triangle *trukytnuk = malloc(sizeof(Triangle));
	trukytnuk->a = a;
	trukytnuk->b = b;
	trukytnuk->c = c;

	return trukytnuk;

}


void deleteTriangle(Triangle *triugolnik) {
	free(triugolnik->a);
	free(triugolnik->b);
	free(triugolnik->c);
	free(triugolnik);
}


void outputData(Triangle *triugolnik)
{
	printf_s("a:\n");
	outputDot(triugolnik->a);
	printf_s("b:\n");
	outputDot(triugolnik->b);
	printf_s("c:\n");
	outputDot(triugolnik->c);

	printf_s("ab=%f\n", CulcSide(triugolnik->a, triugolnik->b));
	printf_s("bc=%f\n", CulcSide(triugolnik->b, triugolnik->c));
	printf_s("ac=%f\n", CulcSide(triugolnik->a, triugolnik->c));

	printf_s("square = %f\n", Square(triugolnik));
}
float Square(Triangle *triangle)
{
	float ab = CulcSide(triangle->a, triangle->b);
	float bc = CulcSide(triangle->b, triangle->c);
	float ac = CulcSide(triangle->a, triangle->c);

	float pol = ((ab + bc + ac) / 2);
	float square = sqrt(pol*(pol - ab)*(pol - bc)*(pol - ac));
	return square;
}


float CulcSide(Dot *a, Dot *b)
{
	int x2 = b->x;
	int x1 = a->x;
	int y2 = b->y;
	int y1 = a->y;

	float result = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

	return result;
}


void outputDot(Dot *a)
{
	printf_s("x = %i\n", a->x);
	printf_s("y = %i\n", a->y);
}


TriangleArray *createArray(int dlina) {
	TriangleArray *theResult = NULL;

	if (dlina > 0)
	{
		theResult = (TriangleArray *)malloc(sizeof(TriangleArray));

		if (NULL != theResult)
		{
			theResult->arr = (Triangle **)malloc(sizeof(Triangle *)  * dlina);  //выделяем память для массива треугольников  

			for (int i = 0; i < dlina; i++)
			{
				theResult->arr[i] = NULL;
			}

			if (NULL != theResult->arr)
			{
				theResult->dlina = dlina;
				theResult->kolichestvo = 0;
			}
			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}
