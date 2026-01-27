#include "SeqList.h"

SequenceList* GlobalSeqlist;

void ReserveSeqList(SequenceList* SeqList)
{
    if (!SeqList || SeqList->last == 0 || SeqList->last == 1)
    {
        return;
    }
    ElemType temp;
    int count;
    count = SeqList->last / 2;
    for (int i = 0; i < count; i++)
    {
        temp = SeqList->data[i];
        SeqList->data[i] = SeqList->data[SeqList->last - 1 - i];
        SeqList->data[SeqList->last - 1 - i] = temp;
    }
}

int main()
{
	GlobalSeqlist = Init();
    for (int i = 0; i < 5; i++)
    {
        InsertElemIntoSeq(GlobalSeqlist, i, i);
    }
    ShowSeq(GlobalSeqlist);
    ReserveSeqList(GlobalSeqlist);
    ShowSeq(GlobalSeqlist);
}