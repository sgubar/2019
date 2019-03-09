#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "dk_tool.h"

int getMass(int l, int h)
	{
	int i;
	srand (time(NULL));
	int *mass = (int*) malloc(sizeof(int)*l);
	if (mass == NULL)
		{
			return -1;
		}
	int i1 = 0;
	int j1 = 0;
	for (i = 0; i < l*h; i++)
		{
		printf("Matrix[%d][%d] = ", i1, j1);
    	scanf("%d\n", &mass[i]);
    	j1++;
    	if (j1>=l)
    	    {
    	        j1 = 0;
    	        i1++;
    	    }
    	//mass[i] = rand()%10;
		}
	return mass;
}

int printMass(int *m, int l, int h)
	{
	int i, j;

	printf("Matrix A\n");
	for (i = 0; i < l*h; i++)  
  		{	
     	printf("%d ", m[i]);
     	
     	if ((i+1)%l == 0)
     		{
    		printf("\n");
    		}		
  		}
  		printf("\n");
  		printf("Matrix A(T)\n");
  		
  	int n = 0;
  	int flag = 0;
  	int n2 = 1;
  	
	for (i = 0; i < l*h; i++)  
  		{
  			printf("%d ", m[n]);
  			
  			if ((i+1)%h == 0)
     		{
    		printf("\n");
    		}
    		
    		n = n+l;
    		flag++;
    		
    		if (flag == h)
    			{
    				n = 0;
    				n = n+n2;
    				flag = 0;
    				n2++;
				}
  		}

}
