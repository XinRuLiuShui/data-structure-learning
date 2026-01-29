#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

typedef struct node {
	int data;
	struct node* pNext;
}CircularLinkList;


//尾插法创建单链表
//arr:传入的顺序表 length:顺序表的长度
CircularLinkList* Create_CircularLinkList(int arr[], int length)
{
	CircularLinkList* pHead, * p, * q;
	pHead = (CircularLinkList*)malloc(sizeof(CircularLinkList));
	//q获得当前链表的头节点
	q = pHead;
	for (int i = 0; i < length; i++)
	{
		p = (CircularLinkList*)malloc(sizeof(CircularLinkList));
		p->data = arr[i];
		q->pNext = p;
		q = p;
	}
	q->pNext = pHead;
	return q;
}

//遍历
//参数是 指向 循环链表最后一个节点 的指针
void ShowCircularLinkList(CircularLinkList* tailPtr)
{
	CircularLinkList* p = tailPtr->pNext;	//头节点head
	p = p->pNext;	//p移动到第一个节点
	while (p != tailPtr->pNext)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
}

CircularLinkList* MergeCircularLinkList(CircularLinkList* aTailPtr, CircularLinkList* bTailPtr)
{
	// 如果任一链表为空，返回另一个
	if (!aTailPtr) return bTailPtr;
	if (!bTailPtr) return aTailPtr;
	CircularLinkList* aHead = aTailPtr->pNext;
	CircularLinkList* bHead = bTailPtr->pNext;
	aTailPtr->pNext = bHead->pNext;	//a尾->b第一个节点
	bTailPtr->pNext = aHead;	//b尾->a头
	free(bHead);
	return bTailPtr;
}

int main()
{
	int temp[] = { 1,2,3,4,5 };
	CircularLinkList* tailNode = Create_CircularLinkList(temp, 5);	//尾节点指针
	//ShowCircularLinkList(tailNode);

	int temp1[] = { 5,4,3,2,1 };
	CircularLinkList* tailNode1 = Create_CircularLinkList(temp1, 5);	//尾节点指针

	CircularLinkList* result = MergeCircularLinkList(tailNode, tailNode1);
	ShowCircularLinkList(result);
}