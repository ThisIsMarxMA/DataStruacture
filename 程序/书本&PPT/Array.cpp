#include <stdarg.h>
#include <bits/stdc++.h>
#define MAX_ARRAY_DIM 8
typedef struct 
{
	int *base;
	int dim;
	int *bounds;
	int *constants;
}Array;

void InitArray(Array &A,int dim,...)
{
	if(dim<1||dim>MAX_ARRAY_DIM)
		printf("ERROR\n");
	A.dim=dim;
	A.bounds=(int *)malloc(sizeof(int)*dim);
	if(!A.bounds)
		printf("ERROR\n");
	int elemtotal=1;
	va_list ap;
	va_start(ap,dim);
	for(int i=0;i<dim;i++)
	{
		A.bounds[i]=va_arg(ap,int);  //存入各维长度
		if(A.bounds[i]<0)
			printf("ERROR\n");
		elemtotal*=A.bounds[i];  //求出总元素个数
	}
	va_end(ap);
	A.base=(int *)malloc(elemtotal*sizeof(int));
	if(!A.base)
		printf("ERROR\n");
	A.constants=(int *)malloc(dim*sizeof(int));
	A.constants[dim-1]=1;  //设单个元素长度L为1
	for(int i=dim-2;i>=0;i--)  //求印象函数的各常数Ci
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];  
}

//销毁数组
void DestoryArray(Array &A)
{
	if(!A.base) 
		printf("ERROR");
	free(A.base);
	A.base=NULL;
	if(!A.bounds)
		printf("ERROR");
	free(A.bounds);
	A.bounds=NULL;
	if(!A.constants)
		printf("ERROR");
	free(A.constants);
	A.constants=NULL;
}

//取得各下标值所对应元素在A中相对地址off
void Locate(Array A,int &off,int dim,...)
{
	va_list ap;
	va_start(ap,dim);
	off=0;
	for(i=0;i<A.dim;i++)
	{
		ind=va_arg(ap,int);
		if(ind<0||ind>=A.bounds[i])
			printf("ERROR\n");
		else
		{
			off+=A.constants[i]*ind;
		}
	}
}

//取出下标所对应位置上的值
void Value(Array A,int &e,...)
{
	va_list ap;
	va_start(ap,e);
	if((Locate(A,off,ap))||(off<0))
		printf("ERROR\n");
	else
	{
		e=*(A.base+off);
	}
}

//给下标所对应位置赋值
void Assign(Array &A,int e,...)
{
	va_list ap;
	va_start(ap,e);
	if((Locate(A,ap,off))||(off<0))
		printf("ERROR\n");
	else
	{
		*(A.base+off)=e;
	}
}

int main(int argc, char const *argv[])
{
	Array A;
	InitArray(A,2,3,4);
	return 0;
}
