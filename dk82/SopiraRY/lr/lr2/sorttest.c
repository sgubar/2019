#include "sort.h"

void help()
{
	printf("###SYNTAX###\n\n\t./sorttest [array size]\n\t\t[array size] must be an integer.\n\n");
}

int main(int argc, char **argv)
{
	//foolproof
	if (argc != 2 || atoi(argv[1]) < 0){
		help();
		return -1;
	}
	
	const char filepath[] = "sort.txt";
	
	//opening file 4 writing chaos
	FILE *sortfile;
	if ((sortfile = fopen(filepath, "w")) == NULL){
		fileerror();
		return -1;
	}

	//placing chaotic letters (aka writing unsorted stuff)
	srand(time(NULL));
	chaosfillFile(sortfile, filepath, atoi(argv[1]));
	fclose(sortfile);
	
	//opening file 4 reading
	if ((sortfile = fopen(filepath, "r")) == NULL){
		fileerror();
		return -1;
	}
	
	//initializing stuff
	char *array, *copyarr;
	array = (char*)malloc(atoi(argv[1])*sizeof(char));

	//reading unsorted stuff
	for (int i = 0; i < atoi(argv[1]); i++)
		fscanf(sortfile, "%c", &array[i]);
	
	fclose(sortfile);
	
	//opening file 4 additions
	if ((sortfile = fopen(filepath, "a+")) == NULL){
		fileerror();
		return -1;
	}
	
	//making a timer
	clock_t start, end;
	
	//bubble sort		
		//copying unsorted array (can be function)
	copyarr = copyArray(array, atoi(argv[1]));
	
		//testing bubble sort
	start = clock();
	bubbleSort(copyarr, atoi(argv[1]));
	end = clock();
	printResults(sortfile, filepath, "Bubble", copyarr, atoi(argv[1]), (double)(end - start));
	
	//selection sort		
		//copying unsorted array
	copyarr = copyArray(array, atoi(argv[1]));
	
		//testing selection sort
	start = clock();
	selectionSort(copyarr, atoi(argv[1]));
	end = clock();
	printResults(sortfile, filepath, "Selection", copyarr, atoi(argv[1]), (double)(end - start));
	
	//insertion sort		
		//copying unsorted array
	copyarr = copyArray(array, atoi(argv[1]));

		//testing insertion sort
	start = clock();
	insertionSort(copyarr, atoi(argv[1]));
	end = clock();
	printResults(sortfile, filepath, "Insertion", copyarr, atoi(argv[1]), (double)(end - start));
	
	//end
	free(array);
	free(copyarr);
	fclose(sortfile);
	return 0;
}
