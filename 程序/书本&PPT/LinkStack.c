

// 链式栈的定义
typedef int StackData;  //以后这样写
typedef struct node
{
	StackData data;
	struct node *link;
}StackNode;

typedef struct
{
	StackNode *top;
}LinkStack;


// 初始化栈
void InitStack(LinkStack *S)
{
	S->top=NULL;
}

// 入栈操作
int Push(LinkStack *S,StackData x)
{
	StackNode *p=(StackNode *)malloc(sizeof(StackNode));
	p->data=x;
	p->link=S->top;
	S->top=p;
	return 1;
}

// 判栈空
int StackEmpty(LinkStack *S)
{
	return S->top==NULL;
}

// 出栈并用x返回
int Pop(LinkStack *S,StackData &x)
{
	if(StackEmpty(S))
		return 0;
	StackNode *p=S->top;
	S->top=p->link;
	x=p->data;
	free(p);
	return 1;
}

int GetTop(LinkStack *S,StackData &x)
{
	if(StackEmpty(S))
		return 0;
	x=S->top->data;
	return 1;
}


int MakeEmpty(LinkStack *S)
{
	while(S->top!=NULL)
	{
		StackNode *p=S->top;
		S->top=S->top->link;
		free(p);
	}
}