# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# define LIST_INIT_SIZE 100
# define LISTINCREMENT 10
# define OK 1;
# define OVERFLOW -2;
typedef struct node
{
	int data;
	struct node *next;
}lnode,*Linklist;

Linklist creat(){
	Linklist p,head;int x;
	head=(Linklist)malloc(sizeof(lnode));
	p=head;
	scanf("%d",&x);
	while(x>0){
		p->next=(Linklist)malloc(sizeof(lnode));
		p=p->next;p->data=x;scanf("%d",&x);
	}
	p->next=NULL;
	return head;
}
void out(Linklist head){
	Linklist p;
	for(p=head->next;p;p=p->next){
		printf("%3d",p->data);
	}
}
int Delete(Linklist L,int mink,int maxk,int *e){
	Linklist p=L;
	while(p->next&&p->next->data<=mink){
		p=p->next;
	}
	Linklist q=p;
	while(q->next&&q->next->data<maxk){
		Linklist m=q->next;
		q->next=m->next;
		*e=m->data;
		free(m);
		e++;
	}
	return OK;
}

int Inverse(Linklist L){
	Linklist p,q,r;
	q=NULL;p=L->next;
	while(p){
		r=p->next;
		p->next=q;
		q=p;p=r;
	}
	L->next=q;
}

Linklist Mergelist(Linklist A,Linklist B){
	Linklist C,p,q,r;
	C=A;p=A->next;q=B->next;C->next=NULL;
	while(p&&q){
		if(p->data==q->data){
			r=q;q=q->next;free(r);
		}
		else{
			if(p->data<q->data){
				r=p;p=p->next;
			}
			else{
				r=q;q=q->next;
			}
			r->next=C->next;C->next=r;
		}
		
	}
	return C;
}
