#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
int main()
{
	int t,n,i,j,k;
	sf(t);
	while(t--)
	{
		sf(n);
		int a[n+1][n+1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			sf(a[i][j]);
		}
		int flag[n+1][n+1];
		memset(flag,0,sizeof flag);
	    set<int> v[n+1];
	    set<int> :: iterator it;
	    if(n==2)
	    cout<<"1"<<" "<<"2"<<endl;
	    else
	    {
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(i==j)
					flag[i][j]=1;
					else if(k!=i&&k!=j&&a[i][j]==a[i][k]+a[j][k])
					flag[i][j]=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(flag[i][j]==0)
				{
					cout<<i<<" "<<j<<endl;
					flag[j][i]=1;
				}
			}
		}
	}
		cout<<endl;
	}
}
