#include "dk_tools.h"

int srchStr(char* srchName, char* str)
{
	int j = 0;
	int result = 0 ;
	
	for ( int i = 0; str[i] != '\0';  i++) {
		 if (str[i] == srchName[j])
		{
			 j++;
			 if (j  == strlen(srchName))
			 {
				 result = i - j + 2;
				 break;
			 }
		 }
		 else if (str[i] != srchName[j])
		 {
			 j = 0;
		 }

		  else if (srchName[j] == '\0')
		 {
		 
		  break;
		 }
	}
	
	if (result < 1)
	{
		return (-1);
	}
	return result;
	
}
