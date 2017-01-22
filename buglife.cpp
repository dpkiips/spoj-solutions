#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
int main()
{
	int t,n,in,i,j,sc=1;
	sf(t);
	while(t--)
	{
		sf(n);sf(in);
		vector<int> v[n+1];
		int a,b;
		while(in--)
		{
			sf(a);sf(b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		vector<int> mark(n+1,0);
		int flag=0;
		for(i=1;i<=n;i++)
		{
			if(mark[i]==0)
			{
				stack<int> s;
				s.push(i);
				vector<int> v1(n+1,2);
				v1[i]=1;
				while(!s.empty())
				{
					int u=s.top();
					s.pop();
					mark[u]=1;
					for(j=0;j<v[u].size();j++)
					{
						if(v1[v[u][j]]!=2&&(v1[v[u][j]]==v1[u]))
						{
							flag=1;
							break;
						}
						if(mark[v[u][j]]==0)
						{
							v1[v[u][j]]=!(v1[u]);
							s.push(v[u][j]);
						}
					}
					if(flag==1)
					break;
				}
			}
			if(flag==1)
			break;
		}
		printf("Scenario #%d:\n",sc);
		if(flag==1)
		printf("Suspicious bugs found!\n");
		else
		printf("No suspicious bugs found!\n");
		sc++;
	}
}
