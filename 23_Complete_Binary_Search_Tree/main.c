#include <stdio.h>
#include <stdbool.h>

//完全二叉搜索树数组下标从一开始，适应完全二叉树规律
void Create_Bst(int bst[], int arr[], int length)
{
	for (int i = 0; i < 200; i++)
	{
		bst[i] = -1;
	}
	int pos = 1;
	bst[1] = arr[1];
	for (int i = 2; i < length; i++)
	{
		int pos = 1;

		//错误代码
		/*while (arr[i] < bst[pos])
		{
			if (bst[pos * 2] == -1)
			{
				bst[pos * 2] = arr[i];
				break;
			}
			else
			{
				pos = pos * 2;
			}
		}
		
		while (arr[i] > bst[pos])
		{
			if (bst[pos * 2 + 1] == -1 )
			{
				bst[pos * 2 + 1] = arr[i];
				break;
			}
			else
			{
				pos = pos * 2 + 1;
			}
		}*/

		while (true)
		{
			if (arr[i] < bst[pos])
			{
				if (bst[pos * 2] == -1)
				{
					bst[pos * 2] = arr[i];
					break;
				}
				else
				{
					pos = pos * 2;
				}
			}
			else if (arr[i] > bst[pos])
			{
				if (bst[pos * 2 + 1] == -1)
				{
					bst[pos * 2 + 1] = arr[i];
					break;
				}
				else
				{
					pos = pos * 2 + 1;
				}
			}
			else
			{
				//相等时退出
				break;
			}
		}
	}
}

void Show_Bst(int bst[], int length)
{
	for (int i = 1; i < length; i++)
	{
		if (bst[i] != -1)
		{
			printf("bst[%d]:%d\n", i, bst[i]);
		}
	}
}
int main()
{
	int bst[200] = { 0 };
	//int arr[16] = { 17, 97, 59, 20, 23, 83, 44, 48, 72, 52, 86, 65, 1, 8, 78, 55 };
	int arr[16] = {
	10, 5, 15, 3, 7, 12, 18,
	1, 4, 6, 8, 11, 13, 16, 19
	};

	Create_Bst(bst, arr, 16);
	Show_Bst(bst, 200);
}
