#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

typedef char datatype;
typedef struct LinkStackNode {
	datatype data;
	struct node* pNext;
}LinkStack;

//允许传入空的栈顶指针
LinkStack* Push(LinkStack* top, datatype value)
{
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

int isEmpty(LinkStack* top)
{
	return (top == NULL);
}

int GetValue(LinkStack* top)
{
	if (!top)
	{
		return -1;
	}

	return top->data;
}


int isOperator(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return TRUE;
	default:
		return FALSE;
	}
}

int isparentheses(char c)
{
	switch (c)
	{
	case '(':
	case ')':
		return TRUE;
	default:
		return FALSE;
	}
}

int Priority(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}

int result(char operator,int num1, int num2)
{
	switch (operator)
	{
	case '+':
		return (num2 + num1);
	case '-':
		return (num2 - num1);
	case '*':
		return (num2 * num1);
	case '/':
		return (num2 / num1);
	default:
		break;
	}
}

int main()
{
	//A+B				 -->	AB+
	//A+B*C				 -->	ABC*+
	//(A+B)*C			 -->	AB+C*
	//A+B*(C-D)-E/F		 -->	ABCD-*+EF/-		实现运算结果为	ABCD-*EF/-+	但也正确
	//((A+B)*C-D)/(E+F)  -->	AB+C*D-EF+/
	
	char expression[] = "A+B*(C-D)-E/F";
	int index = 0;

	char operator;
	char temp = 0;

	LinkStack* operatorStack = NULL;
	LinkStack* sufixStack = NULL;

	LinkedQueue* sufixQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	Init(sufixQueue);

	while (expression[index] != '\0')
	{
		if (isOperator(expression[index]) == TRUE)
		{
			if (!isEmpty(operatorStack))
			{
				if (Priority(expression[index]) <= Priority(GetValue(operatorStack)))
				{
					operatorStack = Pop(operatorStack, &operator);
					enQueue(sufixQueue, operator);
					operatorStack = Push(operatorStack, expression[index]);
				}
				else
				{
					operatorStack = Push(operatorStack, expression[index]);
				}
			}
			else
			{
				operatorStack = Push(operatorStack, expression[index]);
			}
		}
		else if (isparentheses(expression[index]) == TRUE)
		{
			if (expression[index] == '(')
			{
				operatorStack = Push(operatorStack, expression[index]);
			}
			else if (expression[index] == ')')
			{
				if (!isEmpty(operatorStack))
				{
					while (1)
					{
						operatorStack = Pop(operatorStack, &operator);
						if (operator == '(')
						{
							break;
						}
						enQueue(sufixQueue, operator);
					}
				}
			}
		}
		else
		{
			enQueue(sufixQueue, expression[index]);
		}
		index++;
	}

	while (!isEmpty(operatorStack))
	{
		operatorStack = Pop(operatorStack, &operator);
		enQueue(sufixQueue, operator);
	}

	while (!isQueueEmpty(sufixQueue))
	{
		temp = deQueue(sufixQueue)->data;
		printf("%c", temp);
	}
	printf("\nend");

	return 0;
}