#pragma once

#define TRUE 1
#define FALSE -1

typedef char datatype;

typedef struct node {
	datatype data;
	struct node* pNext;
}LinkedQueueNode;

typedef struct {
	LinkedQueueNode* front, * rear;
}LinkedQueue;

int Init(LinkedQueue* queue);
int isQueueEmpty(LinkedQueue* queue);
int GetQueueValue(LinkedQueue* queue, datatype* value);
int enQueue(LinkedQueue* queue, datatype value);
LinkedQueueNode* deQueue(LinkedQueue* queue);
