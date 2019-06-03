#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_h
#define LIST_h


typedef struct tagFloatNode FloatNode;

struct tagFloatNode
{
	float value;
	FloatNode *leftChild;
	FloatNode *rightChild;
};

typedef struct tagTree
{
	FloatNode *root;
	int count;
}Tree;

Tree *createTree();

void destroyTree(Tree *aTree);
void addNode(Tree *aTree, float aValue);
void printTree(FloatNode *aNode);
void destroyNode(FloatNode *aNode);

FloatNode *createNode(float aValue);
FloatNode *destroyTreeNode(FloatNode *treeRoot, float aValue);
FloatNode *getSuccessor(FloatNode *treeRoot);
FloatNode *findNode(Tree *aTree, float aValue);

void printTree(FloatNode *aNode);

#endif

