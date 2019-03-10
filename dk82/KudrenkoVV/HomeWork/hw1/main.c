#include <stdio.h>
#include "tool.h"

int main(int argc, const char * argv[]) {
	
	/* функция getStr подсчитывает сколько раз 
	в строке встречается сочитание символов 'el' */
	
	printf("Counter Str:%d!\n", getStr("Hello world")); 
	printf("Counter Str:%d!\n", getStr("Hello el ello"));
	printf("Counter Str:%d!\n", getStr("Hello El eL ello"));
	return 0;
}
