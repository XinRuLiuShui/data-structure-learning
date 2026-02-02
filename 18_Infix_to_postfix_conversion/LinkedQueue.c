#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>



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

int isQueueEmpty(LinkedQueue* queue)
{
	return (queue->front == queue->rear);
}

int GetQueueValue(LinkedQueue* queue, datatype* value)
{
	if (!queue)
	{
		return FALSE;
	}

	if (isQueueEmpty(queue))
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

	if (isQueueEmpty(queue))
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
