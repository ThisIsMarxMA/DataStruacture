
// 将十进制数N转换为d进制数
void conversion(int N,int d)
{
	Sqstack S=Initstack();
	while(N)
	{
		Push(S,N%d);
		N=N/d;
	}
	while(!StackEmpty(S))
	{
		Pop(S);
	}
}