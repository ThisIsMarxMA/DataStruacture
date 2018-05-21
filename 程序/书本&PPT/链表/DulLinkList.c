
//双向链表节点的定义
typedef struct node
{
	int data;
	struct node *next;
	struct node *prior;
}Node,*Linknode;

//双向链表的定义
typedef struct List
{
	Linknode head,tail;
	int len;
}List,*Linklist;


//双向循环链表的初始化
Linklist createList()
{
	Linklist La;
	Linknode L;
	La=(Linklist)malloc(sizeof(List));
	L=(Linknode)malloc(sizeof(Node));
	L->next=L;
	L->prior=L;
	La->head=L;
	La->tail=L;
	La->len=0;
	return La;
}


//双向链表的尾部添加
Linklist ListAppend(Linklist La,int e)
{
	Linknode s;
	if(!(s=(Linknode)malloc(sizeof(Linknode))))
		return 0;
	s->data=e;
	s->next=La->tail->next;
	La->tail->next=s;
	s->prior=La->tail;
	La->head->prior=s;
	La->tail=s;
	La->len+=1;
	return La;
}

//在表的第i个位置前插入元素e
Linklist List_Insert(Linklist La,int i,int e)
{
	Linknode p=La->head;
	if(i<1||i>La->len+1)
		printf("ERROR\n");
	for(j=0;j<i;j++)
		p=p->next;   //确定第i个元素位置p
	Linknode s;
	if(!(s=(Linknode)malloc(sizeof(Linknode))))
		return 0;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return La;
}


//删除链表的第i个元素
Linklist ListDelete(Linklist La,int i)
{
	Linknode p=La->head;
	if(i<1||i>La->len+1)
		printf("ERROR\n");
	for(j=0;j<i;j++)
		p=p->next;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	printf("%d\n",e);
	return La;
}