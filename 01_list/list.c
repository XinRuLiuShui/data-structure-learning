#include "SeqList.h"

//初始化
SequenceList* Init()
{
    SequenceList* seq = NULL;
    seq = (SequenceList*)malloc(sizeof(SequenceList));
    if (seq != NULL)
    {
        seq->last = 0;
    }
    return seq;
}

//求长度
int GetSizeOfSeq(SequenceList* seq)
{
    if (seq)
    {
        return seq->last;
    }
    else
    {
        return 0;
    }
}

//取元素
// seq--顺序表指针 pos--元素下标 e--获取元素值
int GetElemFromSeq(SequenceList* seq, int pos, ElemType* e)
{
    if (!seq || pos < 0 || pos > seq->last || seq->last <= 0)
    {
        return FALSE;
    }
    *e = seq->data[pos];
    return TRUE;
}

//查元素 查找给定值的下标位置，有重复的取第一个找到的下标值
//返回FALSE(-1)表示没有找到
int LocateElemOfSeq(SequenceList* seq, ElemType key)
{
    if (!seq || seq->last <= 0)
    {
        return FALSE;
    }
    int i;
    for ( i = 0; i < seq->last; i++)
    {
        if (seq->data[i] == key)
        {
            return i;
        }
    }
    return FALSE;
}

//插入元素  给指定位置插入值
//顺序表需要未满，插入范围0~n-1
int InsertElemIntoSeq(SequenceList* seq, ElemType value, int pos)
{
    if (!seq || seq->last >= LIST_SIZE - 1)
    {
        return FALSE;
    }
    if (pos < 0 || pos > (seq->last + 1))
    {
        return FALSE;
    }

    int i;
    for (i = seq->last; i >= pos; i--)
    {
        seq->data[i + 1] = seq->data[i];
    }
    seq->data[pos] = value;
    seq->last++;
    return TRUE;
}

//删除指定位置的元素
DeleteElemFormSeq(SequenceList* seq, int pos)
{
    if (!seq || seq->last <= 0)
    {
        return FALSE;
    }
    if (pos < 0 || pos >seq->last)
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

//遍历顺序表
int ShowSeq(SequenceList* seq)
{
    if (!seq || seq->last <= 0)
    {
        return FALSE;
    }
    printf("-----------------------------\r\n");
    for (int i = 0; i < seq->last; i++)
    {
        printf("data[%d] is %d\r\n", i, seq->data[i]);
    }
    printf("-----------------------------\r\n");
    return TRUE;
}

int main()
{
    l_Ptr = Init();
    if (l_Ptr)
    {
        //初始化成功
        for (int i = 0; i < 10; i++)
        {
            InsertElemIntoSeq(l_Ptr, i, i);
        }
        
        ShowSeq(l_Ptr);
        InsertElemIntoSeq(l_Ptr, 25, 0);
        ShowSeq(l_Ptr);
        DeleteElemFormSeq(l_Ptr, 5);
        ShowSeq(l_Ptr);
        printf("25 at %d\r\n", LocateElemOfSeq(l_Ptr, 25));
        printf("255 at %d\r\n", LocateElemOfSeq(l_Ptr, 255));
        printf("size of the list is %d\r\n", GetSizeOfSeq(l_Ptr));
    }
    else
    {

    }
}