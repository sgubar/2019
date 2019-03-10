#include "header.h"


int size_sym(char *symbols)
{
    int quantity;
    for(quantity = 0; symbols[quantity] != '\0'; quantity++);
    return quantity;
}


int search_sym(int i, char *text, char *symbols);

int get_sym_with_text(char *text, char *symbols)
{


    int all_found_sym[endall];
    int number_found_sym = 0;
    for(int i = 0; text[i] != '\0';)
    {
        if(search_sym(i, text, symbols) == -1 && i == 0)
            return -1;
        if(search_sym(i, text, symbols) == -1 && i != 0)
            break;
        else
        {
            all_found_sym[number_found_sym] = search_sym(i, text, symbols);
            number_found_sym++;
            i = search_sym(i, text, symbols) + 1;
        }
    }


    return number_found_sym;
}


int search_sym(int i, char *text, char *symbols)
{
    for(int number = i; text[number] != '\0'; number++)
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



