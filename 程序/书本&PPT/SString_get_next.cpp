#include <stdio.h> 
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];//0ºÅ´æ´¢´®³¤¶È

void get_next(SString T,int next[])
{
	int i=1;next[1]=0;int j=0;
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

int main()
{
	int i;
	SString T="6abaabc";
	T[0]=6;
	printf("%d\n",T[0]);
	int next[7];
	get_next(T,next);
	for(i=1;i<7;i++)
		printf("%d ",next[i]);
	return 0;
}
