#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n1;
ll a[1005][1005];
ll memo[1005][1005];
ll find(ll i,ll j)
{
	if(i>n1)
	return 0;
	if(i==n1)
	return a[i][j];
	if(memo[i][j]!=-1)
	return memo[i][j];
	ll sum=0;
	sum=sum+a[i][j]+max(find(i+1,j),find(i+1,j+1));
	memo[i][j]=sum;
	return sum;
}
int main()
{
	ll t,n,i,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n1=n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			scanf("%lld",&a[i][j]);
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			memo[i][j]=-1;
		}
		ll ans=find(1,1);
		printf("%lld\n",ans);
	}
}
