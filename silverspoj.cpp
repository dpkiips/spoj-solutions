#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
		break;
		if(n%2==0)
		printf("%lld\n",n);
		else
		printf("%lld\n",(n/2));
	}
}
