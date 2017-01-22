#include<bits/stdc++.h>
using namespace std;
int main()
{
	int len,i;
	char s[5005];
	while(1)
	{
		cin>>s;
		if(s[0]=='0')
		break;
		len=strlen(s);
		int dp[len+1];
		dp[0]=1;
		for(i=1;i<=len;i++)
		dp[i]=0;
		dp[1]=1;
		for(i=2;i<=len;i++)
		{
			int temp;
			temp=s[i-1]-'0';
			if(temp>=1&&temp<=9)
			dp[i]=dp[i]+dp[i-1];
			temp=(s[i-2]-'0')*10+s[i-1]-'0';
			if(temp>=10&&temp<=26)
			dp[i]=dp[i]+dp[i-2];
		}
		cout<<dp[len]<<endl;
	}
}
