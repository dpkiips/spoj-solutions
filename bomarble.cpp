#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
ll dp[1005];
int main()
{
	ll i,k=2;
	dp[0]=0;
	dp[1]=5;
	for(i=2;i<=1001;i++)
	{
		dp[i]=dp[i-1]+5+k;
		k=k+3;
	}

	ll n;
	while(1)
	{
		sf(n);
		if(n==0)
		break;
		ll ans=dp[n];
		cout<<ans<<endl;
	}
}
