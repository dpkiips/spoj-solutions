#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
#define INF 1000000
int main()
{
	ll n,e,t,m,i,j,k;
	sf(n);sf(e);sf(t);sf(m);
	ll v[n+1][n+1];
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	v[i][j]=INF;
    }
	ll a,b,wt;
	while(m--)
	{
		sf(a);sf(b);sf(wt);
		if(wt<v[a][b])
		v[a][b]=wt;
	}
	for(i=1;i<=n;i++)
	v[i][i]=0;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(v[i][j]>v[i][k]+v[k][j])
				v[i][j]=v[i][k]+v[k][j];
			}
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
	    if(v[i][e]<=t)
	    ans++;
	}
	printf("%lld\n",ans);
}
