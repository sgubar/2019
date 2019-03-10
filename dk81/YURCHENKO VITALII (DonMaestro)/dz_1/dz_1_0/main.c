#include <stdio.h>
#include "header.h"
//void get_sym_with_text(char *text, char *symbols);

int main()
{
    char *text = "hello worlds. enter Symbols for Search";
    printf("%s\n", text);

    char *symbols = "i l.";

    for(int i = 0; text[i] != '\0'; i++)
        printf("%c = %p\n", text[i], &text[i]);

    printf("\n\n");

    get_sym_with_text(text, symbols);
    return 0;
}
