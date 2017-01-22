#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll t,gn,mgn,a1,a2;
	sf(t);
	while(t--)
	{
		printf("\n");
		sf(gn);sf(mgn);
		ll max1=-1,max2=-1;
		while(gn--)
		{
		  sf(a1);
		  if(a1>max1)
		  max1=a1;	
		}
		while(mgn--)
		{
			sf(a2);
			if(a2>max2)
			max2=a2;
		}
		if(max1>=max2)
		{
			printf("Godzilla\n");
		}
		else
		{
			printf("MechaGodzilla\n");
		}
	}
}
