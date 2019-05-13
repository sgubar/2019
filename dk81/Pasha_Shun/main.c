//
// Created by World_conspiracy on 04.05.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main( ) {

    float begin_time, end_time;
    int size = 0;
    size = enter_size_array();
    char *array = malloc (sizeof (char) * (size+1));
    fill_array (array, size);
    input_array_in_file(array, size, "lab2.txt");

    char * bubble = loadFile("lab2.txt" , size);

    begin_time = clock();
    bubble_sort(bubble, size);
    end_time = clock();

    printf("\n bubble sorting : %f \n", (end_time - begin_time) / CLK_TCK);

    char * insertion = loadFile("lab2.txt" , size);

    begin_time = clock();
    insertion_sort(insertion, size);
    end_time = clock();

    printf("\n insertion sorting : %f \n", (end_time - begin_time) / CLK_TCK);

    char * selection = loadFile("lab2.txt" , size);

    begin_time = clock();
    selection_sort(selection, size);
    end_time = clock();

    printf("\n selection sorting: %f \n", (end_time-begin_time) / CLK_TCK);

    input_array_in_file(bubble, size, "bubble.txt");
    input_array_in_file(insertion, size, "insertion.txt");
    input_array_in_file(selection, size, "selection.txt");


    free(bubble);
    free(insertion);
    free(selection);
    free(array);

    return 0;
}