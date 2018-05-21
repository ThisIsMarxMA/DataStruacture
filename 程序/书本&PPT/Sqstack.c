

// 栈的顺序存储表示
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct 
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

// 栈的初始化
SqStack InitStack()
{
	SqStack S;
	S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
		printf("ERROR");
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return S;
}

// 返回栈顶元素，但并不删除
int GetTop(SqStack &S)
{
	int e;
	if(S.top==S.base)
		printf("ERROR");
	e=*(S.top-1);
	return e;
}

// 入栈新元素e
void Push(SqStack &S,int e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(int *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
		if(!S.base)
			printf("ERROR");
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top=e;
	S.top++;
}

// 删除栈顶元素
void Pop(SqStack &S)
{
	int e;
	if(S.top==S.base)
		printf("ERROR");
	e=*--S.Top;
	printf("%d",e);
}


int StackEmpty(SqStack &S)
{
	if(S.top==S.base)
		return 1;
	else
		return 0;
}