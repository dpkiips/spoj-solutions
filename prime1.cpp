#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[31624]={0};
ll b[31624];
ll k;
ll c[1000005];
void sieve()
{
	ll i,j;
	k=0;
	for(i=2;i<=(sqrt(31624));i++)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<=31624;j=j+i)
			{
				a[j]=1;
			}
		}
	}
	for(i=2;i<=31624;i++)
	{
		if(a[i]==0)
		b[k++]=i;
	}
}
int main()
{
	sieve();
	ll i,j;
	ll t,m,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&m,&n);
		for(i=0;i<n-m+1;i++)
		c[i]=0;
		ll temp,temp1;
		if(m==1)
		c[0]=1;
		for(i=0;i<k;i++)
		{
			if(b[i]>n)
			break;
			
			temp=b[i];
			temp1=m/temp;
			temp1=temp1*temp;
			for(j=temp1;j<=n;j=j+temp)
			{
				if(j>=m)
				{
					if(j<=31623)
					{
						if(a[j]!=0)
						c[j-m]=1;
					}
					else
					c[j-m]=1;
					
				}
			}
		}
		for(i=0;i<n-m+1;i++)
		{
			if(c[i]==0)
			{
				printf("%lld\n",m+i);
			}
		}
		printf("\n");
	}
}
