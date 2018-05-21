void BracketCheck()
{
	InitStack(S);
	while(true)
	{
		scanf("%c",temp);
		if(temp!='('&&temp!='['&&temp!='{')
		{
			switch(temp)
			{
				case ')':
				if(GetTop(S)=='(')
				{
					Pop(S);
					break;
				}
				case ']':
				if(GetTop(S)=='[')
				{
					Pop(S);
					break;
				}
				case '}':
				if(GetTop(S)=='{')
				{
					Pop(S);
					break;
				}
				default:
				printf("ERROR\n");
				return 0;			
			}
		}
		else
		{
			Push(S,temp);
		}
		if(StackEmpty(S))
			return 0;
	}
}