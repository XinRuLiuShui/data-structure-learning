#include <stdio.h>
#include <stdlib.h>

#define LIST_MAX_SIZE 50
#define TRUE 1
#define FALSE -1

typedef struct Student
{
	int num;		//系数
	float score;	//指数
}node;

//用顺序表实现
typedef struct
{
	node data[LIST_MAX_SIZE];
	int last;	//表明最后一个节点的位置
}SeqList;

//初始化
SeqList* Init()
{
	SeqList* seq = NULL;
	seq = (SeqList*)malloc(sizeof(SeqList));
	if (seq != NULL)
	{
		seq->last = 0;
	}
	return seq;
}

int InsertStuSeq(SeqList* seq, node stu, int pos)
{
	if (!seq || seq->last >= LIST_MAX_SIZE - 1)
	{
		return FALSE;
	}
	if (pos < 0 || pos >(seq->last + 1))
	{
		return FALSE;
	}

	int i;
	for (i = seq->last; i >= pos; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	seq->data[pos] = stu;
	seq->last++;
	return TRUE;
}

int DelStuSeq(SeqList* seq, int pos)
{
	if (!seq || seq->last <= 0)
	{
		return FALSE;
	}
	if (pos < 0 || pos > seq->last)
	{
		return FALSE;
	}
	for (int i = pos; i < seq->last; i++)
	{
		seq->data[i] = seq->data[i + 1];
	}
	seq->last--;
	return TRUE;
}

//查元素 查找给定值的下标位置，有重复的取第一个找到的下标值
//返回FALSE(-1)表示没有找到
int DisplayStuByNum(SeqList* seq, int num)
{
	if (!seq || seq->last <= 0)
	{
		return FALSE;
	}
	int i;
	for (i = 0; i < seq->last; i++)
	{
		if (seq->data[i].num == num)
		{
			printf("student %d: num is %d , score is %f\r\n", num, seq->data[i].num, seq->data[i].score);
			return TRUE;
		}
	}
	printf("student %d: no found\r\n", num);
	return FALSE;
}

int GetSize(SeqList* seq)
{
	if (!seq)
	{
		return 0;
	}
	return seq->last;
}

void ShowSeqList(SeqList* seq)
{
	if (!seq || seq->last <= 0)
	{
		return;
	}
	printf("-----------------------------\r\n");
	for (int i = 0; i < seq->last; i++)
	{
		printf(" loop%d ,num is %d , score is %f\r\n", i, seq->data[i].num, seq->data[i].score);
	}
	printf("-----------------------------\r\n");
	return;
}



int main()
{
	SeqList* stuList;
	stuList = Init();
	if (stuList)
	{
		node stuNode;
		//初始化成功
		for (int i = 0; i < 10; i++)
		{
			stuNode.num = i;
			stuNode.score = i * i;
			InsertStuSeq(stuList, stuNode, i);
		}
		ShowSeqList(stuList);
	}
	DelStuSeq(stuList, 0);
	ShowSeqList(stuList);
	DisplayStuByNum(stuList, 5);
	DisplayStuByNum(stuList, 15);
}