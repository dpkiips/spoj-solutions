#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
long double pi=3.14159265358979323846264338327950;
ll check(ll r[],long double x,ll f,ll n)
{
	ll i;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		long double temp=pi*r[i]*r[i];
		ll ty=temp/x;
		sum=sum+ty;
	}
	if(sum>=f)
	return 1;
	else
	return 0;
}
long double bin_search(ll r[],long double l,long double h,ll f,ll n)
{
	while(h - l>= 1e-6)
	{
		long double mid=(l+h)/2;
	    //cout<<mid<<endl;
		ll ans=check(r,mid,f,n);
		//cout<<ans<<endl;
		if(ans==0)
		{
			h=mid;
		}
		else
		l=mid;
	}
	return l;
}
int main()
{
	ll t,n,f,i;
	sf(t);
	while(t--)
	{
		sf(n);sf(f);
		f++;
		ll r[n];
		ll max1=-1,total=0;
		for(i=0;i<n;i++)
		{
		sf(r[i]);
	    }
	    sort(r,r+n);
	    long double max2=pi*r[n-1]*r[n-1];
	    //cout<<max2<<" "<<total2<<endl;
		long double fans=bin_search(r,0,max2,f,n);
		printf("%.4Lf\n",fans);
	}
}
