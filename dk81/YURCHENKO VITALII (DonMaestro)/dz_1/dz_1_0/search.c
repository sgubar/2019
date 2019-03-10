#include "header.h"






void get_sym_with_text(char *text, char *symbols)
{
    for(int i = 0; text[i] != '\0'; i++)
    {
        for(int namber_s = 0; symbols[namber_s] != '\0'; namber_s++)
        {
            if(text[i] == symbols[namber_s])
                printf("%c = %p\n", text[i], &text[i]);
        }
    }

}
