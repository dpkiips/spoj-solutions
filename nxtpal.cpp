#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(s) scanf("%s",s)
#define sfi(x) scanf("%lld",&x)
char s[10000000];
int main()
{
	ll t;
	sfi(t);
	while(t--)
	{
		char x='N';
		sf(s);
		ll len=strlen(s);ll c=0,c1=0;
		ll fir=0,sec=len-1;
		while(fir<=sec)
		{
			if(s[fir]>s[sec])
			c=c+fir+1;
			else if(s[fir]<s[sec])
			c=c-fir-1;
			s[sec]=s[fir];
			fir++;sec--;
		}
		fir--;sec++;
		if(c<=0)
		{
		if(s[fir]=='9')
		{
			while(fir>=0&&s[fir]=='9')
			{
				s[fir]='0';s[sec]='0';
				fir--;sec++;
			}
			if(fir>=0)
			{
				s[fir]++;s[sec]=s[fir];
			}
			else
			{
				x='1';s[len-1]='1';
			}
		}
		else
		{
			s[fir]++;s[sec]=s[fir];
		}
		if(x=='N')
		cout<<s<<endl;
		else
		cout<<x<<s<<endl;
	   }
	   else
	   cout<<s<<endl;
	}
}
