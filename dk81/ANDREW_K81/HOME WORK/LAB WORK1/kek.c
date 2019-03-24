#include <math.h>
#include "kek.h"

double pow2(double a) // a => 2^a
{
  return pow(2, a); // (x, y) => x^y
  
} 

double sum(double n)
{
  unsigned long sum = 0;
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
