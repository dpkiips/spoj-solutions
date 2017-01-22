#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,t,b,i,c=1;
	cin>>t;
	while(t--)
	{
		cin>>b>>n;
		ll a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		ll sum=0,flag=0,counter=1;
		for(i=n-1;i>=0;i--)
		{
			sum=sum+a[i];
			if(sum>=b)
			{
				flag=1;
				break;
			}
			counter++;
		}
		printf("Scenario #%lld:\n",c);
		if(flag==0)
		cout<<"impossible"<<endl;
		else
		cout<<counter<<endl;
		cout<<endl;
		c++;
	}
}
