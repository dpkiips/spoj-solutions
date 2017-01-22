#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,i=1;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
		break;
		if(n==1)
		cout<<"Case "<<i<<", N = "<<n<<", # of different labelings = "<<"1"<<endl;
		else
		{
		ll x=n-2;
		ll ans=pow(n,x);
		cout<<"Case "<<i<<", N = "<<n<<", # of different labelings = "<<ans<<endl;
	    }
	    i++;
	}
}
