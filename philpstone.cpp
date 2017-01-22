#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,h,w,i,j;
	cin>>t;
	while(t--)
	{
		cin>>h>>w;
		long long int a[h+1][w+1],b[h+1][w+1];
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			cin>>a[i][j];
		}
		for(i=0;i<=h;i++)
		b[i][0]=0;
		for(i=0;i<=w;i++)
		b[0][i]=0;
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				long long int temp,temp1,max1;
				if(j<w)
				temp=b[i-1][j+1];
				else
				temp=-1;
				temp1=max(b[i-1][j-1],b[i-1][j]);
				if(temp>temp1)
				max1=temp;
				else
				max1=temp1;
				b[i][j]=max1+a[i][j];
			}
		}
		long long int ans=-1;
		for(i=1;i<=w;i++)
		{
			if(b[h][i]>ans)
			ans=b[h][i];
		}
		cout<<ans<<endl;
	}
}
