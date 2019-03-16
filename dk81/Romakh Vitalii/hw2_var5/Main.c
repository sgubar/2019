#include <stdio.h>
#include "Figure.h"


int main(int argc, char * argv[]) {
	//I want to print my Trapezium, and currently code is under construction;
	Trapezium* tr = generateTrapezium(20);
	showTrapezium(tr);
	deleteTrapezium(tr);
	system("pause");
	return 0;
}