#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll t,n,m,i,j,prev,temp;
	sf(t);
	while(t--)
	{
		sf(n);
		ll a[n];
		for(i=0;i<n;i++)
		sf(a[i]);
		sf(m);
		ll b[m];
	     for(i=0;i<m;i++)
	     sf(b[i]);
	     sort(b,b+m);
	    ll min=LONG_LONG_MAX;
	    for(i=0;i<n;i++)
	    {
	    	prev=LONG_LONG_MAX;
	    	for(j=0;j<m;j++)
	    	{
	    		temp=abs(a[i]-b[j]);
	    		if(temp>prev)
	    		break;
	    		else
	    		{
	    			if(temp<min)
	    			min=temp;
	    			prev=temp;
	    		}
	    	}
	    }
	    printf("%lld\n",min);
	}
}
