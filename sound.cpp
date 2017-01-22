#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%lld",&x)
#define ll long long
ll a[10000000];
int main()
{
	ll n,m,c,i,j;
	sf(n);sf(m);sf(c);
	for(i=0;i<n;i++)
	sf(a[i]);
	ll flag=0;
	deque<ll> q1,q2;
	vector<ll> v1,v2;
	if(m>=1)
	{
	//	cout<<"here"<<endl;
	for(i=0;i<m;i++)
	{
		while(!q1.empty()&&a[i]>=a[q1.front()])
		q1.pop_back();
		q1.push_back(i);
	}
	v1.push_back(a[q1.front()]);
	for(i=m;i<n;i++)
	{
		while(!q1.empty()&&q1.front()<i-m+1)
		q1.pop_front();
		while(!q1.empty()&&a[i]>=a[q1.front()])
		q1.pop_back();
		q1.push_back(i);
		v1.push_back(a[q1.front()]);
	}
	for(i=0;i<m;i++)
	{
		while(!q2.empty()&&a[i]<=a[q2.front()])
		q2.pop_back();
		q2.push_back(i);
	}
	v2.push_back(a[q2.front()]);
	for(i=m;i<n;i++)
	{
		while(!q2.empty()&&q2.front()<i-m+1)
		q2.pop_front();
		while(!q2.empty()&&a[i]<=a[q2.front()])
		q2.pop_back();
		q2.push_back(i);
		v2.push_back(a[q2.front()]);
	}
	cout<<v1.size()<<" "<<v2.size()<<endl;
	for(i=0;i<v1.size();i++)
	{
		if(v1[i]-v2[i]<=c)
		{
		//cout<<i+1<<endl;
		flag=1;
	    }
	}
    }
  // if(flag==0)
	    //cout<<"NONE"<<endl;
}
