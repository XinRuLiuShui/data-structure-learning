#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

typedef int datatype;
typedef struct node {
	datatype data;
	struct node* pNext;
}LinkStack;

//允许传入空的栈顶指针
LinkStack* Push(LinkStack* top, datatype value)
{
	//if (!top)
	//{
	//	return NULL;
	//}

	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = value;
	p->pNext = top;
	top = p;
	return top;
}

LinkStack* Pop(LinkStack* top, datatype* value)
{
	if (!top)
	{
		return NULL;
	}

	LinkStack* p;
	*value = top->data;
	p = top;
	top = top->pNext;
	free(p);
	return top;
}

int main()
{
	LinkStack* pTop = NULL;
	pTop = Push(pTop, 1);
	pTop = Push(pTop, 2);
	datatype value;
	while (pTop)
	{
		pTop = Pop(pTop, &value);
		printf("pop %d\n", value);
	}
}