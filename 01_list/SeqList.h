#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;	//假定线性表元素类型为int
#define LIST_SIZE 1024

typedef struct {
	ElemType data[LIST_SIZE];
	int last;	//指向最后一个节点的位置，传递数据时方便
}SequenceList;

SequenceList* l_Ptr;