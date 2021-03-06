#include<ctype.h>
#include<stdio.h>
#define MAX 100
char mid_e[MAX],pos_e[MAX];
int v[26],*p_y;

int evaluate(pos_e,p_y)
char pos_e[];
int *p_y;
{ 
  int stack[MAX],top,x,i;
  char c;
  top=0;i=0;
  c=pos_e[0];
  while (c!='\0')
     {if (islower(c))
	stack[top++]=v[c-'a'];
     else
	switch(c)
	  {case'+': x=stack[--top];
		    stack[top-1]+=x;
		    break;
	   case'-': x=stack[--top];
		    stack[top-1]-=x;
		    break;
	   case'*': x=stack[--top];
		    stack[top-1]*=x;
		    break;
	   case'/': x=stack[--top];
		    stack[top-1]/=x;
		    break;
	   default: return(1);
	  }/*case*/
	c=pos_e[++i];
     }/*while*/
  if (top<1) return(1);
     *p_y=stack[--top];
     return(0);
}

int icp(c)
char c;
{ switch(c)
       {case'*':
	case'/':return(2);
	case'+':
	case'-':return(1);
       }
}
int isp(c)
char c;
{ switch(c)
       {case'*':
	case'/':return(2);
	case'+':
	case'-':return(1);
	case'(':return(0);
	case'#':return(-1);
       }
}
int mid_to_pos(mid_e,pos_e)
	char mid_e[],pos_e[];
{
	char stack[MAX],c;
	int top,i,j;
	top=0;
	stack[top++]='#';
	j=0;i=0;
	c=mid_e[0];
	while (c!='$')
	   { 
	   	if (islower(c))
			pos_e[j++]=c;
	    else
			switch(c)
			{
			   	case'+':
			    case'-':
			    case'*':
			    case'/':
				    while (icp(c)<=isp(stack[top-1]))
				       pos_e[j++]=stack[--top];
				    stack[top++]=c;
				    break;
			    case'(':
				    stack[top++]=c;
				    break;
			    case')':
				    while (stack[top-1]!='(')
				       pos_e[j++]=stack[--top];
				    top--;
				    break;
			    default:
				    return(1);
			}/*case*/

		c=mid_e[++i];
	    }/*while*/
	while (top>1)
		pos_e[j++]=stack[--top];
	pos_e[j]='\0';
	return(0);
}
main()
 {
 	int i,n,s;
 	p_y=(int*)malloc(sizeof(int));
	printf("INPUT OperandType Expression\n");
	scanf("%s",mid_e);
	i=mid_to_pos(mid_e,pos_e);
	if (i==1)  printf("ERROR1");
	else printf("%s\n",pos_e);

	printf("n=");
	scanf("%d",&n);
	for (i=0;i<=n;i++)
	{
		printf("v[%d]=",i);
	 	scanf (" %d",&v[i]);
	}
	i=evaluate(pos_e,p_y);
	if (i==1) printf("ERROR2");
	else
	{
		s=*p_y;
	 	printf("s=%d\n",s);
	}
 }
 
