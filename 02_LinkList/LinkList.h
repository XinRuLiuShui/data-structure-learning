#pragma once
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

typedef struct node {
	int data;
	struct node* pNext;
}LinkListNode;