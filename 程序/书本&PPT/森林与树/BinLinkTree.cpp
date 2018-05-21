typedef char TreeData;

//二叉链表表示二叉树
typedef struct node
{
	TreeData data;
	struct node *leftChild,*rightChild;	
}BinTreeNode;
typedef BinTreeNode *BinTree;

//自下而上依次删除树
void destory(BinTreeNode *current)
{
	if(current!=NULL)
	{
		destory(current->leftChild);
		destory(current->rightChild);
		delete current;
	}
}

//自上而下寻找current的双亲结点
BinTree Parent(BinTreeNode *start,BinTreeNode *current)
{
	if(start==NULL)
		return NULL;
	if(start->leftChild==current||start->rightChild==current)
		return start;
	BinTree p;
	if((p=Parent(start->leftChild,current))!=NULL)
		return p;
	else
		return Parent(start->rightChild,current);
}

//二叉树的遍历，此处为前序遍历
void BinTreeNodeTraverse(BinTreeNode *current,ostream &out)
{
	if(current!=NULL)
	{
		out<<current->data<<' ';
		BinTreeNodeTraverse(current->leftChild,out);
		BinTreeNodeTraverse(current->rightChild,out);
	}
}

//中序遍历二叉树--递归算法实现
void InOrder(BinTreeNode *T)
{
	if(T!=NULL)
	{
		InOrder(T->leftChild);
		cout<<T->data;
		InOrder(T->rightChild);
	}
}

void PreOrder(BinTreeNode *T)
{
	if(T!=NULL)
	{
		cout<<T->data;
		PreOrder(T->leftChild);
		PreOrder(T->rightChild);
	}
}

void PostOrder(BinTreeNode *T)
{
	if(T!=NULL)
	{
		PostOrder(T->leftChild);
		PostOrder(T->rightChild);
		cout<<T->data;
	}
}




