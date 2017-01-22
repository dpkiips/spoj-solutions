#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,k,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>k>>m;
		ll wt[m+1],val[m+1];
		ll a[m+1][k+1];
		for(i=1;i<=m;i++)
		{
			cin>>wt[i]>>val[i];
		}
		for(i=0;i<=m;i++)
		a[i][0]=0;
		for(i=0;i<=k;i++)
		a[0][i]=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(wt[i]<=j)
				a[i][j]=max(val[i]+a[i-1][j-wt[i]],a[i-1][j]);
				else
				a[i][j]=a[i-1][j];
			}
		}
		cout<<"Hey stupid robber, you can get "<<a[m][k]<<"."<<endl;
	}
}
