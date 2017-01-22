#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
int main()
{
	int p,n;
	sf(p);
	char s[45];
	while(p--)
	{
		int a[8]={0};
	     sf(n);
		cin>>s;
		int i,l;
		for(i=2;i<40;i++)
		{
			int a0,a1,a2;
			if(s[i]=='T')
			a0=0;
			else
			a0=1;
			if(s[i-1]=='T')
			a1=0;
			else
			a1=1;
			if(a[i-2]=='T')
			a2=0;
			else
			a2=1;
			int temp=a0*pow(2,0)+a1*pow(2,1)+a2*pow(2,2);
			cout<<temp<<endl;
			a[temp]++;
		}
	/*	cout<<n<<" ";
		for(i=0;i<8;i++)
		cout<<a[i]<<" ";
		cout<<endl;*/
	}
}
