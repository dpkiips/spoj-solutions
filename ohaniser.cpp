#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
#define mod 1000000007
ll dp[100003];
int main()
{
	ll i;
	dp[1]=1;
	dp[2]=3;
	ll x=2;
	for(i=3;i<=100000;i++)
	{
		dp[i]=((dp[i-1]+dp[i-1])%mod + x)%mod;
		x=(2*x)%mod;
	}
	ll t;
	sf(t);ll y=1;
	while(t--)
	{
		ll n;
	    sf(n);
	    printf("Case %lld: %lld\n",y,dp[n]);
	    y++;
	}
}
