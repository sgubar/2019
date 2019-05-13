//
// Created by World_conspiracy on 04.05.2019.
//
#ifndef LAB2_H_INCLUDED
#define LAB2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int enter_size_array();
void fill_array(char *array, int size);
void input_array_in_file(char *aray, int size, char *name);
void bubble_sort(char *aray, int n);
void insertion_sort(char *aray, int size);
void selection_sort(char *aray, int size);

char* loadFile (char * path , int size);


#endif