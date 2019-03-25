#include <stdio.h>
#include "Figure.h"

int main(int argc, char * argv[]) {
	Trapezium *tr1 = generateTrapezium(5);
	Trapezium *tr2 = generateTrapezium(10);
	Trapezium *tr3 = generateTrapezium(15);

	TrapeziumArray *trArr = createTrapeziumArray(3);
	addElementToTrapeziumArray(trArr, tr1);
	addElementToTrapeziumArray(trArr, tr2);
	addElementToTrapeziumArray(trArr, tr3);

	FILE *fp;
    fopen_s(&fp, "Trapezium.json", "w+");
	for (int i = 0; i < trArr->length; i++)
	{
		showTrapezium(getElementFromTrapeziumArray(trArr,i));
		printToFileTrapezium(fp,getElementFromTrapeziumArray(trArr, i));
		if (i != trArr->length - 1) {
			fprintf(fp, ",\n");
		}
	}
	fclose(fp);

	system("pause");
	return 0;
}