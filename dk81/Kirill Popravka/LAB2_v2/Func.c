#include "Func.h"

char* randomArray(int In_value) 
{	

	char* Out_array = malloc((In_value + 1)*(sizeof(char)));
	int r_value = 0;
	int cnt = 0;

	while(cnt < In_value)
	{	
		r_value = 65 + rand() % 58;

		if (r_value > 90 && r_value < 97) 
		{ 
			//printf("symbol");
		}else {
			Out_array[cnt] = (char)r_value;
			cnt++;
		};

	}
	
	Out_array[cnt] = '\0';

	return Out_array;

}

char* selectionSort(char* anArray)
{
	int aSize = strlen(anArray);

	for (int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;

	}
	return anArray;
}

void fileWrite(FILE* file, char* anArray) 
{
	if(NULL == file)
	{
		return;
	}

	fprintf(file, "%s", anArray);
}

void freeArray(char *anArray)
{
	if (NULL != anArray)
	{
		free(anArray);
	}
}