#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "quickSort.h"


void printm(int max_i, int mas[]);



int main(int argc, char *argv[])
 {
 	
 	
 	srand(time(NULL));

	int masiv[10000];
	int i, int_put;
	
 	
 	for(i=0; i<10000; i++){
 		do{
 			masiv[i] = rand();
		 }while(masiv[i] > 10000);
	 }
 	
 	
 	clock_t start_t = clock();
 	quickSort2(masiv, 0, 9999);
 	clock_t end_t = clock();
 	
 	
 	
 	printm(10000, masiv);
 	
 	printf("\n\ntime = %f\n", (double)(end_t - start_t)/CLOCKS_PER_SEC);
 	printf("\nvedite chislo: ");
 	scanf("%i", &int_put);
 	
 	//fun(masiv, 10000, int_put);
 	
 	for(i=0; i<10000; i++){
 		if(masiv[i]==int_put){
 			printf("\n%i", i);
 			i = 10000;
		 }
		 else if(i==9999 && masiv[i] !=int_put){
		 	printf("\nnumeric not search\n");
		 }
	 }	 
	 
	 
	 
	 
	 return 0;
 }
 
 
 void printm(int max_i, int mas[])
 {
 	
 	FILE * f;
 	
 	int i;
 	
 	
 	f = fopen("file2.txt", "w");
 	
 	for(i = 0; i < max_i; i++)
 	{
 		fprintf(f, "[%i]:%i ", i, mas[i]);
 		printf("[%i]:%i ", i, mas[i]);
	 }
	 
	 fclose(f); 
 }
 

