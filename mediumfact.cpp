#include<bits/stdc++.h>
using namespace std;
int a[100000001]={0};
void sieve()
{
	int i,j;
	a[1]=1;
	a[2]=2;
	for(i=4;i<=10000000;i=i+2)
	a[i]=2;
	for(i=3;i<=sqrt(10000000);i=i+2)
	{
		if(a[i]==0)
		{
			a[i]=i;
		for(j=i*i;j<=10000000;j=j+i)
		 {
		 	if(!a[j])
		 	a[j]=i;
		 }
	    }
	}
	for(i=2;i<10000000;i++)
	{
		if(a[i]==0)
		a[i]=i;
	}
}
int main()
{
	sieve();
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("1");
			while(n%a[n]==0&&n!=1)
			{
				printf(" x %d",a[n]);
				n=n/a[n];
			}
		printf("\n");
	}
}
