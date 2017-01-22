#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll n,i,j,cn=1;
	while(1)
	{
		sf(n);
		if(n==0)
		break;
		ll a[n+1][4];
		ll dp[n+1][4];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			sf(a[i][j]);
		}
	    dp[1][1]=a[1][1];dp[1][2]=a[1][2];dp[1][3]=dp[1][2]+a[1][3];
	    dp[2][1]=a[2][1]+dp[1][2];dp[2][2]=a[2][2]+min(min(dp[2][1],dp[1][2]),dp[1][3]);dp[2][3]=a[2][3]+min(min(dp[2][2],dp[1][2]),dp[1][3]);
	    for(i=3;i<=n;i++)
	    {
	    	for(j=1;j<=3;j++)
	    	{
	    		if(j==1)
	    		dp[i][j]=a[i][j]+min(dp[i-1][1],dp[i-1][2]);
	    		else if(j==2)
	    		dp[i][j]=a[i][j]+min(min(dp[i-1][1],dp[i-1][2]),min(dp[i-1][3],dp[i][1]));
	    		else if(j==3)
	    		dp[i][j]=a[i][j]+min(min(dp[i-1][2],dp[i-1][3]),dp[i][2]);
	    	}
	    }
	    printf("%lld. %lld\n",cn,dp[n][2]);
	    cn++;
	}
}
