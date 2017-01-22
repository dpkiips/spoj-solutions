#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	while(1)
	{
	ll bud,n,i,j;
	cin>>bud>>n;
	if(bud==0&&n==0)
	break;
	ll cost[n+1],fun[n+1];
	ll b[n+1][bud+1];
	for(i=1;i<=n;i++)
	cin>>cost[i]>>fun[i];
    for(i=0;i<=n;i++)
    b[i][0]=0;
    for(i=0;i<=bud;i++)
    b[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=bud;j++)
		{
	        if(cost[i]<=j)
	        b[i][j]=max(fun[i]+b[i-1][j-cost[i]],b[i-1][j]);
	        else
	        b[i][j]=b[i-1][j];
		}
	}
	ll max=b[n][bud];
	for(i=1;i<=n;i++)
	{
		for(j=30;j<=bud;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}
	for(i=bud;i>=1;i--)
	{
		if(b[n][i]<max)
		break;
	}
	cout<<i+1<<" "<<max<<endl;
   }
   return 0;
}
