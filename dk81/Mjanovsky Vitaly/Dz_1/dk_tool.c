#include "dk_tool.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_matrix(int y, int x, int a[y][x])
{
	int i, j;
	for(j=0; j<y; j++){
	for(i=0; i<x; i++){
	printf("%i ", a[j][i]);
}
	printf("\n");
}}

void print_massive(int n, int a[n])
{
	int i;
	for(i=0; i<n; i++)
	printf("%i ", a[i]);
}

void C_mult(int y, int x, int a[y][x], int c)
{
	int j, i;
	for(j=0; j<y; j++){
	for(i=0; i<x; i++){
	a[j][i] *= c;
}}
	print_matrix(y, x, a);
}

void matrix_mult(int n, int a[n][n], int b[n][n])
{
	int c[n][n], j, i, k;
	for(j=0; j<n; j++){
	for(k=0; k<n; k++){
	c[j][k] = 0;
	for(i=0; i<n; i++){
	c[j][k] += a[j][i] * b[i][k];
	}}}
	print_matrix(n, n, c);
}

matrix_sum(int y, int x, int a[y][x], int b[y][x], char op)
{
	int c[y][x], j, i;
	for(j=0; j<y; j++){
	for(i=0; i<x; i++){
	if(op == '+') c[j][i] = a[j][i]+b[j][i];
	else if(op == '-') c[j][i] = a[j][i]-b[j][i];
}}
	print_matrix(y, x, c);
}

void transpon_m(int y, int x, int u[y][x])
{
	int c[x][y], j, i;
	for(j=0; j<x; j++){
	for(i=0; i<y; i++){
	c[j][i] = u[i][j];
}}
	print_matrix(x, y, c);
}

void permutation(int n, int a[n])
{
	int i, b[n];
	for(i=0; i<n; i++)
	b[i] = a[n-1-i];
	
	print_massive(n, b);
}

int BIN_decoder(char str[])
{
	int num=0, i=0, k=0;
	if(get_len(str)>8 || get_len(str) == 0) 
	{
	num = -255;
	}else{
	while(i<get_len(str))
	{
		k = str[get_len(str)-1-i] - '0';	
		if(k>1 || k<0) 
		{
			num = -255;
			return num; 
		}
		num += k*pow(2, i);
		i++;
	}}
	return num;
}

int OCT_decoder(char str[])
{
	int num=0, i=0, k=0;
	if(strlen(str)>4 || strlen(str) == 0)
	{
	num = -255;
	}else{
	while(i<strlen(str))
	{
		k = str[strlen(str)-1-i] - '0';
		if(k>7 || k<0) 
		{
			num = -255;
			return num; 
		}
		num += k*pow(8, i);
		i++;
	}}
	return num;
}

int HEX_decoder(char str[])
{
	int num = 0, i = 0, k=0;
	char ch;
	if(strlen(str)>4 || strlen(str) == 0)
	{
	num = -255;
	}else{
	while(i<strlen(str))
	{
		ch = str[strlen(str)-1-i];
		if(ch=='A' || ch=='a') k=10;
		else if(ch=='B' || ch=='b') k=11;
		else if(ch=='C' || ch=='c') k=12;
		else if(ch=='D' || ch=='d') k=13;
		else if(ch=='E' || ch=='e') k=14;
		else if(ch=='F' || ch=='f') k=15;
		else k = str[strlen(str)-1-i] - '0';
		
		if(k>15 || k<0) 
		{
			num = -255;
			return num; 
		}
		
		num += k*pow(16, i);
		i++;
	}}
	return num;
}

int get_len(char str[])
{
	int i=0;
	while(str[i] != '\0')
	i++;
	
	return i;
}
