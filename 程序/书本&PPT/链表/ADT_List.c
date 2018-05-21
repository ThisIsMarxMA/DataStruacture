ADT List
{
	InitList(&L)
		//构造一个空表L
	DestoryList(&L)
		//销毁表
	ClearList(&L)
		//将L置为空表
	ListEmpty(L)
		//判表是否为空，是返回True
	ListLength(L)
		//返回表L中元素个数
	GetElem(L,i,&e)
		//返回表L第i个元素的值
	LocateElem(L,e,compare())
		//返回表中第一个与e满足关系compare()的数据位序
	PriorElem(L,cur_e,&pre_e)
		//返回表中元素的前驱
	NextElem(L,cur_e,&next_e)
		//返回表中元素的后继
	ListInsert(&L,i,e)
		//在表中的第i个元素前插入e
	ListDelete(&L,i,&e)
		//删除表的第i个元素，用e返回其值
	ListTraverse(L,visit())
		//以方法visit遍历表L
}//ADT List