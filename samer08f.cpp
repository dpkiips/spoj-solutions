#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	while(1)
	{
	scanf("%lld",&n);
	if(n==0)
	break;
	ll sum=0;
	while(n)
	{
		sum=sum+(n*n);
		n--;
	}
	printf("%lld\n",sum);
    }
}
