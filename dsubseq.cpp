#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define sf(s) scanf("%s",s)
int main()
{
	int t,i;
	scanf("%d",&t);
	char s[1000000];
	while(t--)
	{
		sf(s);
		int len=strlen(s);
		ll dp[len+1];
		int count[27]={0};
		dp[0]=0;
		for(i=1;i<=len;i++)
		{
		//	cout<<count[s[i]-'A']<<endl;
		     int x=s[i-1]-'A';
			dp[i]=dp[i-1]+dp[i-1]+1-count[x];
			if(dp[i]<0)
			dp[i]=dp[i]+mod;
			dp[i]=dp[i]%mod;
			//cout<<dp[i]<<" "<<dp[i-1]<<" "<<count[x]<<endl;
			count[x]=count[x]+(dp[i]-dp[i-1]);
			if(count[x]<0)
			count[x]=count[x]+mod;
			count[x]=count[x]%mod;
		}
		cout<<dp[len]+1<<endl;
	}
}
