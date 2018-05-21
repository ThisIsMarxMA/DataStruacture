ADT_Stack
{
	InitStack(&S)
		// 构造一个空栈S
	DestoryStack(&S)
		// 销毁栈S
	ClearStack(&S)
		// 将S清空
	StackEmpty(S)
		// 判断栈是否为空
	StackLength(S)
		// 返回栈S的元素个数
	GetTop(S,&e)
		// 用e返回栈顶元素
	Push(&S,e)
		// 插入s为新的栈顶元素
	Pop(&S,&e)
		// 删除栈顶元素，用e返回
	StackTraverse(S,visit())
		// 以函数visit()从栈底到栈顶遍历栈S
}