#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void help()
{
	printf("###SYNTAX###\n\n\t./matrix [action] [height] [width]\n\nList of actions:\n\t1 is A + B\n\t2 is A - B\n\t3 is (A or B) * n\n\n");
}

int main(int argc, char **argv)
{	
	//foolproof
	if (argc != 4){
		help();
		return 1;
	}
	
	//taking action and a size of matrix
	int act = atoi(argv[1]);
	int col = atoi(argv[2]);
	int row = atoi(argv[3]);
	char choice;
	
	//requesting memory
	int *p_mA, *p_mB, *p_mC;
	p_mA = (int*)malloc(col*row*sizeof(int));
	p_mB = (int*)malloc(col*row*sizeof(int));
	p_mC = (int*)malloc(col*row*sizeof(int));

	//random matrix
	srand(time(NULL));
	matr_rand(p_mA, col, row);
	matr_rand(p_mB, col, row);
	
	//displaying matrixes
	printf("A\n");
	matr_print(p_mA, col, row);
	printf("B\n");
	matr_print(p_mB, col, row);
	
	switch (act)
	{
		case 1:			
			//summing
			printf("A + B = C\n");
			matr_add(p_mA, p_mB, p_mC, col, row);
			matr_print(p_mC, col, row);
			break;
			
		case 2:			
			//subtraction
			printf("A - B = C\n");
			matr_sub(p_mA, p_mB, p_mC, col, row);
			matr_print(p_mC, col, row);
			break;
			
		case 3:			
			//multiply by number
			printf("Choose a matrix (A or B):\n");
			do
			{
				scanf("%c", &choice);
			}
			while (choice != 'A' && choice != 'B');
			
			if (choice == 'A')
			{
				printf("A * n\n");
				matr_multBy(p_mA, col, row);
				matr_print(p_mA, col, row);
			}
			else
			{
				printf("B * n\n");
				matr_multBy(p_mB, col, row);
				matr_print(p_mB, col, row);
			}
			break;
			
		default:
			help();
			break;
	};
	
	//free the memory
	free(p_mA);
	free(p_mB);
	free(p_mC);
	return 0;
}
