#include <stdio.h>
#include "Figure.h"
#include "Sort.h"
#include <time.h>

int main(int argc, char * argv[]) {
	
	//Знак неравенства в компараторе определяет сортировку по возрастанию или по уменьшению


	clock_t start, stop;

	size_t arrLength = 100;
	TrapeziumArray *trArr = createTrapeziumArray(arrLength);

	
	for (int i = 0; i < arrLength; i++)
	{
		Trapezium *tr = generateTrapezium(1+i);
		addElementToTrapeziumArray(trArr, tr);
	}
	

	simplifiedPrintArray(trArr);

	printf("After sorting:\n");

	start = clock();
	selectionSort(trArr->trapeziumArr, arrLength, sizeof(trArr->trapeziumArr[0]), comparator);
	stop = clock();
	
	printf("Sort required %f seconds, or %i clocks\n", (stop - start) / CLK_TCK, (stop - start));
	simplifiedPrintArray(trArr);


	system("pause");
	return 0;
}