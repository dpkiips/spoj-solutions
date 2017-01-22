#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
ll mulmod(ll x,ll y,ll mod)
{
	ll ans=0;
	x=x%mod;
	while(y>0)
	{
		if(y%2==1)
		ans=(ans+x)%mod;
		x=(x+x)%mod;
		y=y/2;
	}
	return ans%mod;
}
ll power(ll x,ll y,ll mod)
{
	ll ans=1;
	x=x%mod;
	while(y>0)
	{
		if(y%2==1)
		ans=(mulmod(ans,x,mod))%mod;
		x=(mulmod(x,x,mod))%mod;
		y=y/2;
	}
	return ans%mod;
}
bool miller(ll n)
{
	ll d=n-1;
	while(d%2==0)
	d=d/2;
	for(int i=0;i<5;i++)
	{
		ll temp=d;ll a=rand()%(n-1) + 1;
		ll x=power(a,temp,n);
		if(x==1||x==-1)
		continue;
		while(temp!=n-1 && x!=n-1)
		{
			x=mulmod(x,x,n);
			temp=temp*2;
		}
		if(x!=n-1)
		return false;
	}
	return true;
}
bool isprime(ll n)
{
	if(n==1||n==4)
	return false;
	if(n==2||n==3)
	return true;
	if(n%2==0)
	return false;
	bool y=miller(n);
	return y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		sf(n);
		if(isprime(n)==true)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
}
