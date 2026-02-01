#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

typedef int datatype;

typedef struct node {
	datatype data;
	struct node* pNext;
}LinkedQueueNode;

typedef struct {
	LinkedQueueNode* front, * rear;
}LinkedQueue;

int Init(LinkedQueue* queue)
{
	if (!queue)
	{
		return FALSE;
	}

	queue->front = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
	queue->front->pNext = NULL;
	queue->rear = queue->front;
	return TRUE;
}

int isEmpty(LinkedQueue* queue)
{
	return (queue->front == queue->rear);
}

int GetValue(LinkedQueue* queue, datatype* value)
{
	if (!queue)
	{
		return FALSE;
	}

	if (isEmpty(queue))
	{
		return FALSE;
	}

	//front仍然指向第一个节点的前一个位置
	*value = queue->front->pNext->data;
	return TRUE;
}

int enQueue(LinkedQueue* queue, datatype value)
{
	if (!queue)
	{
		return FALSE;
	}
	queue->rear->pNext = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
	queue->rear->pNext->data = value;
	queue->rear->pNext->pNext = NULL;
	queue->rear = queue->rear->pNext;
	return TRUE;
}

LinkedQueueNode* deQueue(LinkedQueue* queue)
{
	if (!queue)
	{
		return NULL;
	}

	if (isEmpty(queue))
	{
		return NULL;
	}

	LinkedQueueNode* q = queue->front->pNext;
	queue->front->pNext = q->pNext;
	if (q->pNext == NULL)
	{
		queue->rear = queue->front;	//队空条件
	}
	return q;
}

int main()
{
	LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	Init(queue);

	enQueue(queue, 1);
	enQueue(queue, 1);
	enQueue(queue, 0);

	int num;
	int pre = 0;
	int value;
	int line = 10;

	//打印10行
	for (int  i = 0; i < line; i++)
	{
		while (1)
		{
			num = deQueue(queue)->data;
			value = pre + num;
			printf("%d ", value);
			enQueue(queue, value);
			if (num == 0)
			{
				printf("\n");
				enQueue(queue, 0);
				pre = 0;
				break;
			}
			else
			{
				pre = num;
			}
		}
	}

	//以下代码也同样可以实现
	/*for (int i = 0; i < 10; i++)
	{
		num = deQueue(queue)->data;
		while (num != 0)
		{
			
			value = pre + num;
			printf("%d ", value);
			enQueue(queue, value);
			pre = num;
			num = deQueue(queue)->data;
		}
		value = pre + num;
		printf("%d ", value);
		printf("\n");
		enQueue(queue, value);
		enQueue(queue, 0);
		pre = 0;
	}*/
}