#include <stdio.h>
#include "header.h"


void main (void)
{
  
  
  float a, b, c;
  
  printf("Enter numbers of A, B, C: \n");

  printf("A = ");
  scanf("%f", &a);
  
  printf("B = ");
  scanf("%f", &b);
  
  printf("C = ");
  scanf("%f", &c);

  if (100 - (b + c) == 0)
  {
  	
	  printf("Denominator is 0. Please try again: \n");

  	printf("Enter numbers of A, B, C: \n");
  	printf("A = ");
  	scanf("%f", &a);
  
  	printf("B = ");
  	scanf("%f", &b);
  
  	printf("C = ");
  	scanf("%f", &c);
  	
   }

   printf("The result of Q = %.2f\n", result(a, b, c));
   
  return;
}


