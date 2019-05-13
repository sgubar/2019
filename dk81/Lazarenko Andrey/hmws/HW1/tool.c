#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tool.h"

int srtLengh(char * str[])
{
	char *mass = str;
	int counter = 0;

	while (mass[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

int  find(char *str, char *toFind)
{
	int len_s = srtLengh(str);
	int len_f = srtLengh(toFind);
	int key = 0;
	int count = 0;
	int result = 0;

	for (int i = 0; i < len_s; i++)
	{
		if (str[i] == toFind[key])
		{
			key++;
			if (key == len_f)
			{
				if (str[i + 1] == ' ' || str[i + 1] == '\0')
				{
					count = i;
					break;
				}
				else if (str[i + 1] != ' ')
				{
					printf("Error\n");
					key = 0;
					break;
				}
			}
		}
		else if (str[i] != toFind[key])
		{
			key = 0;
		}
	}
	result = count + 1 - len_f;

	return result;
}