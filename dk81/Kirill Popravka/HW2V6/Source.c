#include "circle.h"

void main(void)
{
	Dot O = { 2,3 };
	int radius = 10;


	Circle *cO = createCircle(&O, radius);

	printCircle(cO);
	
	destroyCircle(cO);
	
	system("pause");
}
