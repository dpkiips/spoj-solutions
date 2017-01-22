#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll total[3010]={0};
ll cnt[3010][4100];
int main()
{
	ll a[4],i,j;
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(a,a+4);
	for(i=1;i<=a[0];i++)
	{
		for(j=i;j<=a[1];j++)
		{
			total[j]++;
		}
	}
	for(i=1;i<=3009;i++)
	total[i]+=total[i-1];
	for(i=1;i<=a[0];i++)
	{
		for(j=i;j<=a[1];j++)
		{
			int x=i^j;
			cnt[j][x]++;
		}
	}
	for(i=1;i<=3001;i++)
	{
		for(j=0;j<=4000;j++)
		{
			cnt[i][j]+=cnt[i-1][j];
		}
	}
	ll result=0;
	for(i=1;i<=a[2];i++)
	{
		for(j=i;j<=a[3];j++)
		{
			int y=i^j;
			result=result+total[i]-cnt[i][y];
			
		}
	}
	cout<<result<<endl;
}
