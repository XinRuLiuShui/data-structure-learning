#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;	//假定链表元素类型为int

#define TRUE 1
#define FALSE -1

typedef struct node {
	ElemType data;
	struct node* pNext;
}LinkListNode;

LinkListNode* Create_Rear_LinkList(ElemType arr[], int length);
LinkListNode* Create_Front1_LinkList(ElemType arr[], int length);
LinkListNode* Create_Front2_LinkList(ElemType arr[], int length);
LinkListNode* Create_Front3_LinkList(ElemType arr[], int length);