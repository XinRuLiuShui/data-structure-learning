#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* pNext;
}JoeLinkListNode;


//尾插法创建单链表
//arr:传入的顺序表 length:顺序表的长度
//没有头节点，第一个节点便是有数据的节点
JoeLinkListNode* CreateLinkList(int arr[], int length)
{
	JoeLinkListNode* pHead, * p, * q;
	pHead = (JoeLinkListNode*)malloc(sizeof(JoeLinkListNode));
	pHead->data = arr[0];
	//q获得当前链表的头节点
	q = pHead;
	for (int i = 1; i < length; i++)
	{
		p = (JoeLinkListNode*)malloc(sizeof(JoeLinkListNode));
		p->data = arr[i];
		q->pNext = p;
		q = p;
	}
	q->pNext = pHead;
	return q;
}

int main()
{
	int temp[30];
	for (int i = 0; i < 30; i++)
	{
		temp[i] = i;
	}
	JoeLinkListNode* HeadNode = CreateLinkList(temp, 30);
	JoeLinkListNode* pre, * next;
	JoeLinkListNode* cur = HeadNode;
	int start = 1;	//从第一个人开始
	int sum = 30;	//开始时的总人数
	int survivors = 15;	//最后剩余的人数
	int key = 9;	//逢9退出

	pre = HeadNode;
	next = NULL;
	while (sum > survivors)
	{
		//错误代码
		//for (int i = 1; i <= key; i++)
		//{
		//	pre = cur;
		//	cur = cur->pNext;
		//	next = cur->pNext;
		//}
		
		for (int i = 0; i < key - 1; i++)
		{
			pre = pre->pNext;
		}
		cur = pre->pNext;
		next = cur->pNext;

		// 删除cur结点
		pre->pNext = next;
		printf("删除节点%d \n", cur->data);
		free(cur);
		sum--;
	}
}