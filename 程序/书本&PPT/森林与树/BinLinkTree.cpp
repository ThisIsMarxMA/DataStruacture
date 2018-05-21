typedef char TreeData;

//二叉链表表示二叉树
//单个节点定义
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

void CreateBiTree(BinTree &T,char s[],int &i)  //此处i的初值为-1
{
	i++;
	if(s[i]==' '||s[i]=='#')
		T=NULL;
	else
	{
		T=new BinTreeNode;
		T->data=s[i];
		CreateBiTree(T->leftChild,s,i);
		CreateBiTree(T->rightChild,s,i);
	}
}

int Count(BinTreeNode *T)
{
	if(T==NULL)
		return 0;
	else
		return 1+Count(T->leftChild)+Count(T->rightChild);
}

int Leaf_Count(BinTree T)
{
	if(!T)
		return 0;
	else if(!T->leftChild&&!T->rightChild) return 1;
	else return Leaf_Count(T->leftChild)+Leaf_Count(T->rightChild);
}

int Height(BinTreeNode *T)
{
	if(T==NULL)
		return 0;
	else
	{
		int m=Height(T->leftChild);
		int n=Height(T->rightChild);
		return (m>n)?m+1:n+1;
	}
}

BinTree Copy(BinTree T)
{
	if(T==NULL)
		return 0;
	BinTree temp=new BinTreeNode;
	temp->data=T->data;
	temp->leftChild=Copy(T->leftChild);
	temp->rightChild=Copy(T->rightChild);
	return temp;
}

