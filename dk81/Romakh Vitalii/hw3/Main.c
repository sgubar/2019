#include <stdio.h>
#include "Figure.h"

int main(int argc, char * argv[]) {
	Trapezium *tr1 = generateTrapezium(5);
	Trapezium *tr2 = generateTrapezium(10);
	Trapezium *tr3 = generateTrapezium(15);
	Trapezium *tr4 = generateTrapezium(5);


	TrapeziumArray *trArr = createTrapeziumArray(4);
	addElementToTrapeziumArray(trArr, tr1);
	addElementToTrapeziumArray(trArr, tr2);
	addElementToTrapeziumArray(trArr, tr3);

	FILE *fp;
    fopen_s(&fp, "Trapezium.json", "w+");
	if (trArr->length != 1) {
		fprintf(fp,"[\n");
	}
	for (int i = 0; i < trArr->numberUsed; i++)
	{

		showTrapezium(getElementFromTrapeziumArray(trArr,i));
		printToFileTrapezium(fp,getElementFromTrapeziumArray(trArr, i));
		if (i != trArr->numberUsed - 1) {
			fprintf(fp, ",\n");
		}
		else {
			fprintf(fp, "\n");
		}
	}
	if (trArr->length != 1) {
		fprintf(fp, "]");
	}
	fclose(fp);

	system("pause");
	return 0;
}