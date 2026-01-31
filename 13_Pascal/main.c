#include <stdio.h>
#include <stdlib.h>

int main()
{
	int front = 1;
	int rear = 4;
	int queue[500] = {0,1,1,0};
	for (int i = 0; i < 50; i++)
	{
		queue[rear] = queue[front - 1] + queue[front];
		printf("%d ", queue[rear]);
		rear++;
		if (queue[front] == 0)
		{
			queue[rear] = 0;
			rear++;
			printf("\n");
		}
		front++;
	}
}