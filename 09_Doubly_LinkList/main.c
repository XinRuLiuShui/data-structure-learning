#include <stdio.h>
#include <stdlib.h>

// Define a node for doubly linked list
typedef struct DNode {
    int data;
    struct DNode* pre;  // 前驱指针
    struct DNode* next;  // 后继指针
} DLinkListNode;

DLinkListNode* DeleteDNode(DLinkListNode* ptr)
{
    if (!ptr)
    {
        return NULL;
    }

    DLinkListNode* pre = ptr->pre;
    DLinkListNode* next = ptr->next;

    pre->next = next;
    next->pre = pre;
    
    return ptr;
}

void InsertBeforeDNode(DLinkListNode* ptr, int value)
{
    if (!ptr)
    {
        return;
    }
    DLinkListNode* p = (DLinkListNode*)malloc(sizeof(DLinkListNode));
    p->data = value;
    DLinkListNode* pre = ptr->pre;
    if (pre)
    {
        pre->next = p;
    }
    p->pre = pre;
    p->next = ptr;
    ptr->pre = p;
}

int main()
{
    DLinkListNode a, b, c;
    DLinkListNode* pa, * pb, * pc;
    DLinkListNode* p;
    pa = &a; pb = &b; pc = &c;
    a.data = 1;
    a.pre = NULL;
    a.next = &b;

    //b.data = 2;
    //b.pre = &a;
    //b.next = &c;

    c.data = 3;
    c.pre = &a;
    c.next = NULL;

    InsertBeforeDNode(pc, 2);

    p = pa;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }

    printf("/////////////////\n");
    DeleteDNode(pc->pre);
    p = pc;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->pre;
    }
}