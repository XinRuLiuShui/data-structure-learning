#include <stdio.h>
#include <stdbool.h>
#include<math.h>

#define ROW 5
#define COL 5

//1表示路 0表示墙
char maze[ROW][COL] = {
   {'1','0','1','1','1'},
   {'1','1','1','0','1'},
   {'1','0','0','1','1'},
   {'1','0','0','1','0'},
   {'1','0','0','1','1'} };

typedef struct {
	int x;
	int y;
	int dir;
}node;

int main()
{
	int top = -1;
	node stack[ROW * COL];
	stack[++top] = (node){ 0,0,0 };

	int dir_x[] = { -1,1,0,0 };	//上 下 左 右
	int dir_y[] = { 0,0,-1,1 };

	bool visited[ROW][COL] = { true,false };

	while (top >= 0)
	{
		node* cur = &stack[top];

		//到达终点
		if (cur->x == ROW - 1 && cur->y == COL - 1)
		{
			for (int i = 0; i <= top; i++)
			{
				printf("(%d,%d)\n", stack[i].x, stack[i].y);
			}
			return 0;
		}

		if (cur->dir >= 4)
		{
			visited[cur->x][cur->y] = false;
			top--;
			continue;
		}

		int nx = cur->x + dir_x[cur->dir];
		int ny = cur->y + dir_y[cur->dir];
		cur->dir++;

		if (nx>=0 && nx<ROW && ny>=0 && ny<COL && maze[nx][ny]=='1' && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			stack[++top] = (node){ nx,ny,0 };
		}
	}
}