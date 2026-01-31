#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define QUEUE_SIZE 100

typedef int datatype;

//数组形式的循环队列
// front指向队首第一个元素的前一个位置
//rear指向队列最后一个元素
//队满条件为 front+1=rear
//队空条件为 front=rear
//实现时需要取模
typedef struct {
	datatype data[QUEUE_SIZE];
	int front, rear;
}SeqQueue;

int Init(SeqQueue* queue)
{
	if (!queue)
	{
		return FALSE;
	}
	queue->front = QUEUE_SIZE - 1;
	queue->rear = QUEUE_SIZE - 1;
}

int isEmpty(SeqQueue* queue)
{
	if (!queue)
	{
		return FALSE;
	}

	return (queue->front == queue->rear);
}

int isFull(SeqQueue* queue)
{
	if (!queue)
	{
		return FALSE;
	}

	return (((queue->rear + 1) % QUEUE_SIZE) == queue->front);
}

//返回的是数组下标
int GetValue(SeqQueue* queue)
{
	if (!queue)
	{
		return FALSE;
	}

	if (isEmpty(queue))
	{
		return FALSE;
	}
	//return (queue->front + 1) % QUEUE_SIZE;
	return queue->data[(queue->front + 1) % QUEUE_SIZE];
}

int enQueue(SeqQueue* queue, datatype value)
{
	if (!queue)
	{
		return FALSE;
	}

	if (isFull(queue))
	{
		return FALSE;
	}
	queue->rear = (queue->rear + 1) % QUEUE_SIZE;
	queue->data[queue->rear] = value;
	return TRUE;
}

int deQueue(SeqQueue* queue)
{
	if (!queue)
	{
		return FALSE;
	}

	if (isEmpty(queue))
	{
		return FALSE;
	}

	queue->front = (queue->front + 1) % QUEUE_SIZE;
	return queue->data[queue->front];
}

int main()
{
	SeqQueue queue;
	SeqQueue* pQueue = &queue;
	Init(pQueue);

	//enQueue(pQueue, 0);
	enQueue(pQueue, 1);
	enQueue(pQueue, 1);
	enQueue(pQueue, 0);

	int num;
	int pre = 0;
	int value;
	for (int i = 0; i < 50; i++)
	{
		num = deQueue(pQueue);
		value = pre + num;
		printf("%d ", value);
		enQueue(pQueue, value);
		if (num == 0)
		{
			printf("\n");
			enQueue(pQueue, 0);
			pre = 0;
		}
		else
		{
			pre = num;
		}
	}
}