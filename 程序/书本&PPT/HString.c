
//串的堆分配存储表示
typedef struct 
{
	char *ch;
	int length;
}HString;


//在S的pos前插入T
void StrInsert(HString *S,int pos,HString T)  //此处pos为从S[0]开始为第一个字符计算
{
	if(pos<1||pos>S->length+1) return ERROR;   
	if(T.length)
	{
		if(!(S->ch=(char *)realloc(S->ch,(S.length+T.length)*sizeof(char))))
			return ERROR;
		for(i=S->length-1;i>=pos-1;--i)      //length同理
			S->ch[i+T.length]=S->ch[i];
		for(i=0;i<=T.length-1;i++)
			S->ch[pos-1+i]=T.ch[i];
		S->length+=T.length;
	}
	return 0;
}

//生成值为chars的串
void StrAssign(HString *T,char *chars)
{
	if(T->ch) free(T->ch);
	for(i=0,c=chars;c;++i,++c);
	if(!i)
	{
		T->ch=NULL;
		T->length=0;
	}
	else
	{
		if(!(T->ch=(char *)malloc(i*sizeof(char))))
			return ERROR;
		for(j=0;j<=i-1;j++)
			T->ch[j]=chars[j];
			T->length=i;
	}
	return 0;
}


//求串长
int StrLength(HString S)
{
	return S.length;
}

//比较串S与串T的值，S>T返回1，S<T返回-1
int StrCompare(HString S,HString T)
{
	for(i=0;i<S.length&&i<T.length;++i)
	{
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	}
	return S.length-T.length;
}

//清空串
void ClearString(HString S)
{
	if(S.ch)
	{
		free(S.ch);
		S.ch=NULL;
	}
	S.length=0;
}

//联接两个子串
HString Concat(HString S1,HString S2)
{
	HString T;
	if(T.ch) free(T.ch);
	if(!(T.ch=(char *)malloc((S1.length+S2.length)*sizeof(char))))
		printf("ERROR");
	for(i=0;i<S1.length;i++)
		T.ch[i]=S1.ch[i];
	for(i=0;i<S2.length;i++)
		T.ch[S1.length+i]=S2.ch[i];
	T.length=S1.length+S2.length;
	return T;
}

//返回串S第pos个字符起长度为len的子串
HString SubString(HString S ,int pos,int len)
{
	HString Sub;
	if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
		printf("ERROR");
	if(Sub.ch) free(Sub.ch);
	if(!len)
	{
		Sub.ch=NULL;
		Sub.length=0;
	}
	else
	{
		Sub.ch=(char *)malloc(len*sizeof(char));
		for(i=0;i<len;i++)
			Sub.ch[i]=S.ch[pos-1+i];
		Sub.length=len;
	}
	return Sub;
}

