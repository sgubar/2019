#include <stdio.h>
#include "header.h"


void output_text_address(char *text)
{
    for(int number = 0; text[number] != '\0'; number++)
        printf("%c = %p\n", text[number], &text[number]);
    printf("\n");
}


int main()
{
    char *text = "hello worlds. enter Symbols for Search";
    printf("%s\n", text);

    //output_text_address(text);   //   text_address output to screen


    char input[20] = {0};
    scanf("%s", input);
    char *symbols = input;



    if(get_sym_with_text(text, symbols) == -1)
    {
        printf("%i\n", get_sym_with_text(text, symbols));
        return 0;
    }


    for(int number = 0; number < size_sym(symbols); number++)
        printf("%c = %p\n", text[get_sym_with_text(text, symbols) + number],
                &text[get_sym_with_text(text, symbols) + number]);


    return 0;
}
