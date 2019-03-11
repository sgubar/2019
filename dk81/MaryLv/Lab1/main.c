#include <stdio.h>
#include "tool.h"

int q(int a, int b);
int main(void)
{

	printf("Result is: %i\n", q(4, 4));
	system("pause");
	return 0;
}

int q(int a, int b)
{
	int result = fuc(a) / mod((2 * a) + b);
	return result;
}
