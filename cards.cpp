#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000007
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll temp=((n*(n+1))%MOD);
		ll temp1=(n*(n-1)/2)%MOD;
		cout<<(temp+temp1)%MOD<<endl;
	}
}
