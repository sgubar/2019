#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "dk_tools.h"

int main(int argc, char* argv[]) {
	char str[100];
	gets(str);
	char srchName[30];
	gets(srchName);
	printf_s("koordinata:%d",srchStr(srchName, str));
	return 0;	
}
