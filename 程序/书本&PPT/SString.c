
//串的定长顺序存储表示
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1] //0号存储串长度

//串的联接操作
SString Concat(SString S1,SString S2)
{
	SString T="0";
	if(S1[0]+S2[0]<=MAXSTRLEN-1)
	{
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=S1[0]+1;i<=S1[0]+S2[0];i++)
			T[i]=S2[i-S1[0]];
		T[0]=S1[0]+S2[0];
	}
	else if(S1[0]<MAXSTRLEN)
	{
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=S1[0]+1;i<MAXSTRLEN-1;i++)
			T[i]=S2[i-S1[0]];
		T[0]=MAXSTRLEN;
	}
	else
	{
		for(i=1;i<=MAXSTRLEN-1;i++)
			T[i]=S1[i];
		T[0]=MAXSTRLEN-1;
	}
	return T;
}


//求子串
SString SubString(SString S,int pos,int len)
{
	SString Sub="0";
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	for(i=1;i<=len;i++)
	{
		Sub[i]=S[pos+i-1];
	}
	Sub[0]=len;
	return Sub;
}

//求子串位置定位函数
int Index(SString S,SString T,int pos)
{
	i=pos;j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			i=i-j+2;
			j=1;
		}
	}
	if(j>T[0]) return i-T[0];
	else return 0;
}

//KMP算法求子串位置定位函数
int Index_KMP(SString S,SString T,int pos)
{
	i=pos;j=1;
	while(i<=s[0]&&j<=T[0])
	{
		if(j==0||S[i]==T[j])
		{
			++j;++i;
		}
		else
			j=next[j];
	}
	if(j>T[0]) return i-T[0];
	else return 0;
}

//求子串的next值
void get_next(SString T,int next[])
{
	int i=1,j=0;
	next[1]=0;next[0]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			++j;++i;
			next[i]=j;
		}
		else
			j=next[j];
	}
}

//改进的next函数
void get_nextval(SString T,int nexval[])  //????????
{
	i=1;j=0;
	nextval[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			++i;++j;
			if(T[i]!=T[j])
				nextval[i]=j;
			else nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}
}