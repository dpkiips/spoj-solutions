#include<bits/stdc++.h>
using namespace std;
#define getchar_unlocked getchar
#define pp pair<int,int>
#define ii pair<pp,int>
#define mp make_pair
int bit[30001]={0};
inline int read()
{
  int ret = 0;
   int c = getchar_unlocked();
 
  while(c<'0' || c>'9')
    c = getchar_unlocked();
  while(c>='0' && c<='9')
  {
    ret = (ret<<3) + (ret<<1) + c - '0';
    c = getchar_unlocked();
  }
        return ret;
}
bool cmp(ii a,ii b)
{
	if(a.first.first==b.first.first)
	return a.second<b.second;
	return (a.first.first<b.first.first);
}
void add(int x)
{
//	cout<<x<<endl;
	while(x<=30000)
	{
	//	cout<<"here"<<endl;
		bit[x]+=1;
		x=x+(x&(-x));
	}
}
void remove(int x)
{
	while(x<=30000)
	{
	//	cout<<"here"<<endl;
		bit[x]-=1;
		x=x+(x&(-x));
	}
}
int sum(int x)
{
	int res=0;
	while(x>0)
	{
	//	cout<<"here"<<endl;
//	cout<<x<<" "<<bit[x]<<endl;
		res+=bit[x];
		x=x-(x&(-x));
	}
//	cout<<endl;
	return res;
}
 int xc[1000001];
int main()
{
	int n,q,i,l,r,p;
	vector<ii> v;
	n=read();
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=read();
		v.push_back(mp(mp(i+1,a[i]),0));
	}
	q=read();
	int query[q+1],ans[q+1];
	for(i=1;i<=q;i++)
	{
		l=read();r=read();
		v.push_back(mp(mp(r,l),i));
	}
	sort(v.begin(),v.end(),cmp);
//	cout<<v.size()<<endl;
int sf=v.size();
     memset(xc,-1,sizeof xc);
	for(i=0;i<sf;i++)
	{
	//	cout<<sf<<endl;
		p=v[i].second;
	//	cout<<p<<endl;
		if(p==0)
		{
			l=v[i].first.second;
		//	cout<<"a"<<endl;
		//	cout<<xc[l]<<endl;
			if(xc[l]!=-1)
			{
				remove(xc[l]);
				add(v[i].first.first);
			}
			else
			{
			///	cout<<"here"<<endl;
				int y=v[i].first.first;
				add(y);
			}
			xc[l]=v[i].first.first;
		}
		else
		{
			l=v[i].first.second;
			r=v[i].first.first;
		//	cout<<l<<" "<<r<<endl;
			int an=sum(r);
		//	cout<<an<<endl;
			//cout<<l<<" "<<r<<endl;
			an=an-sum(l-1);
		//	cout<<sum(l-1)<<endl;
			//cout<<v[i].second<<endl;
			ans[v[i].second]=an;
		}
    }
   // cout<<q<<endl;
    for(i=1;i<=q;i++)
    printf("%d\n",ans[i]);
}
