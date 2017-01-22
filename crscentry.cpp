#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
#define pb push_back
int dp[2001][2001];
int main()
{
	int t;
	sf(t);
	while(t--)
	{
		vector<int> v;
		int x,i,j;
		sf(x);
		while(x!=0)
		{
			v.pb(x);
			sf(x);
		}
	int y;
		int lcs_max=0;
		while(1)
		{
				vector<int> v1;
			sf(y);
			if(y==0)
			break;
			while(y!=0)
			{
				v1.pb(y);
				sf(y);
			}
			int m=v.size();
			int n=v1.size();
		//	cout<<m<<" "<<n<<endl;
			if(n<lcs_max)
			continue;
			for(i=0;i<=m;i++)
			dp[i][0]=0;
			for(i=0;i<=n;i++)
			dp[0][i]=0;
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(v[i-1]==v1[j-1])
					{
					//	cout<<v[i-1]<<" "<<v1[j-1]<<endl;
					dp[i][j]=dp[i-1][j-1]+1;
				     }
					else
					{
						dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					}
				//	cout<<dp[i][j]<<" ";
				}
			//	cout<<endl;
			}
			lcs_max=max(lcs_max,dp[m][n]);
			cout<<lcs_max<<endl;
		}
		cout<<lcs_max<<endl;
	}
}
