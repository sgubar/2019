#include "tool.h"

int stepen(int chislo) {
	int resultat;
	resultat = chislo * chislo;
	return resultat;
}

int factorial(int chislo) {
	int resultat = 1;
	
	if (chislo < 0)
	{
		printf_s("factorial can`t be lower than ZERO\n");
		return ERROR; 

	}
	 
	for (int i = 1; i <= chislo; i++)
	{
		resultat = resultat * i;
	}

	return resultat;
}
int suma(int chislo)
{
	int b;
	int resultat = 0;

	if (chislo < 0)
	{
	    printf_s("suma can`t be lower than ZERO\n");

		return ERROR;
	}

	for (b = 0; b <=chislo; b++)
	{
		resultat = resultat + factorial(b);
		
	}
	return resultat;
}

int formula(int a, int b, int c)
{
	int resultat = 0;

	resultat = ((a*b) / (b + stepen(c))) + suma(b);

	return resultat;

}
