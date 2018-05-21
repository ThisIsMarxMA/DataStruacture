#include <stdio.h>
#define MAXQSIZE 100
typedef struct{
	int *base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue Q){
	Q.base=(int *)malloc(MAXQSIZE * sizeof(int));
	if(!Q.base) exit(OVERFLOW);
	Q.front=Q.rear=0;
}

Boolean Empty(SqQueue Q){
	if(Q.front==Q.rear)
		return True;
	else
		return False;
}

void EnQueue(SqQueue Q,int e){
	if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return OK;
}

void DeQueue(SqQueue Q,int *e){
	if(Q.front===Q.rear)return ERROR;
	*e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

