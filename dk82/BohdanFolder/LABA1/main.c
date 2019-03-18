#include <stdio.h>
#include "tool.h"

int end(int base, int finish, int c, char* str);

int main(int argc, const char* argv[])
{
	int base = 0, finish = 0, c;
	char str[100];

	printf("Wwedit chisla dla funk sumi, chislo C i shisnat chislo:\n");
	scanf_s("%i %i %i\n", &base, &finish, &c);
	gets(str);
 	printf("Q = %i \n", end(base, finish, c, str));
	return 0;
}

int end(int base, int finish, int c, char* str)
{
	int result = u_system(str);
	int suma = sum(base, finish);

	return(suma * (result - c));
}