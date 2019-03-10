#include <stdio.h>	
#include "Tools.h"

int main() {
	char binary[] = "11001010";

	printf("%s = %i\n", binary, binary2Decimal(binary));

	system("pause");
}

