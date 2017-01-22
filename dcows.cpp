#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll n,m,j;
	sf(n);sf(m);
	ll diff=m-n+1;
	ll a[n],i;
	for(i=0;i<n;i++)
	sf(a[i]);
	ll b[m];
	for(i=0;i<m;i++)
	sf(b[i]);
	sort(a,a+n);
	sort(b,b+m);
	ll cost[diff];
	memset(cost,0,sizeof cost);
	ll min1=LONG_LONG_MAX;
	for(i=n-1;i>=0;i--)
	{
		min1=LONG_LONG_MAX;
		for(j=diff-1;j>=0;j--)
		{
			ll x=abs(a[i]-b[i+j])+cost[j];
		//	cout<<x<<endl;
			min1=min(min1,x);
			cost[j]=min1;
		}
	}
	cout<<min1<<endl;
}
