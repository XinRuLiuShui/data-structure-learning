#include "LinkList.h"

int main()
{
	LinkListNode* xPtr, * yPtr, * p;
	xPtr = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (xPtr)
	{
		xPtr->data = 100;
		xPtr->pNext = NULL;
	}

	yPtr = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (yPtr)
	{
		yPtr->data = 200;
		yPtr->pNext = NULL;
	}

	xPtr->pNext = yPtr;
}