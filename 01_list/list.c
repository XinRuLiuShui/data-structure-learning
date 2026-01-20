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

int main()
{
    l_Ptr = Init();
    if (l_Ptr)
    {
        //初始化成功
    }
    else
    {

    }
}