#include "Tools.h"

int stringLen(char *inString) {
	
	int len = 0;
	while (inString[len] != '\0') len++;

	return len;
}

int binary2Decimal(char *inString) {
	
	int Decimal = 0;
	
	if (stringLen(inString) > 8) return ERROR;

	for (; '\0' != *inString; inString++) {
		
		Decimal *= 2;
		if (*inString == '1') Decimal++;
		//10 1*2+0
		//100 1*2*2
	}
		
	return Decimal;
}