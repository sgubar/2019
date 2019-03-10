#include "tool.h"

int getStr(const char *inStr)
{
	int counter = 0;
	char find[] = "el";
	
	if (NULL == inStr)
	{
		return ERROR;
	}
	
	for(counter = 0 ; '\0' != *inStr ; inStr++)
	{
		if(*inStr == find[0])
		{
			inStr++;
			if(*inStr == find[1])
			{
				counter++;
			}
			else{
				inStr--;
			}
		}
	}
	
	return counter;
}
