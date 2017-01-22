#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll t,n;
	sf(t);
	while(t--)
	{
		ll n;
		sf(n);
		ll i,a[n];
		for(i=0;i<n;i++)
		sf(a[i]);
		if(n==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		ll sum[n];
		ll total=0;
		sum[0]=0;ll c=0;
		for(i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+(c+1)*(a[i]-a[i-1]);
			total+=sum[i];
			c++;
		//	cout<<sum[i]<<endl;
		}
		cout<<total<<endl;
	}
} 
