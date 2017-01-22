#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll lsum;
	ll rsum;
	ll tsum;
	ll result;
};
node tree[200003];
void build(int a[],int st,int s,int e)
{
//	cout<<s<<" "<<e<<endl;
	if(s>e)
	return;
	if(s==e)
	{
		tree[st].lsum=a[s];tree[st].rsum=a[s];
		tree[st].tsum=a[s];
		tree[st].result=a[s];
		return;
	}
	build(a,2*st,s,(s+e)/2);
	build(a,2*st+1,(s+e)/2+1,e);
	tree[st].tsum=tree[2*st].tsum+tree[2*st+1].tsum;
	tree[st].lsum=max(tree[2*st].lsum,tree[2*st].tsum+tree[2*st+1].lsum);
	tree[st].rsum=max(tree[2*st+1].rsum,tree[2*st+1].tsum+tree[2*st].rsum);
	tree[st].result=max(tree[2*st].rsum+tree[2*st+1].lsum,max(tree[2*st].result,tree[2*st+1].result));
}
node query(int st,int s,int e,int l,int r)
{
	if(s>=l&&e<=r)
	return tree[st];
	int mid=(s+e)/2;
	cout<<s<<" "<<e<<endl;
	node le,ri;
	if(r<=mid)
	return query(2*st,s,mid,l,r);
	if(l>mid)
	return query(2*st+1,mid+1,e,l,r);
	le=query(2*st,s,mid,l,r);
	ri=query(2*st+1,mid+1,e,l,r);
	node temp;
		temp.tsum=le.tsum+ri.tsum;
	temp.rsum=max(ri.rsum,ri.tsum+le.rsum);
	temp.lsum=max(le.lsum,le.tsum+ri.lsum);
	temp.result=max(le.rsum+ri.lsum,max(le.result,ri.result));
	return temp;
}
void update(int st,int s,int e,int pos,int v)
{
	if(s>e||pos>e||pos<s)
	return;
	if(s==e&&s==pos)
	{
		tree[st].lsum=v;tree[st].rsum=v;
		tree[st].tsum=v;
		tree[st].result=v;
		return;
	}
	int mid=(s+e)/2;
	if(pos<=mid)
	update(2*st,s,mid,pos,v);
	else
	update(2*st+1,mid+1,e,pos,v);
	tree[st].tsum=tree[2*st].tsum+tree[2*st+1].tsum;
	tree[st].lsum=max(tree[2*st].lsum,tree[2*st].tsum+tree[2*st+1].lsum);
	tree[st].rsum=max(tree[2*st+1].rsum,tree[2*st+1].tsum+tree[2*st].rsum);
	tree[st].result=max(tree[2*st].rsum+tree[2*st+1].lsum,max(tree[2*st].result,tree[2*st+1].result));
}
int main()
{
	int n,i;
/*	for(i=0;i<1000000;i++)
	{
		tree[i].lsum=INF;tree[i].rsum=INF;tree[i].tsum=INF;tree[i].result=INF;
	}*/
//	tree[k].lsum=INF;tree[k].tsum=INF;tree[k].rsum=INF;tree[k].result=INF;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	build(a,1,0,n-1);
	int q,k,l,r;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&k,&l,&r);
		if(k==0)
		update(1,0,n-1,l-1,r);
		else
		{
		node ans=query(1,0,n-1,l-1,r-1);
		printf("%lld\n",ans.result);
	}
	}
}
