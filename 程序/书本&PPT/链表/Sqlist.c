
//线性表的顺序存储结构
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct 
{
	int *elem;
	int length;
	int listsize;
}Sqlist;

//初始化一个新表
Sqlist InitList_Sq()
{
	Sqlist L;
	L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem)
		printf("ERROR\n");
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return L;
}

//在表L的第i个位置之前插入e
void ListInsert_Sq(Sqlist *L,int i,int e)
{
	if(i<1||i>L->length+1)
		printf("ERROR");
	if(L->length>=L->listsize)
	{
		newbase=(int *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase)
			printf("ERROR");
		L->elem=newbase;
		L->listsize+=LISTINCREMENT;
	}
	q=&(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
}

//删除第i个元素并返回其值
int ListDelete_Sq(Sqlist *L,int i)
{
	if(i<1||(i>L->length))
		printf("ERROR");
	int *p=&(L->elem[i-1]);
	int e=*p;
	int *q=L->elem+L->length-1;
	for(++p;p<=q;++p)
		*(p-1)=*p;
	--L->length;
	return e;
}

//合并两表生成新表Lc
void MergeList_Sq(Sqlist *La,Sqlist *Lb,Sqlist *Lc)
{
	int *pa=La->elem;
	int *pb=Lb->elem;
	if(Lc->elem)
		free(Lc->elem);
	int *pc=Lc->elem;
	Lc->length=La->length+Lb->length;
	Lc->listsize=Lc->length;
	pc=(int *)malloc(Lc->listsize*sizeof(int));
	int *Pa_last=La->elem+La->length-1;
	int *Pb_last=Lb->elem+Lb->length-1;
	while((pa<=Pa_last)&&(pb<=Pb_last))
	{
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}
	while(pa<Pa_last)
		*pc++=*pa++;
	while(pb<=Pb_last)
		*pc++=*pb++;
}