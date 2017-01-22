#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll n,i;
	sf(n);
	ll a[4]={0};
	char s[5];
	while(n--)
	{
		cin>>s;
		if(strcmp(s,"1/4")==0)
		a[1]++;
		else if(strcmp(s,"1/2")==0)
		a[2]++;
		else if(strcmp(s,"3/4")==0)
		a[3]++;
	}
	ll tot=0;
	tot=tot+a[1]/4;
	a[1]=a[1]%4;
	if(a[2]>0)
	{
		tot=tot+a[2]/2;
		a[2]=a[2]%2;
		tot=tot+a[2]%2;
		if(a[1]>0&&a[2]>0)
		{
			if(a[1]>2)
			a[1]=a[1]-2;
			else
			a[1]=0;
		}
	}
	if(a[3]>0)
	{
		if(a[3]>a[1])
		tot=tot+a[3];
		else
		{
			
			tot=tot+a[3];
			a[1]=a[1]-a[3];
		}
	}
	if(a[1]>0)
	tot=tot+1;
	cout<<tot+1<<endl;
}
