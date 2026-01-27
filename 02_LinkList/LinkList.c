#include "LinkList.h"

//创建带有头节点的链表
LinkListNode* InitLinkList(void)
{
	LinkListNode* pHead = NULL;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (pHead)
	{
		pHead->pNext = NULL;
	}
	return pHead;
}

//获取链表长度
int GetSizeOfLinkList(LinkListNode* pHead)
{
	if (!pHead)
	{
		return 0;
	}
	int num = 0;
	LinkListNode* node = pHead;
	while (node->pNext)
	{
		node = node->pNext;
		num++;
	}
	return num;
}

//取元素
// seq--链表头指针 pos--编号位置
LinkListNode* GetElemFromLinkList(LinkListNode* pHead, int pos)
{
	//if (!pHead || pos == 0 || pos > GetSizeOfLinkList(pHead))
	//{
	//	return NULL;
	//}
	//LinkListNode* node = pHead;
	//for (int i = 0; i < pos; i++)
	//{
	//	node = node->pNext;
	//}

	if (!pHead || pos == 0)
	{
		return NULL;
	}
	LinkListNode* node = pHead;
	int i = 0;
	while (i < pos && node->pNext)
	{
		node = node->pNext;
		i++;
	}
	if (i == pos)
	{
		return node;
	}
	return NULL;
}

//查元素 查找给定值的下标位置，有重复的取第一个找到的下标值
//返回FALSE(-1)表示没有找到
LinkListNode* LocateElemOfSeq(LinkListNode* pHead, ElemType key)
{
	if (!pHead)
	{
		return NULL;
	}
	LinkListNode* node = pHead->pNext;
	while (node)
	{
		if (node->data == key)
		{
			return node;
		}
		node = node->pNext;
	}
	return NULL;

}

//尾插法创建单链表
//arr:传入的顺序表 length:顺序表的长度
LinkListNode* Create_Rear_LinkList(ElemType arr[], int length)
{
	LinkListNode* pHead, * p, * q;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	//q获得当前链表的头节点
	q = pHead;
	for (int i = 0; i < length; i++)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		q->pNext = p;
		q = p;
	}
	q->pNext = NULL;
	return pHead;
}


//头插法创建单链表
//arr:传入的顺序表 length:顺序表的长度
LinkListNode* Create_Front1_LinkList(ElemType arr[], int length)
{
	LinkListNode* pHead, * p, * q;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	//q获得当前链表的头节点
	q = NULL;
	for (int i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		pHead->pNext = p;
		p->pNext = q;
		q = p;
	}
	return pHead;
}


//头插法2创建单链表	(最后再插入头节点)
//arr:传入的顺序表 length:顺序表的长度
LinkListNode* Create_Front2_LinkList(ElemType arr[], int length)
{
	LinkListNode* pHead, * p, * q;
	//q获得当前链表的头节点
	q = NULL;
	for (int i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = q;
		q = p;
	}
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = q;
	return pHead;
}


//头插法3创建单链表	(只用一个头节点和一个新增节点指针)
//arr:传入的顺序表 length:顺序表的长度
LinkListNode* Create_Front3_LinkList(ElemType arr[], int length)
{
	LinkListNode* pHead, * p;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	//q获得当前链表的头节点
	pHead->pNext = NULL;
	for (int i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	return pHead;
}


//
//int main()
//{
//	LinkListNode* xPtr, * yPtr, * p;
//	xPtr = (LinkListNode*)malloc(sizeof(LinkListNode));
//	if (xPtr)
//	{
//		xPtr->data = 100;
//		xPtr->pNext = NULL;
//	}
//
//	yPtr = (LinkListNode*)malloc(sizeof(LinkListNode));
//	if (yPtr)
//	{
//		yPtr->data = 200;
//		yPtr->pNext = NULL;
//	}
//
//	xPtr->pNext = yPtr;
//}