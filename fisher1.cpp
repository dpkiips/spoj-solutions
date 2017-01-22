#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
#define ii pair<int,int>
#define jj pair<ii,int>
#define mp make_pair
#define ll long long
#define sf(x) scanf("%lld",&x)

struct cmp{
	bool operator ()(jj a,jj b){
		if(a.first.first==b.first.first) a.first.second>b.first.second;
		return a.first.first>b.first.first;
	}
};
int main()
{
	while(1)
	{
		ll n,t,i,j;
		sf(n);sf(t);
		if(n==0&&t==0)
		break;
		ll time[n+1][n+1],tol[n+1][n+1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			sf(time[i][j]);
		}
		cout<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			sf(tol[i][j]);
		}
		vector<ll> dis(n+5,INF);
		vector<ll> ti(n+5,INF);
		priority_queue<jj,vector<jj> ,cmp> q1;
		dis[1]=0;
		ti[1]=0;
		q1.push(mp(mp(dis[1],ti[1]),1));
		while(!q1.empty())
		{
			ll u;
			u=q1.top().second;
			q1.pop();
			for(i=1;i<=n;i++)
			{
				if(tol[u][i]>0&&(dis[i]>dis[u]+tol[u][i]))
				{
					dis[i]=dis[u]+tol[u][i];
					ti[i]=ti[u]+time[u][i];
					q1.push(mp(mp(dis[i],ti[i]),i));
				}
				cout<<q1.top().first.second<<endl;
			}
		}
		cout<<dis[n]<<endl;
	}
}
