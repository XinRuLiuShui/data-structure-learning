#include "LinkList.h"

void ReserveLinkList(LinkListNode* pHead)
{
	if (!pHead || !pHead->pNext)
	{
		return;
	}
	LinkListNode* point, * back, * next;
	back = pHead;
	point = back->pNext;
	while (point)
	{
		next = point->pNext;
		point->pNext = back;
		back = point;
		point = next;
	}
	//point->pNext = back;
	pHead->pNext->pNext = NULL;	//pHead->pNext一直没有变，一直是原链表的第一个节点
	pHead->pNext = back;
}


int main()
{
	int temp[] = { 1,2,3,4,5 };
	LinkListNode* LinkList = Create_Rear_LinkList(temp, 5);
	ReserveLinkList(LinkList);
	ShowLinkList(LinkList);
}