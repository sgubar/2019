#include <math.h>
#include "header.h"

float power(float a)        
{
    float i, power = 1;     
	for(i = 1; i <= a; i++)
	{
		power = 2 * power;
		
	}
	return power;

//	return pow(2, a);
}

float sum(float a)
{
  float i, sum = 0;
  for (i = 0; i <= a; i++)
  {
    sum = power(i+a) + sum;
  }
  return sum;
  
}  

float division(float a, float b, float c)
{
  float k, g, m;
  
  k = a + b + c;
  g = 100 - b - c;
  m = k / g;
  
  return m;
}

float result(float a, float b, float c)
{ 
  float q;
  q = division(a, b, c) + sum(a);
  
  return q;
}

