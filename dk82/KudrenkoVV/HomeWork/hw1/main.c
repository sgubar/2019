#include <stdio.h>
#include "tool.h"

int main(int argc, const char * argv[]) {
	
	/* ôóíêöèÿ getStr ïîäñ÷èòûâàåò ñêîëüêî ðàç */
	
	printf("Counter Str:%d!\n", getStr("Hello world")); 
	printf("Counter Str:%d!\n", getStr("Hello el ello"));
	printf("Counter Str:%d!\n", getStr("Hello El eL ello"));
	return 0;
}
