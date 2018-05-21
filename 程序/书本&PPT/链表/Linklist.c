
//线性表的单向链表定义
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*Linklist;

//获取表的第i个位置元素
int GetElem_L(Linklist L,int i)
{
	Linklist p;
	int e,j=1;
	p=L->next;
	while(p&&j<i)
	{
		p=p->next;++j;
	}
	if(!p||j>i)
		printf("ERROR");
	else
		e=p->data;
	return e;
}

//在表的第i个位置前插入元素e
void ListInsert_L(Linklist L,int i,int e)
{
	Linklist p=L;
	int j=0;
	while(p&&j<i-1)  //寻找第i-1个元素
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		printf("ERROR");
	Linklist s=(Linklist)malloc(sizeof(LNode));
	s->data=e;s->next=p->next;
	p->next=s;
}

//删除表第i个位置元素
int ListDelete_L(Linklist L,int i)
{
	Linklist p=L;
	int j=0,e;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)
		printf("ERROR");
	Linklist q=p->next;
	p->next=q->next;
	e=q->data;free(q);
	return e; 
}

//逆序创建n个元素的链表
Linklist RevCreateList_L(int n)
{
	Linklist L=(Linklist)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;--i)
	{
		Linklist p=(Linklist)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
	return L;
}

//合并两个链表
Linklist MergeList_L(Linklist La,Linklist Lb)
{
	Linklist pa=La->next;
	Linklist pb=Lb->next;
	Linklist Lc,pc;
	pc=La;Lc=La;
	while(pa&&pb)
	{
		if(pa->data<=pb->data){
			pc->next=pa;pc=pa;pa=pa->next;
		}
		else{
			pc->next=pb;pc=pb;pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(Lb);
	return Lc;
}


//////////////////////////////////////
///标准实用型链表定义与逆序创建初始化////

typedef struct LNode
{
	int data;
	struct LNode *next;
} *Link,*Position;

typedef struct 
{
	Link head,tail;
	int len;
}Linklist;

Linklist createList(int n)
{
	Linklist La;
	Link L=(Linknode)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;--i)
	{
		Link p=(Link)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
	La->head=L;
	Link p=L;
	while((p->next)!=NULL)
		p=p->next;
	La->tail=p;
	La->len=n;
	return La;
}

/////////////////////////////////////////////