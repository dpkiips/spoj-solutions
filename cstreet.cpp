#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LONG_LONG_MAX
ll alist[1002][1002];
int main()
{
	ll t,p,v,e,i,j;
	cin>>t;
	while(t--)
	{
		cin>>p>>v>>e;
	    for(i=0;i<=v;i++)
	    {
	    	for(j=0;j<=v;j++)
	    	alist[i][j]=INF;
	    }
		ll a,b,c;
		for(i=1;i<=e;i++)
		{
			cin>>a>>b>>c;
			if(c<alist[a][b])
			alist[a][b]=c;
			if(c<alist[b][a])
			alist[b][a]=c;
		}
		vector<ll> mst(v+1,0);
		vector<ll> dis(v+1,INF);
		ll par[v+1];
		par[1]=-1;dis[1]=0;
		for(i=1;i<=v;i++)
		{
			ll min=INF,mini,u;
			for(j=1;j<=v;j++)
			{
				if(mst[j]==0&&dis[j]<min)
				{
					min=dis[j];
					mini=j;
				}
			}
			u=mini;mst[u]=1;
			for(j=1;j<=v;j++)
			{
				if(alist[u][j]!=0&&mst[j]==0&&dis[j]>alist[u][j])
				{
					dis[j]=alist[u][j];
					par[j]=u;
				}
			}
		}
		ll cost=0;
		for(i=2;i<=v;i++)
		{
			cost=cost+(alist[par[i]][i])*p;
		}
		cout<<cost<<endl;
	}
	return 0;
}
