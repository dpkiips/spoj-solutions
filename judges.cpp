#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,n,c=1,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ll dp[n+1];
		dp[0]=0;
		dp[1]=a[1];
		for(i=2;i<=n;i++)
		{
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		}
		printf("Case %lld: %lld\n",c,dp[n]);
		c++;
	}
}
