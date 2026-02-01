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

int isEmpety(LinkStack* top)
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
		return 0;
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
	//89+2*6-
	char expression[] = "1562/-3*+";
	int index = 0;

	int operator;
	int num1 = 0;
	int num2 = 0;
	int res = 0;

	LinkStack* operatorStack = NULL;
	LinkStack* numsStack = NULL;

	while (expression[index] != '\0')
	{
		if (isOperator(expression[index]) == TRUE)
		{
			if (!isEmpety(numsStack))
			{
				numsStack = Pop(numsStack, &num1);
				numsStack = Pop(numsStack, &num2);
				numsStack = Push(numsStack, result(expression[index], num1, num2));
			}
		}
		else
		{
			numsStack = Push(numsStack, expression[index] - '0');

		}
		index++;
	}

	while (!isEmpety(numsStack))
	{
		numsStack = Pop(numsStack, &num1);
		printf("%d\n", num1);

	}
	printf("end\n");
	return 0;
}