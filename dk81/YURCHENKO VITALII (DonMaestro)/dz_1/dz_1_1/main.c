#include <stdio.h>
#include "header.h"


void output_text_address(char *text)
{
    for(int number = 0; text[number] != '\0'; number++)
        printf("%c = %i = %p\n", text[number], number, &text[number]);
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

    printf("function return = %i\n", get_sym_with_text(text, symbols));

    if(get_sym_with_text(text, symbols) == -1)
        return 0;


    printf("\n");
    for(int number = 0; number < size_sym(symbols); number++)
        printf("%c = %i = %p\n",
                text[get_sym_with_text(text, symbols) + number],
                get_sym_with_text(text, symbols) + number,
                &text[get_sym_with_text(text, symbols) + number]);


    return 0;
}
