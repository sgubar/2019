#include "sort.h"

int getSize()
{
	int size;
	do
	{
		printf("Enter array size:\n");
		scanf("%d", &size);
		printf("\n");
	}
	while (size <= 0);
	return size;
}

char getElement()
{
	char element;
	printf("Enter element:\n");
	do
	{
		scanf("%c", &element);
	}
	while (isalpha(element) == 0);
	return element;
}

int chaosfillFile(FILE *file, const char filepath[], int lineSize)
{

	for (int i = 0; i < lineSize; i++)
	{
		int letterType = 0 + rand() % 2;
			
		if (letterType == 0){
			fprintf(file, "%c", ('A' + rand() % ('Z' - 'A' + 1)));
		}
		else{
			fprintf(file, "%c", ('a' + rand() % ('z' - 'a' + 1)));
		}
	}
	fprintf(file, "\n\n");
	return 0;
}

int searchResults(FILE *file, const char filepath[], const char name[], const char element, int idx, double time)
{
	fprintf(file, "Search type: %s\nelement: %c\nIndex: %d\nTime used in seconds: %f\n",
					name, element, idx, (time/CLOCKS_PER_SEC));
		
	return 0;
}


void printSortOnScreen(char *array, int arraysize, double time)
{	
	printf("Array: ");
	for (int i = 0; i < arraysize; i++)
		printf("%c", array[i]);
		
	printf("\n");
	printf("Time: %f\n\n", (time/CLOCKS_PER_SEC));
}

void printSortToFile(FILE *file, char *array, int arraysize, double time)
{	
	fprintf(file, "Array: ");
	for (int i = 0; i < arraysize; i++)
		fprintf(file, "%c", array[i]);
		
	fprintf(file, "\n");
	fprintf(file, "Time: %f\n\n", (time/CLOCKS_PER_SEC));
}


void printSearchOnScreen(char element, int find, double time)
{	
	printf("element: %c\nIndex: %d\nTime: %f\n",
					element, find, (time/CLOCKS_PER_SEC));
}

void printSearchToFile(FILE *file, char element, int find, double time)
{	
	fprintf(file, "element: %c\nIndex: %d\nTime used in seconds: %f\n",
					element, find, (time/CLOCKS_PER_SEC));
}


int linearSearch(char *array, int size, const char element)
{
	for (int i = 0; i < size; i++)
	{
		if (element == array[i])
		{
			return i;
		}
	}
	return -1;
}


void quickSort(char *array, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(array, start, end);
		
		quickSort(array, start, pivot - 1);
		quickSort(array, pivot + 1, end);
	}
}
	
	//function deviding array
int partition(char *array, int start, int end)
{
    char ele = array[end]; 
    
    char *temp_c;
	temp_c = (char*)malloc(sizeof(char)); 
 
    int i = (start - 1);

    for (int j = start; j <= (end - 1); j++)
    {
        if (array[j] <= ele)
        {
            i++;
            
            *temp_c = array[i];
			array[i] = array[j];
			array[j] = *temp_c;
        }
    }
    
    *temp_c = array[i + 1];
	array[i + 1] = array[end];
	array[end] = *temp_c;
	
    return (i + 1);
}

