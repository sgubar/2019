#include <stdio.h>
#include "kek.h"

char problem[] = "(a+b+c)/(100-b-c) + (sum|d=0..a| 2^(d+a))";

int main(void)
{
  int a, b, c;
  printf("Enter variables: a>0 b>0 c>0\n");
  scanf("%f%f%f", &a, &b, &c);
  while (a < 0 || b < 0 || c < 0)
  {
    printf("Variables are wrong, try again!");
    printf("Enter variables: a>0 b>0 c>0\n");
    scanf("%f%f%f", &a, &b, &c);
  }
  printf("Solution for %s=%.4f\n", problem, solve(a, b, c));
  return 0;
}