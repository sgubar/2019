#include <math.h>
#include "lab1.h"

double pow2(double a) 
{
  return pow(2, a); // (x, y) => x^y
} 

double sum(double n) // cycle summing of pow
{
  double sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += pow2(i+n);
  }
  return sum;
}

double solve(double a, double b, double c)
{
  double result = (a + b + c)/(100 - b - c);
  result += sum(a);
  return result;
}