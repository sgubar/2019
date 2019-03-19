#include "dk_tools.h"
#include <string.h>
#include <stdio.h>
int returnDex_minus_C(char* F , int C)
{
	int search;
	int dex = 0;
	int step = 1;
	int x = 0;
	int len;
	len = strlen(F);
	
	
		for (int i = len - 1; i >= 0; i--)
		{
			if (F[i] >= '0' && F[i] <= '9')
			{
				search = (F[i] - 48) * step;
				step = 16 * step;
				dex = dex + search;
			}
			else if (F[i] >= 'A' && F[i] <= 'F')
			{
				search = (F[i] - 55) * step;
				step = 16 * step;
				dex = dex + search;
			}
			else if (F[i] >= 'a' && F[i] <= 'f')
			{
				search = (F[i] - 87) * step;
				step = 16 * step;
				dex = dex + search;
			}
			else
			{
				printf_s("\nERROR");
				exit(404);
			}
		}

		return dex - C;
	

}



int summ(int D, int minus_plus_dex) {
	int sum = 0;
	
	
	for (int A = 1; A <= D; A++) 
	{
		sum = sum + A * minus_plus_dex;
	}
	return sum;
}

int Q(int C, char* F, int D)
{
	int Dex = returnDex_minus_C(F, C);
	int Finish = summ(D, Dex);
	return Finish;
}
