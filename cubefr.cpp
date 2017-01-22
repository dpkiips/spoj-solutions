#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
ll a[1000001]={0};
ll b[1000001];
void construct()
{
	ll i,j;
	for(i=2;i<=1000000;i++)
	{
		ll x=i*i*i;
		if(a[i]==0)
		{
			for(j=x;j<=1000000;j=j+x)
			{
				a[j]=1;
			}
		}
	}
	ll k=1;
	for(i=1;i<=1000000;i++)
	{
		if(a[i]==0)
		b[i]=k++;
		else
		b[i]=-1;
	}
}
int main()
{
	construct();
	ll t;
	sf(t);ll c=1;
	while(t--)
	{
		ll n;
		sf(n);
		cout<<"Case "<<c<<": ";
		if(b[n]!=-1)
		cout<<b[n]<<endl;
		else
		cout<<"Not Cube Free"<<endl;
		c++;
	}
}
