#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

void C_mult(int y, int x, int a[y][x], int c);
void matrix_mult(int n, int a[n][n], int b[n][n]);
void print_matrix(int y, int x, int a[y][x]);
void matrix_sum(int y, int x, int a[y][x], int b[y][x], char op);
void transpon_m(int y, int x, int u[y][x]);
void permutation(int n, int a[n]);
void print_massive(int n, int a[n]);
int BIN_decoder(char str[]);
int OCT_decoder(char str[]);
int HEX_decoder(char str[]);
int get_len(char str[]);

#endif
