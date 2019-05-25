#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct tagNode {
	int Value;
	void* prev;
	void* next;
}Node;

int structSize(void);