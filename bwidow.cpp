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
		sf(n);
		ll r1[n],r2[n],i;
		ll max1=-1,maxi;
		for(i=0;i<n;i++)
		{
			sf(r1[i]);sf(r2[i]);
			if(r1[i]>max1)
			{
				max1=r1[i];
				maxi=i;
			}
		}
		ll flag=0;
		for(i=0;i<n;i++)
		{
			if(i!=maxi&&r2[i]>=max1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		cout<<"-1"<<endl;
		else 
		cout<<maxi+1<<endl;
	}
}
