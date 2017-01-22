#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,max1,i,j;
	cin>>n;
	ll a[n+1],b[n+1][n+1];
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=0;i<=n;i++)
	b[i][0]=0;
	for(i=0;i<=n;i++)
	b[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<=i&&(n-j+1)<=i)
			{
			    if(j==1)
			    b[i][j]=max(b[i-1][j+1],b[i-1][n])+(i*a[j]);
			    else if(j==n)
			    b[i][j]=max(b[i-1][j-1],b[i-1][1])+(i*a[j]);
			    else
			    b[i][j]=max(b[i-1][j-1],b[i-1][j+1])+(i*a[j]);
			}
			else if(j<=i)
			{
				if(j==1)
			    b[i][j]=b[i-1][n]+(i*a[j]);
			    else
			    b[i][j]=b[i-1][j-1]+(i*a[j]);
			}
			else if((n-j+1)<=i)
			{
				if(j==n)
				b[i][j]=b[i-1][1]+(a[j]*i);
				else
				b[i][j]=b[i-1][j+1]+(a[j]*i);
			}
			else
			b[i][j]=b[i-1][j];
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}
}
