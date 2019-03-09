#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "dk_tool.h"


int main(int argc, char *argv[]){
	int l, h;
	printf("Enter length of matrix\n");
	scanf("%d", &l);
	printf("Enter height of matrix\n");
	scanf("%d", &h);
	
	if (l < 1 || h < 1)
	    {
	        printf("Input error");
	        return -1;
	    }
	int m = getMass(l, h);
	if (m == -1)
		{
			return 0;
		}
	printMass(m, l, h);

/*	int l, h;
	printf("Enter length of matrix\n");
	scanf("%d", &l);
	printf("Enter height of matrix\n");
	scanf("%d", &h);
	printMass(getMass(l, h), l, h);
*/	
//system("PAUSE");
return 0;
}
