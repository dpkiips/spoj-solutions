#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
#define pp pair<int,int>
#define mp make_pair
vector<int> v[1000002];
int vis[1000002];
int mark[1000002];
int main()
{
	int t,n,r,m,i;
	sf(t);
	while(t--)
	{
		sf(n);sf(r);sf(m);
		for(i=0;i<=n;i++)
		{
			vis[i]=0;
			mark[i]=0;
		}
		int s,d;
		for(i=1;i<=r;i++)
		{
			sf(s);sf(d);
			v[s].push_back(d);v[d].push_back(s);
		}
		int city[m],k[m],count=0,flag=0;
		for(i=0;i<m;i++)
		{
			sf(city[i]);sf(k[i]);
		}
		for(int j=0;j<m;j++)
		{
			int cit=city[j];int k1=k[j]; 
			queue<pp> q;
			q.push(mp(cit,k1));
			//	memset(mark,0,sizeof mark);
				mark[cit]=1;
			while(!q.empty())
			{
				int x=q.front().first;int y=q.front().second;
			//	cout<<x<<" "<<y<<endl;
				q.pop();
				if(vis[x]==0)
				{
					vis[x]=1;count++;
				}
				else
				{
					flag=1;
					break;
				}
				if(y>0)
				{
					for(i=0;i<v[x].size();i++)
					{
						if(mark[v[x][i]]==0)
						{
						q.push(mp(v[x][i],y-1));
						mark[v[x][i]]=1;
				    	}
					}
			    }
			}
			if(count>=n&&j<m-1)
			flag=1;
			if(flag==1)
			break;
		}
		if(flag==0&&count==n)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		for(i=1;i<=n;i++)
		v[i].clear();
	}
}
