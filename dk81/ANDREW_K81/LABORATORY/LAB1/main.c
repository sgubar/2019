#include <stdio.h>
#include "lab1.h"


void forUser(void)
{
  double a=0, b=0, c=0;
  char problem[] = "(a+b+c)/(100-b-c) + (sum|d=0..a| 2^(d+a))";
    printf("Enter variables: a>0 b>0 c>0\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
  while (a < 0 || b < 0 || c < 0 || (100-b-c)<0)
  {
    printf("Variables are wrong, try again!\n");
    printf("Enter variables: a>0 b>0 c>0\n");
    scanf("%lf%lf%lf", &a, &b, &c);
  }
    printf("Solution for %s = %.4lf\n", problem, solve(a, b, c));

  return;
} 

int main(void)
{
  forUser();
  return 0;
  
}