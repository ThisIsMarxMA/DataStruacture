ADT String
{
	D:{a[i]|a[i]->CharacterSet}
	Ri={<a[i],a[i+1]>}
	StrAssign(&T,chars)
		//创建值为chars的串T   *
	StrCopy(&T,S)
		//拷贝串S至T
	StrEmpty(S)
		//判断串S是否为空
	StrCompare(S,T)
		//比较串S与串T的大小   *
	StrLength(S)
		//返回串S元素个数   *
	ClearString(&S)
		//将S清为空串
	Concat(&T,S1,S2)
		//用T返回由S1和S2联接而成的新串   *
	SubString(&Sub,S,pos,len)
		//用Sub返回串S的第pos个字符起长度为len的子串   *
	Index(S,T,pos)
		//返回主串S中第pos个字符后子串T第一次出现的位置
	Replace(&S,T,V)
		//用V替换主串S中出现的所有与T相等的子串
	StrInsert(&S,pos,T)
		//在串S的第pos个字符前插入T
	StrDelete(&S,pos,len)
		//从串S中删除第pos个字符起长度为len的子串
	DestoryString(&S)
		//销毁串
}ADT String






