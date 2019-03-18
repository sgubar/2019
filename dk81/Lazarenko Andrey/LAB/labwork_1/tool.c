#include <stdio.h>
#include <string.h>
#include "tool.h"

int  find(char *str, char *toFind)
{
	int key = 0;
	int count = 0;
	int result = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == toFind[key])
		{
			key++;
		}
		if (key == strlen(toFind) && (str[i + 1] == '\0' || str[i + 1] == strlen(str)))
		{
			count = i;
			break;
		}
		else if (key == strlen(toFind) && str[i + 1] != '\0')
			key = 0;
	}
	
	result = count - strlen(toFind);
		
	return result;
}



