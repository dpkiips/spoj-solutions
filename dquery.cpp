#include<bits/stdc++.h>
using namespace std;
#define getchar_unlocked getchar
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
struct node
{
	int l;
	int r;
	int idx;
};
int block;
bool cmp(node x,node y)
{
	if((x.l)/block != (y.l)/block)
	return x.l<y.l;
	return x.r<y.r;
}
int a[1000009]={0};
int cur=0;
inline void add(int val)
{
	if(a[val]==0)
	cur++;
	a[val]++;
}
inline void remove(int val)
{
	if(a[val]==1)
	cur--;
	a[val]--;
}
int main()
{
	int n,q,i,x,y;
	n=read();
	block=sqrt(n);
	int b[n];
	for(i=0;i<n;i++)
	b[i]=read();
	q=read();
	node query[q];
	for(i=0;i<q;i++)
	{
		x=read();y=read();
		query[i].l=x-1;
		query[i].r=y-1;query[i].idx=i;
	}
	sort(query,query+q,cmp);
	int l1=0,r1=-1;
	int ans[q];
	for(i=0;i<q;i++)
	{
		x=query[i].l;y=query[i].r;
		while(l1<x)
		{
			remove(b[l1]);
			l1++;
		}
		while(r1<y)
		{
			r1++;
			add(b[r1]);
		}
		while(l1>x)
		{
			l1--;
			add(b[l1]);
		}
		while(r1>y)
		{
			remove(b[r1]);
			r1--;
		}
		ans[query[i].idx]=cur;
	}
	for(i=0;i<q;i++)
	printf("%d\n",ans[i]);
}
