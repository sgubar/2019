#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define max_line 20
#define max_col 12


struct surface_game
{
    int surface[max_line][max_col];
}Surface;



void clrscr();
void out_surface();

int rules_game();

#endif // HEADER_H
