#include<bits/stdc++.h>
using namespace std;
bool a[100000000]={false};
#define ll long long
vector<ll> v;
void sieve()
{
	ll i,j;
	for(i=4;i<100000000;i=i+2)
	a[i]=true;
	for(i=3;i<sqrt(100000000);i=i+2)
	{
		if(a[i]==false)
		{
		for(j=i*i;j<100000000;j=j+(2*i))
		a[j]=true;
	    }
	}
	for(i=2;i<100000000;i++)
	{
		if(a[i]==false)
		v.push_back(i);
	}
}
int main()
{
	sieve();
	ll q,k;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&k);
		printf("%lld\n",v[k-1]);
	}
}
