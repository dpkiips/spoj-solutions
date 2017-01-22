#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		break;
		int a[n+1],to_go=1,index=1;
		stack<int> s;
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		if(n==1)
		{
		printf("yes\n");
		continue;
	     }
		while(1)
		{
			if(!s.empty())
			{
				if(a[index]==to_go)
				{
					to_go++;
					index++;
				}
				else if(to_go==s.top())
				{
					s.pop();
					to_go++;
				}
				else
				{
					s.push(a[index]);
					index++;
				}
			}
			else
			{
				if(a[index]==to_go)
				{
					to_go++;
					index++;
				}
				else if(a[index]!=to_go)
				{
					s.push(a[index]);
					index++;
				}
			}
			if(index==n+1)
			break;
		}
		int ch=0;
		while(!s.empty())
		{
			if(s.top()==to_go)
			{
				s.pop();
				to_go++;
			}
			else if(s.top()!=to_go)
			{
				ch=1;
				break;
			}
		}
		if(ch==1)
		printf("no\n");
		else
		printf("yes\n");
	}
	return 0;
}
