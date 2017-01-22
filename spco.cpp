#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int a1[101]={0};
void sieve()
{
	int i,j;
	a1[1]=1;
	for(i=4;i<101;i=i+2)
	a1[i]=1;
	for(i=3;i*i<101;i++)
	{
		if(a1[i]==0)
		{
			for(j=i*i;j<101;j=j+i)
			a1[j]=1;
		}
	}
}
int cb(ll r)
{
	int ans=0;
	while(r>0)
	{
		ans++;
		r=r&(r-1);
	}
	return ans;
}
int main()
{
	sieve();
	ll t,a,b,i;
	sf(t);
	while(t--)
	{
		sf(a);sf(b);
        int a1[100],b1[100];
        int c=0,c1;
        while(b>0)
        {
        	c++;
        	if(b%2==1)
        	c1=c;
        	b=b/2;
        
        }
        cout<<c1<<endl;
	}
}
