#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%lld",&x)
long long int find(long long int a,long long int b)
{
	if(b>a-b)
	b=a-b;
	long long int ans=1;
	for(long long int i=0;i<b;i++)
	{
		ans=ans*(a-i)/(i+1);
	}
	return ans;
}
int main()
{
	long long int t,n,k,i;
	sf(t);
    while(t--)
    {
    	sf(n);sf(k);
    	cout<<find(n-1,k-1)<<endl;
    }
}
