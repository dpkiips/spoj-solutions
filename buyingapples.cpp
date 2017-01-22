#include<bits/stdc++.h>
using namespace std;
#define INF 10000000000000
#define ll long long
#define sf(x) scanf("%lld",&x)
struct node
{
	ll val;
	ll c;
};
int main()
{
	ll t,k,n;
	sf(t);
	while(t--)
	{
		ll i,j;
		sf(n);sf(k);
		ll cost[k+1];
		for(i=1;i<=k;i++)
		{
			sf(cost[i]);
		}
		ll x,y;
		node a[k+1];
		for(i=0;i<=k;i++)
		{
			a[i].val=INF;
			a[i].c=0;
		}
		a[0].val=0;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(cost[j]!=-1)
				{
			      	x=a[i-j].val;y=a[i-j].c;
				   if(x!=INF&&y+1<=n)
				   {
				   	  if(a[i].val>x+cost[j])
				   	  {
				   	  	a[i].val=x+cost[j];
				   	  	a[i].c=y+1;
				   	  }
				   }
			   }
			}
		}
		if(a[k].val==INF)
		cout<<"-1"<<endl;
		else
	    cout<<a[k].val<<endl;
	}
}
