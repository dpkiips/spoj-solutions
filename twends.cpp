#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1001][1001];
int main()
{
	ll n,i,j,k,c=1;
	while(1)
	{
		cin>>n;
		if(n==0)
		break;
		ll sum=0;
		ll a[n+1];
		for(i=1;i<=n;i++)
		{
		cin>>a[i];
		sum=sum+a[i];
	    }
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			dp[i][j]=0;
		}
		for(i=1;i<=n;i++)
		dp[i][i]=i;
		ll sum1=0;
		for(i=n-1;i>=1;i--)
		{
			if(i%2==1)
			{
				ll max=-1;
			for(j=i,k=n;j>=1&&k>=1;j--,k--)
			{
				
				ll mini;
				if(a[dp[j][k-1]]<a[dp[j+1][k]])
				mini=dp[j][k-1];
				else
				mini=dp[j+1][k];
				if(mini==j)
				dp[j][k]=k;
				else if(mini==k)
				dp[j][k]=j;
				else if(k-mini==1)
				dp[j][k]=k;
				else if(mini-j==1)
				dp[j][k]=j;
				if(a[dp[j][k]]>max)
				max=a[dp[j][k]];
			}
			sum1=sum1+max;
		    }
		    else
		    {
		    	for(j=i,k=n;j>=1&&k>=1;j--,k--)
		    	{
		    		if(a[j]>=a[k])
		    		dp[j][k]=j;
		    		else
		    		dp[j][k]=k;
		    	}
		    }
		}
		ll ans=2*sum1-sum;
		printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",c,ans);
		c++;
	}
}
