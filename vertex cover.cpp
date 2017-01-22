#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
vector<ll> v[100005];
ll mark[1000005];
ll get(ll sr)
{
	mark[sr]=2;
	if(v[sr].size()==1)
	return 0;
	ll i;
	ll x=0;
	for(i=0;i<v[sr].size();i++)
	{
		if(mark[v[sr][i]]==0)
		{
			x=x+get(v[sr][i]);
			if(mark[sr]==2&&mark[v[sr][i]]==2)
			{
				x++;
				mark[sr]=1;
			}
		}
	}
	return x;
}
int main()
{
	ll n;
	sf(n);
	ll i;
	for(i=1;i<n;i++)
	{
		ll u1,v1;
		sf(u1);sf(v1);
		v[u1].push_back(v1);
		v[v1].push_back(u1);
	}
	if(n<=2)
	cout<<"1"<<endl;
	else
	{
	memset(mark,0,sizeof mark);
	for(i=1;i<=n;i++)
	{
		if(v[i].size()>1)
		break;
	}
	ll ans=get(i);
	cout<<ans<<endl;
  }
}
