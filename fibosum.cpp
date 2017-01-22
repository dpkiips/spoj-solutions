#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
#define mod 1000000007
void mul1(ll rb[2][2],ll m[2][2])
{
ll x= ((rb[0][0]*m[0][0])%mod+ (rb[0][1]*m[1][0])%mod)%mod;
ll y =((rb[0][0]*m[0][1])%mod + (rb[0][1]*m[1][1])%mod)%mod;
ll z =((rb[1][0]*m[0][0])%mod + (rb[1][1]*m[1][0])%mod)%mod;
ll w =((rb[1][0]*m[0][1])%mod + (rb[1][1]*m[1][1])%mod)%mod;
rb[0][0]=x;
rb[0][1]=y;
rb[1][0]=z;
rb[1][1]=w;
}
void power(ll rb[2][2],ll p)
{
	if(p==0||p==1)
	return;
	ll m[2][2]={{1,1},{1,0}};
	power(rb, p/2);
    mul1(rb,rb);
    if (p % 2 != 0)
        mul1(rb,m);
	
}
ll f(ll n)
{
	if(n==0)
	return 0;
	ll rb[2][2]={{1,1},{1,0}};
	power(rb,n-1);
	cout<<rb[0][0]<<" "<<rb[0][1]<<endl;
	cout<<rb[1][0]<<" "<<rb[1][1]<<endl;
}
int main()
{
	ll t,n1,m1;
	sf(t);
	while(t--)
	{
		sf(n1);
		ll a1,a2;
		a1=f(n1);
	
	}
}
