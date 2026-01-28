


> Written with [StackEdit](https://stackedit.io/).

关键代码
``` c
设pa指向headA链、pb指向headB链
while (pa、pb两个链都没处理完)
{
    if (pa、pb指向当前结点的指数项相同)
    {
        系数相加，当和不为零时在C链中添加新的结点;
        pa、pb指针后移一位;
    }
    else
    {
        以指数小的项的系数添入C链中的新结点;
        指数小的相应链指针后移;
    }
}
p指向未处理完的链
while(p非空)
	{ 顺序处理p链; }
```
