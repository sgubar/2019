#ifndef FIGURES_H
#define FIGURES_H

#include <stdio.h>


struct figure_coordinates
{
    int point_col;
    int point_line;
    int point_col_e;
    int point_line_e;

}Figu_coord;



void add_figu();

int wheeling_figu();

int bias_figu_left();
int bias_figu_rite();

int fall_figu_surf();

void save_changes();



#endif // Figu_coordS_H
