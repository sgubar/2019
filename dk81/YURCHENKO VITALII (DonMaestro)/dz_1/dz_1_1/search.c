#include "header.h"


int size_sym(char *symbols)
{
    int quantity;
    for(quantity = 0; symbols[quantity] != '\0'; quantity++);
    return quantity;
}




int get_sym_with_text(char *text, char *symbols)
{

    for(int number = 0; text[number] != '\0'; number++)
    {
        for(int number_sym = 0;
            symbols[number_sym] == text[number+number_sym] && number_sym < size_sym(symbols);
            number_sym++)
        {
            if(number_sym == size_sym(symbols) - 1)
                return number;
        }
    }
    return -1;
}
