#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
#define ll long long
#define sf(x) scanf("%lld",&x)
#define pb push_back
#define pp pair<ll,ll>
#define mp make_pair
int main()
{
	ll t,n,m,sr,dst,i,j;
	sf(t);
	while(t--)
	{
		sf(n);sf(m);sf(sr);sf(dst);
		vector<pp> alist[n+5];
		ll m1=m;
		ll a,b,time;
		while(m1--)
		{
			sf(a);sf(b);sf(time);
			alist[a].pb(mp(b,time));
			alist[b].pb(mp(a,time));
		}
		vector<ll> dis(n+5,INF);
		bool vis[n+5];
		 memset(vis,false,sizeof(vis));
	     priority_queue<pp> q;
	     dis[sr]=0;
	     q.push(mp(0,sr));
		while(!q.empty())
		{
			ll u,k;
			u=q.top();
			int cur  = u.second ;
			int cos = u.first ;
			q.pop();
		  for(int i =0;i<alis[cur].size() ;i++)
		  {
		  	if(dis[alis[cur][i].first] >cos+alis[cur][i].second)
		  	{
		  		dis[alis[cur][i].first] = cos+alis[cur][i].second ;
		  		q.push(mp(cos+alis[cur][i].second , alis[cur][i].first)) ;
		  	}
		  }
				
		}
		if(dis[dst]==INF)
		cout<<"NONE"<<endl;
		else
		cout<<dis[dst]<<endl;
	}
	return 0;
}

