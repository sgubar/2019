    int words(char myString[100])
{
    int nospace = 0;
    int space = 1;
    int length = strlen(myString);
	for (int i = 0; i<=length; i++)
    {

        if (myString[i] == ' ' && myString[i+1] != ' ' )
        {
            space++;
        }
        if ( space == 1 && i != 0 && nospace == 0)
        {
            nospace = 1;
            space = 0;
        }
        if ( i == 0 && myString[i] != ' ') 
        {
            nospace = 1;
        }
    }
     return space;
}
