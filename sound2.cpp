#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
#define mp make_pair
int main()
{
	ll n,m,c,i;
	sf(n);sf(m);sf(c);
	ll a[n];
	map<ll,ll> m1;
	map<ll,ll> :: iterator it;
	vector<ll> v1,v2;
	for(i=0;i<n;i++)
	sf(a[i]);
	for(i=0;i<m-1;i++)
	{
		m1[a[i]]++;;
	}
	int flag=0,y;
	for(i=m-1,y=0;i<n;y++,i++)
	{
		m1[a[i]]++;
		if(m1.rbegin()->first-m1.begin()->first<=c&&(flag=1))
		cout<<y+1<<endl;
		m1[a[y]]--;
		if(m1[a[y]]==0)
		m1.erase(a[y]);
	}
	if(flag==0)
	cout<<"NONE"<<endl;
}
