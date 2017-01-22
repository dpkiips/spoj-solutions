#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cout<<endl;
		cin>>n;
		ll a[n],sum=0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			sum=(sum+a[i])%n;
		}
		if(sum!=0)
		cout<<"NO\n";
		else
		cout<<"YES\n";
	}
}
