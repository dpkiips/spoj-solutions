#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
#define INF INT_MAX
int dp[1005][25][82];
int main()
{
	int c,t,a,n,i,j,k;
	sf(c);
	while(c--)
	{
		sf(t);sf(a);
		sf(n);
		int ti[n+1],ai[n+1],w[n+1];
		for(i=1;i<=n;i++)
		{
			sf(ti[i]);sf(ai[i]);sf(w[i]);
		}
	     for(i=0;i<=n;i++)
	     {
	     	for(j=0;j<=21;j++)
	     	{
	     		for(k=0;k<=79;k++)
	     		{
	     			 if(i==0)
	     			 {
                        dp[i][j][k] =100000000;
                        if(j==0 && k==0) 
				        dp[i][j][k] = 0;
				       }
                        else {
                       dp[i][j][k] = min(dp[i-1][j][k], w[i] + dp[i-1][max(0,j-ti[i])][max(0,k-ai[i])]);
                         }
	     		}
	     	}
	     }
		printf("%d\n",dp[n][t][a]);
	}
}
