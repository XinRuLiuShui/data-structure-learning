#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;	//假定线性表元素类型为int
#define LIST_SIZE 1024
#define TRUE 1
#define FALSE -1
typedef struct {
	ElemType data[LIST_SIZE];
	int last;	//指向最后一个节点的位置，传递数据时方便
}SequenceList;


//初始化
SequenceList* Init();

//求长度
int GetSizeOfSeq(SequenceList* seq);

//取元素
// seq--顺序表指针 pos--元素下标 e--获取元素值
int GetElemFromSeq(SequenceList* seq, int pos, ElemType* e);

//查元素 查找给定值的下标位置，有重复的取第一个找到的下标值
//返回FALSE(-1)表示没有找到
int LocateElemOfSeq(SequenceList* seq, ElemType key);

//插入元素  给指定位置插入值
//顺序表需要未满，插入范围0~n-1
int InsertElemIntoSeq(SequenceList* seq, ElemType value, int pos);

//删除指定位置的元素
DeleteElemFormSeq(SequenceList* seq, int pos);

//遍历顺序表
int ShowSeq(SequenceList* seq);