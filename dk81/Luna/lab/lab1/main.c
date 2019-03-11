#include <stdio.h>
#include "tool.h"
 
int main(int argc, char *argv[])
{
	printf_s("vvedite a\n");
	int a;
	scanf_s("%i", &a);
	 
	printf_s("vvedite b\n");
	int b;
	scanf_s("%i", &b);

	printf_s("vvedite c\n");
	int c;
	scanf_s("%i", &c);

	int resultat = formula(a, b, c);
	printf_s("resultat = %i\n", resultat);

	system("pause");

}