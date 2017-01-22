#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(s) scanf("%s",s)
#define pp pair<string,ll>
#define mp make_pair
ll a[10000]={0};
void sieve()
{
	ll i,j;
	for(i=2;i<=(sqrt(10000));i++)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<=10000;j=j+i)
			{
				a[j]=1;
			}
		}
	}
}
ll num(string s)
{
	ll x=0,p=1;
	for(int i=3;i>=0;i--)
	{
		x=x+(s[i]-'0')*p;
		p=p*10;
	}
	return x;
}
int main()
{
	ll t,i,j;
	sieve();
	cin>>t;
	while(t--)
	{
		string s,s1;
		cin>>s>>s1;
		ll num2=num(s1);
		ll ans=10000000;
		ll mark[10000]={0};
		queue<pp> st;
		st.push(mp(s,0));
		mark[num(s)]=1;
		ll x=0;
		while(!st.empty())
		{
			string temp=st.front().first;
			ll ct=st.front().second;
			ll tnum=num(temp);
			st.pop();
			x++;
			if(tnum==num2)
			{
				ans=min(ans,ct);
			}
			string temp2;
			for(i=0;i<=3;i++)
			{
				temp2=temp;
				for(j=0;j<=9;j++)
				{
					if(i==0)
					{
						if(j>=1)
						{
							temp2[i]='0'+j;
							if(a[num(temp2)]==0&&mark[num(temp2)]==0)
							{
							st.push(mp(temp2,ct+1));
							mark[num(temp2)]=1;
						    }
						}
					}
					else
					{
					    	temp2[i]='0'+j;
							if(a[num(temp2)]==0&&mark[num(temp2)]==0)
							{
							st.push(mp(temp2,ct+1));
							mark[num(temp2)]=1;
						   }
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
