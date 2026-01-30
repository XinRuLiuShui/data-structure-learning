#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define stackSize 100

//顺序栈实现
typedef struct
{
	int stack[stackSize];
	int top;
}SeqStack;


//栈的初始化
int init(SeqStack* pStack)
{
	if (!pStack)
	{
		return FALSE;
	}
	pStack->top = -1;
	return TRUE;
}

//判断栈是否为空
int isEmpty(SeqStack* pStack)
{
	if (!pStack)
	{
		return FALSE;
	}
	return (pStack->top == -1);
}

//压栈
int Push(SeqStack* pStack, int value)
{
	if (!pStack)
	{
		return FALSE;
	}

	if (pStack->top >= stackSize - 1)
	{
		return FALSE;
	}

	pStack->top++;
	pStack->stack[pStack->top] = value;
}

//出栈
int Pop(SeqStack* pStack)
{
	if (!pStack)
	{
		return FALSE;
	}

	if (pStack->top < 0)
	{
		return FALSE;
	}

	int temp = pStack->stack[pStack->top];
	pStack->top--;
	return temp;
}

//十进制转八进制
void decimal_to_octal(SeqStack* pStack, int value)
{
	if (!pStack)
	{
		return FALSE;
	}

	while (value)
	{
		Push(pStack, value % 8);
		value /= 8;
	}

	while (!isEmpty(pStack))
	{
		printf("%d", Pop(pStack));
	}
}

//
int GetTopValue(SeqStack* pStack, int* value)
{
	if (!pStack)
	{
		return FALSE;
	}

	if (isEmpty(pStack))
	{
		return FALSE;
	}

	*value = pStack->stack[pStack->top];
	return TRUE;
}

int main()
{
	SeqStack stack;
	SeqStack* p = &stack;
	init(p);
	decimal_to_octal(p, 1348);
}