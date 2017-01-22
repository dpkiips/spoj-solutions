#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
#define mp make_pair
#define pp pair<int,int>
#define ii pair<int,pp>
int bit[1000000]={0};
void update(int ind,int n)
{
	while(ind<=n)
	{
		bit[ind]+=1;
		ind+=ind&(-ind);
	}
}
int get(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=bit[x];
		x-=x&(-x);
	}
	return sum;
}
int  main()
{
	int n,q,a,l,r,k,i;
	sf(n);
	vector<ii> v;
	for(i=0;i<n;i++)
	{
		sf(a);
		v.push_back(mp(a,mp(0,i)));
	}
	sf(q);
	vector<int> ans(q);
	vector<pp> q1;
	for(i=0;i<q;i++)
	{
		sf(l);sf(r);sf(k);
		v.push_back(mp(k,mp(1,i)));
		q1.push_back(mp(l,r));
	}
	//cout<<endl;
	//for(i=0;i<v.size();i++)
	//cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
	//cout<<endl<<endl;
	sort(v.begin(),v.end());
	for(i=v.size()-1;i>=0;i--)
	{
		//cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
		
		if(v[i].second.first==0)
		update(v[i].second.second+1,n);
		if(v[i].second.first==1)
		{
			int x=get(q1[v[i].second.second].first-1);
			int y=get(q1[v[i].second.second].second);
			ans[v[i].second.second]=y-x;
		}
	}
	for(i=0;i<q;i++)
	printf("%d\n",ans[i]);
}
