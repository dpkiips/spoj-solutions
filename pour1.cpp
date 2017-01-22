#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll t,a,b,c;
	sf(t);
	while(t--)
	{
		sf(a);sf(b);sf(c);
		ll g=__gcd(a,b);
		if(c%g!=0)
		printf("-1\n");
		else if(c>max(a,b))
		printf("-1\n");
		else
		{
		ll c1=0,c2=0;
		ll c3=c,move1=0;
		move1=1;
		c1=a;
		while(1)
		{
			if(c1==c||c2==c)
			break;
			if(c1==0)
			{
				c1=a;
				move1++;
			}
			else if(c2==b)
			{
				c2=0;
				move1++;
			}
			else
			{
				ll min1=min(b-c2,c1);
				c1=c1-min1;
				c2=c2+min1;
				move1++;
			}
			
		}
		c1=0;c2=b;
		ll mov2=0;
		mov2=1;
		while(1)
		{
			if(c1==c||c2==c)
			break;
			if(c2==0)
			{
				c2=b;
				mov2++;
			}
			else if(c1==a)
			{
				c1=0;
				mov2++;
			}
			else
			{
				ll min2=min(a-c1,c2);
				c1=c1+min2;
				c2=c2-min2;
				mov2++;
			}
			
		}
		ll ans=min(move1,mov2);
		printf("%lld\n",ans);
	}
	}
}
