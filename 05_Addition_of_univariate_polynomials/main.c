#include <stdio.h>
#include <stdlib.h>

typedef struct Polynode
{
	int coef;	//系数
	int exp;	//指数
	struct Polynode* pNext;
}LinkPolyNode;


LinkPolyNode* attach(int coef, int exp, LinkPolyNode* pc)
{
	if (!pc)
	{
		return NULL;
	}
	LinkPolyNode* p;
	p = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
	p->coef = coef;
	p->exp = exp;
	p->pNext = NULL;	//必须要将pNext指针置空
	pc->pNext = p;
	return p;
}

//假定存储结构按照幂指数顺序
//将a和b相加，结果放入c中
//函数的参数是a和b的首地址
//函数返回的是c的首地址
LinkPolyNode* MergePoly(LinkPolyNode* headA, LinkPolyNode* headB)
{
	LinkPolyNode* headC;
	LinkPolyNode* pa, * pb, * pc, * p;

	pa = headA->pNext;
	pb = headB->pNext;
	headC = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
	pc = headC;
	int x = 0;

	while (pa && pb)
	{
		if (pa->exp == pb->exp)
		{
			x = pa->coef + pb->coef;
			if (x != 0)
			{
				pc = attach(x, pa->exp, pc);	//关键点，这里即增加了新节点，同时将p指针移向新节点
			}
			pa = pa->pNext;
			pb = pb->pNext;
			continue;
		}
		else
		{
			//关键点，这里的代码保证了c链表指数是从小到大的
			if (pa->exp < pb->exp)
			{
				p = pa;
				pa = pa->pNext;
			}
			else
			{
				p = pb;
				pb = pb->pNext;
			}
			pc = attach(p->coef, p->exp, pc);
		}
	}

	p = pa;
	if (p == NULL)
	{
		p = pb;
	}

	while (p)
	{
		pc = attach(p->coef, p->exp, pc);
		p = p->pNext;
	}
	return headC;
}

void ShowList(LinkPolyNode* pHead)
{
	if (!pHead)
	{
		return;
	}
	LinkPolyNode* p;
	p = pHead->pNext;
	printf("***********************\r\n");
	while (p)
	{
		//if (p->exp > 0)
		//{
		//	printf("+");
		//}

		if (p->exp == 0)
		{
			printf("%d ", p->coef);
		}
		else if (p->exp == 1)
		{
			printf("%dx ", p->coef);
		}
		else
		{
			printf("%dx^(%d) ", p->coef, p->exp);
		}
		p = p->pNext;
	}
	printf("\r\n***********************\r\n");
}

int main()
{
	//PolyA:1+2x+3x^2
	//PolyB:3x+x^4

	LinkPolyNode HeadA, A1, A2, A3;
	LinkPolyNode HeadB, B1, B2;

	HeadA.pNext = &A1;
	A1.coef = 1;
	A1.exp = 0;
	A1.pNext = &A2;
	A2.coef = 2;
	A2.exp = 1;
	A2.pNext = &A3;
	A3.coef = 3;
	A3.exp = 2;
	A3.pNext = NULL;

	HeadB.pNext = &B1;
	B1.coef = 3;
	B1.exp = 1;
	B1.pNext = &B2;

	B2.coef = 1;
	B2.exp = 4;
	B2.pNext = NULL;

	ShowList(&HeadA);
	ShowList(&HeadB);

	LinkPolyNode* HeadC;
	HeadC = MergePoly(&HeadA, &HeadB);
	ShowList(HeadC);
}