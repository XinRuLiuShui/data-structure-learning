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
// pHead--链表头指针 pos--编号位置
LinkListNode* GetNodeFromLinkList(LinkListNode* pHead, int pos)
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

//插入节点  在指定位置之后插入节点
int InsertAfterIntoLinkList(LinkListNode* ptr, ElemType value)
{
	if (!ptr)
	{
		return FALSE;
	}
	LinkListNode* p;
	p = (LinkListNode*)malloc(sizeof(LinkListNode));
	p->data = value;
	p->pNext = ptr->pNext;
	ptr->pNext = p;
	return TRUE;
}


//插入节点  在指定位置之前插入节点
int InsertBeforeIntoLinkList(LinkListNode* pHead, LinkListNode* ptr, ElemType value)
{
	if (!pHead || !ptr)
	{
		return FALSE;
	}
	LinkListNode* pre, * p;
	pre = pHead;
	while (pre && pre->pNext != ptr)
	{
		pre = pre->pNext;
	}
	if (!pre)
	{
		return FALSE;
	}
	p = (LinkListNode*)malloc(sizeof(LinkListNode));
	p->data = value;
	p->pNext = pre->pNext;
	pre->pNext = p;
	return TRUE;
}

//删除节点  在指定位置删除后继节点
LinkListNode* DeleteAfterLinkList(LinkListNode* ptr)
{
	if (!ptr)
	{
		return NULL;
	}
	LinkListNode* backPtr;
	backPtr = ptr->pNext;
	ptr->pNext = backPtr->pNext;
	return backPtr;
}

//删除第i个节点	假定头节点为第0个节点
LinkListNode* DeleteSpecifyLinkList(LinkListNode* pHead, int pos)
{
	if (!pHead || pos <= 0)
	{
		return NULL;
	}
	LinkListNode* pre;
	//获取要删除节点的前一个节点
	pre = GetNodeFromLinkList(pHead, pos - 1);
	if (!pre && !pre->pNext)
	{
		return NULL;
	}
	LinkListNode* ptr;
	ptr = DeleteAfterLinkList(pre);
	return ptr;

	//LinkListNode* q = pHead;
	//LinkListNode* pre = NULL;
	//int i = 0;
	//while (q || i < pos)
	//{
	//	pre = q;
	//	i++;
	//	q = q->pNext;
	//}
	//if (!q)
	//{
	//	return NULL;
	//}
	//pre->pNext = q->pNext;
	//return q;
}

//遍历
void ShowLinkList(LinkListNode* pHead)
{
	if (!pHead)
	{
		return;
	}
	LinkListNode* ptr = pHead->pNext;
	printf("---------------LinkList--------------\r\n");
	while (ptr)
	{
		printf("%d\r\n", ptr->data);
		ptr = ptr->pNext;
	}
	printf("---------------LinkList--------------\r\n");
}


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