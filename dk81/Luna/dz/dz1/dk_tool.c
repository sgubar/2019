#include "dk_tool.h"
	
int words(char myString[100])
{
	int i;
    int no = 0;
    int space = 0;
    int len = dlina(myString);
    for (i = 0; i<=len; i++) 
	{
        if (myString[i] == ' ' && myString[i+1] != ' ' )
        {
            space++;
        }
        if ( space == 1 && i != 0 && no == 0)
        { 
	      	no = 1; 
		    space = 0;
		}
        if ( i == 0 && myString[i] != ' ') 
        {
            no = 1;
        }
    if(len < 1 ) 
    {
     space = 0;
    }
    else if( len != 0 && space == 0 && myString[len-1] != ' ') 
    {
      space = 1;
    }
    else if( myString[len-1] == ' ' || space == 0) 
    {

    }

    else
    {
       space++;
    }}
    return space;
}
int dlina(char str[])
{
int i = 0;
while (str[i]!= '\0')
i++;
 
 return i;  
}
