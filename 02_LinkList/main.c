#include "LinkList.h"

int main()
{
	int temp[] = { 1,2,3,4,5 };
	Create_Rear_LinkList(temp, 5);
	Create_Front1_LinkList(temp, 5);
	Create_Front2_LinkList(temp, 5);
	LinkListNode* LinkList = Create_Front3_LinkList(temp, 5);

	ShowLinkList(LinkList);
	LinkListNode* nodeToInsert = GetNodeFromLinkList(LinkList, 2);

	InsertAfterIntoLinkList(nodeToInsert, 22);
	ShowLinkList(LinkList);

	InsertBeforeIntoLinkList(LinkList, nodeToInsert, 222);
	ShowLinkList(LinkList);

	DeleteAfterLinkList(nodeToInsert);
	ShowLinkList(LinkList);
	printf("size of the list is %d\r\n", GetSizeOfLinkList(LinkList));

	DeleteSpecifyLinkList(LinkList, 2);
	ShowLinkList(LinkList);

	printf("size of the list is %d\r\n", GetSizeOfLinkList(LinkList));
}