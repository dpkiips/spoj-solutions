#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
ll check(ll a[],ll c,ll x,ll n)
{
	ll prev=a[0];
	ll total=1;
	ll i;
	for(i=1;i<n;i++)
	{
		if(a[i]-prev>=x)
		{
			total++;
			if(total==c)
			return 1;
			prev=a[i];
		}
	}
	return 0;
}
ll bin_search(ll a[],ll lo,ll h,ll c,ll n)
{
//	cout<<lo<<" "<<h<<endl;
	while(lo<h)
	{
		ll mid=lo+(h-lo+1)/2;
		//cout<<"here"<<" "<<mid<<endl;
		ll ans=check(a,c,mid,n);
		if(ans==0)
		h=mid-1;
		else
		lo=mid;
	}
	return lo;
}
int main()
{
	ll t,n,c,i;
	sf(t);
	while(t--)
	{
		sf(n);sf(c);
		ll a[n];
		for(i=0;i<n;i++)
		{
			sf(a[i]);
		}
		sort(a,a+n);
		ll fans=bin_search(a,0,a[n-1]-a[0],c,n);
		cout<<fans<<endl;
	}
}
