#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
#define ll long long
#define sf(x) scanf("%lld",&x)
ll dp[105][105];
ll a[105][105];
int main()
{
	ll n,m,i,j;
	sf(n);sf(m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		sf(a[i][j]);
	}
	for(i=1;i<=n;i++)
	{
	dp[i][0]=INF;
	dp[i][m+1]=INF;
    }
	for(i=0;i<=m;i++)
	dp[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[i][j]=a[i][j]+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]);
		}
	}
	ll min1=INF;
	for(i=1;i<=m;i++)
	{
		if(dp[n][i]<min1)
		min1=dp[n][i];
	}
	printf("%lld\n",min1);
}
