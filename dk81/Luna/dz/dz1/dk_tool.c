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
    }
     return space;
}
