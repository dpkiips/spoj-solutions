#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[10000];int c=1;
	while(1)
	{
		int i,j,k;
		cin>>s;
		if(s[0]=='b')
		break;
		int l=strlen(s);
		int sum[l+1][l+1];
		memset(sum,0,sizeof sum);
		int dp[l+1][l+1];
		memset(dp,0,sizeof dp);
		for(i=1;i<=l;i++)
		{
			for(j=i;j<=l;j++)
			{
				sum[i][j]=sum[i-1][j-1]+s[j-1]-'0';
			//	cout<<sum[i][j]<<" ";
			}
		//	cout<<endl;
		}
		for(i=1;i<=l;i++)
		{
			if(i==1||i==l)
			{
				if(i==1&&sum[2][l]>=s[i-1]-'0')
				dp[i][i]=1;
				else if(i==l&&sum[2][i-1]<=s[i-1]-'0')
				{
					cout<<"here"<<sum[1][i-1]<<endl;
				dp[i][i]=1;
			   }
			}
			else
			{
				if(sum[1][i-1]<=s[i-1]-'0'&&sum[i+1][l]>=s[i-1]-'0')
				dp[i][i]=1;
			}
		}
		for(i=2;i<=l;i++)
		{
			for(j=1;j<=l-i+1;j++)
			{
				for(k=j;k<j+i-1;k++)
				{
					if(sum[j][k]<=sum[k+1][j+i-1])
					{
				//	if(i==3)
				//	cout<<j<<" "<<j+i-1<<endl;
					dp[j][j+i-1]=dp[j][k]+dp[k+1][j+i-1]+1;
				    }
				}
			}
		}
		for(i=1;i<=l;i++)
		{
			for(j=1;j<=l;j++)
			cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		cout<<c<<". "<<dp[1][l]<<endl;
		c++;
	}
}
