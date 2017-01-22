#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[1000000000];
int main()
{
	ll n,i;
	scanf("%lld",&n);
	ll a[n];
	scanf("%lld",&a[0]);
	for(i=1;i<n;i++)
	{
	scanf("%lld",&a[i]);
	a[0]=a[0]^a[i];
    }
    printf("%lld\n",a[0]);
}
