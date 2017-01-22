#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
int main()
{
	int t,n,l,r;
	sf(t);
	while(t--)
	{
		sf(n);
		map<int,int> m;
		map<int,int> :: iterator it;
		while(n--)
		{
			sf(l);sf(r);
			m[l]=1;
			m[r]=2;
		}
		int c=0;int max1=-1;
		while(!m.empty())
		{
			it=m.begin();
			if(it->second==1)
			c++;
			else
			c--;
			m.erase(it);
			max1=max(max1,c);
		}
		printf("%d\n",max1);
	}
}
