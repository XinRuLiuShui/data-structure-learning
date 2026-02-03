#include <stdio.h>
#include <stdbool.h>
#include<math.h>

//8行8列 数组下标代表行，下标内容代表列
//从第0行第0列开始
int Queen_Position[8];
int count = 0;

bool isSafe(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (col == Queen_Position[i] || abs(row - i) == abs(col - Queen_Position[i]))
		{
			return false;
		}
	}
	return true;
}
void solve(int row)
{
	if (row == 8)
	{
		count++;
		printf("****************\n");
		printf("solution %d\n", count);

		for (int i = 0; i < 8; i++)
		{
			printf("row:%d col:%d\n", i, Queen_Position[i]);
		}
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		if (isSafe(row, i))
		{
			Queen_Position[row] = i;
			solve(row + 1);
		}
	}
}

int main()
{
	int row = 0;
	solve(0);
}