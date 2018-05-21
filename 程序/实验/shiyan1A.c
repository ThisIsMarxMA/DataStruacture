# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# define LIST_INIT_SIZE 100
# define LISTINCREMENT 10
# define OVERFLOW -2
typedef struct{
	int *elem;
	int length;
	int Listsize;
}SeqList;

void Init(SeqList &Vb){
	if(Vb->elem)
		free(Vb->elem); 
	Vb->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!Vb->elem){exit(OVERFLOW);}
	Vb->length=0;
	Vb->Listsize=LIST_INIT_SIZE;
}


void Output(SeqList Va){
	int *p;
	for(p=Va.elem;p<=Va.elem+Va.length-1;p++){
		printf("%d ", *p);
	}
	printf("\n");
}


int Insert(SeqList Va,int x){
	int *newbase;int k;
	if(Va.length>=Va.Listsize){
	newbase=(int *)realloc(Va.elem,(Va.Listsize+LISTINCREMENT)*sizeof(int));	
	}
	if(!newbase){printf("ERROR");}
	Va.elem=newbase;
	Va.Listsize+=LISTINCREMENT;
	
	if(Va.length==0)
	{
		Va.elem[0]=x;
		return 0;
	}
	else
	{
		for(k=0;k<Va.length;k++){
			if(x<Va.elem[k])
				break;
		}
		int *q=&(Va.elem[k]);
		int *p;
		for(p=&(Va.elem[Va.length-1]);p>=q;--p)
		{
			*(p+1)=*p;
		}
		*q=x;
		++Va.length;
	}
	return 0;
}


int main(){
	int n=10,i,x;
	SeqList Va;
	Init(&Va);
	for(i=0;i<n;i++)
	{
		scanf("%d",Va.elem[i]);
		Va.length++;
	}
	//Output(Va);
	/*
	scanf("%d",&x);
	Insert(Va,x);
	Output(Va);
	*/
	return 0;
} 
