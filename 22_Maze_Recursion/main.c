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

bool visited[ROW][COL] = { false };

typedef struct {
	int x;
	int y;
}node;

node stack[ROW * COL];
int top = -1;

int dir_x[] = { -1,1,0,0 };	//上 下 左 右
int dir_y[] = { 0,0,-1,1 };

void solve(node pos)
{
	visited[pos.x][pos.y] = true;
	stack[++top] = pos;

	if (pos.x == ROW - 1 && pos.y == COL - 1)
	{
		for (int i = 0; i <= top; i++)
		{
			printf("(%d,%d)\n", stack[i].x, stack[i].y);
		}
		return;
	}
	
	for (int dir = 0;dir < 4; dir++)
	{
		int nx = pos.x + dir_x[dir];
		int ny = pos.y + dir_y[dir];
		if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL && maze[nx][ny] == '1' && !visited[nx][ny])
		{
			solve((node) { nx, ny});
		}
	}

	visited[pos.x][pos.y] = false;
	top--;
}

int main()
{
	node begin = { 0,0 };
	solve(begin);
}