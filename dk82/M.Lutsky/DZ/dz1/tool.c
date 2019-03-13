#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tool.h"


int poweri(int base, int po)
{
	int result = 1;
	for (int i = 0; i < po; i++) {
		result *= base;
	}
	return result;
}


int fac(int base)
{
	int result = 1;
	if (base > 0) {
		for (int i = base; i > 0; i--) {
			result *= i;
		}
	}
	else
	{
		for (int i = base; i < 0; i++) {
			result *= i;
		}
	}
	return result;
}
