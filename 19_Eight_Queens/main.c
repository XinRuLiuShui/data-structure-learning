#include <stdio.h>
#include <stdbool.h>
#include<math.h>

//8行8列 数组下标代表行，下标内容代表列
//从第0行第0列开始
int Queen_Position[8];

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

int main()
{
	int row = 0;
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		Queen_Position[i] = -1;
	}

	while (row >= 0)
	{
		//如果下一行因为这一次摆放位置不对，回溯到这里继续尝试下一列的位置
		Queen_Position[row]++;

		while (Queen_Position[row] < 8 && !isSafe(row,Queen_Position[row]))
		{
			Queen_Position[row]++;
		}

		//没找到合适的列数，回到上一行
		if (Queen_Position[row] >= 8)
		{
			Queen_Position[row] = -1;
			row--;
		}
		else
		{
			if (row == 7)
			{
				count++;
				printf("****************\n");
				printf("solution %d\n", count);

				for (int i = 0; i < 8; i++)
				{
					printf("row:%d col:%d\n", i, Queen_Position[i]);
				}
			}
			else
			{
				row++;
			}
		}
	}
}