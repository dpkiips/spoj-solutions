#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
ll a[1000009];
ll mark[1000009];
int main()
{
	ll n,i;
	sf(n);
	sf(a[0]);
	mark[0]=2;
	for(i=1;i<n;i++)
	{
		sf(a[i]);
		if(a[i]>a[i-1])
		mark[i]=1;
		else if(a[i]<a[i-1])
		mark[i]=0;
		else
		mark[i]=mark[i-1];
	}
	if(n==1)
	cout<<"1"<<endl;
	else if(n==2)
	cout<<"2"<<endl;
	else
	{
	ll count=1;
	for(i=1;i<n;i++)
	{
		if(mark[i]!=mark[i-1])
		count++;
	}
	cout<<count<<endl;
   }
}
