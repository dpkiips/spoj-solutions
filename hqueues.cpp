#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
ll tree[1000000];
ll a[1000000];
void update(ll node,ll s,ll e,ll p,ll q,ll v)
{
	if(a[node]!=0)
	{
		tree[node]=tree[node]+(e-s+1)*a[node];
		if(s!=e)
		{
			a[2*node]+=a[node];
			a[2*node+1]+=a[node];
		}
		a[node]=0;
	}
	if(s>e||s>q||e<p)
	return;
	if(s>=p&&e<=q)
	{
		tree[node]+=(e-s+1)*v;
		if(s!=e)
		{
			a[2*node]+=v;
			a[2*node+1]+=v;
		}
		return;
	}
	update(2*node,s,(s+e)/2,p,q,v);
	update(2*node+1,(s+e)/2+1,e,p,q,v);
	tree[node]=tree[2*node]+tree[2*node+1];
}
ll sum(ll node,ll s,ll e,ll p,ll q)
{
	if(a[node]!=0)
	{
		tree[node]+=(e-s+1)*a[node];
		if(s!=e)
		{
			a[2*node]+=a[node];
			a[2*node+1]+=a[node];
		}
		a[node]=0;
	}
	if(s>e||s>q||e<p)
	return 0;
	if(s>=p&&e<=q)
	return tree[node];
	return (sum(2*node,s,(s+e)/2,p,q)+sum(2*node+1,(s+e)/2+1,e,p,q));
}
int main()
{
	ll t,n,c,i;
	sf(t);
	while(t--)
	{
		sf(n);sf(c);
		memset(tree,0,sizeof tree);
		memset(a,0,sizeof a);
		ll ty,p,q,v;
		while(c--)
		{
			sf(ty);
			if(ty==0)
			{
				sf(p);sf(q);sf(v);
				update(1,0,n-1,p-1,q-1,v);
			}
			else
			{
				sf(p);sf(q);
				ll ans=sum(1,0,n-1,p-1,q-1);
				printf("%lld\n",ans);
			}
		}
	}
}
