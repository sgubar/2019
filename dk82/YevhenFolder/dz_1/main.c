#include <stdio.h>
#include <stdlib.h>
#include "tool.h"


int main()
{
Point A = { 3,15 };
Point B = { 3,3 };
Point C = { 8,3 };

Prtr* ABC= CreatePrtrByPoints(&A, &B, &C);

printPrtr(ABC);
float square = squarePrtr(ABC);
printf("\nSquare of prtr :%f \n", square);
system("PAUSE");
return 0;
}
