#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 10000007
int main()
{
	ll t,n;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,h,m,s,tl;
		scanf("%lld",&n);
		ll a[n],i=0,n1=n;
		while(n1--)
		{
			scanf("%lld%lld%lld",&h,&m,&s);
			a[i++]=((60*h)+m)*60+s;
		}
		scanf("%lld",&tl);
		sort(a,a+n);
		ll mark=a[0],count[86401]={1},k=0;
		for(i=1;i<n;i++)
		{
			if((a[i]-mark+1)<=tl)
			count[k]++;
			else
			{
				k++;
				count[k]++;
				mark=a[i];
			}
		}
		ll min=LONG_LONG_MAX;
		for(i=0;i<=k;i++)
		{
			if(count[i]<min)
			min
		}
	}
}
