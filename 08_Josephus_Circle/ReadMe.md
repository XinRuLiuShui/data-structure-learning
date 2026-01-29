


> Written with [StackEdit](https://stackedit.io/).

- 关键代码
``` c
for (int i = 0; i < key - 1; i++)
		{
			pre = pre->pNext;
		}
		cur = pre->pNext;
		next = cur->pNext;

		// 删除cur结点
		pre->pNext = next;
		printf("删除节点%d \n", cur->data);
		free(cur);
```
这里是先找到要删除的节点的前一个节点，然后再获得要删除节点以及下一个节点，这样才能完成对删除节点的内存释放。

---

- 错误代码
``` c
//for (int i = 1; i <= key; i++)
//{
//	pre = cur;
//	cur = cur->pNext;
//	next = cur->pNext;
//}
```
这段代码是直接找到要删除的那一个节点，如果不进行内存释放，是可以找到要删除的节点的。但是这样子不利于后面对于要删除节点的内存释放，因为pre指针以及next指针都是基于当前节点的，后面要将当前节点的内存释放，就会造成循环中的内存出错。
