#include <stdio.h>
typedef struct LNode{
	int num;
	struct LNode *next;
}LNode,*Linklist; //*Linklist是什么意思

typedef struct{
	Linklist base;
	Linklist top;
}ListStack;

void InitStack(ListStack L){
	L.base=(Linklist)malloc(sizeof(LNode));
	if(!L.base)exit(OVERFLOW);
	L.top=L.base;
	L.base->next=NULL;
	L.top->num=1;
}

void Gettop(ListStack L,int *e){
	if(L.top==L.base) return 1;
	*e=L.top->next->num;
}

void Push(ListStack L,int e){
	newNode=(Linklist)malloc(sizeof(LNode));
	newNode->num=e;
	newNode->next=L.top->next;
	L.top->next=newNode;
	L.top->num++;
}

int Pop(ListStack L,int *e){
	if(L.top==L.base) return ERROR;
	Linklist p=L.top->next;
	*e=p->num;
	L.top->next=p->next;
	free(p);
	return OK;
}

