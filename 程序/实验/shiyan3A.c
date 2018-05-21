#include <stdio.h>
#include <malloc.h>

typedef struct BTNode
{
	int data;
	struct BTNode *lchild,*rchild;
}BTNode,*BTTree;

typedef struct 
{
	BTTree elem[100];
	int top;
}stack;

BTTree creat_bt()     //前序创建树空位补0
{
	BTTree t;int x;
	scanf("%d",&x);
	if(x==0) t=NULL;
	else
	{
		t=(BTTree)malloc(sizeof(BTNode));
		t->data=x;
		t->lchild=creat_bt();
		t->rchild=creat_bt();
	}
	return t;
}

void exchangeLR(BTTree T)   //前序交换子节点
{
	BTTree t;
	if(T->lchild==NULL)
	;
	else
	{
		t=T->lchild;
		T->lchild=T->rchild;
		T->rchild=t;
		exchangeLR(T->lchild);
		exchangeLR(T->rchild);
	}
}

void inorder(BTTree T)  //中序遍历树
{
	if(T)
	{
		inorder(T->lchild);
		printf("%d",T->data);
		inorder(T->rchild);
	}
}

int main(int argc, char const *argv[])
{
	BTTree root;
	printf("\n");
	printf("intput:\n");
	root=creat_bt();
	printf("\nbefore:\n");
	inorder(root);
	exchangeLR(root);
	printf("\nafter:\n");
	inorder(root);
	printf("\n");
	return 0;
}
