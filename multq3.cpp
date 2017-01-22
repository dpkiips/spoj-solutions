#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	int b;
	int c;
};
node tree[1000000];
int lazy[1000000]={0};
void build(int st,int s,int e)
{
	if(s>e)
	return;
	if(s==e)
	{
		tree[st].a=1;
		tree[st].b=0;
		tree[st].c=0;
		return;
	}
	build(2*st,s,(s+e)/2);
	build(2*st+1,(s+e)/2+1,e);
	tree[st].a=tree[2*st].a+tree[2*st+1].a;
	tree[st].b=tree[2*st].b+tree[2*st+1].b;
	tree[st].c=tree[2*st].c+tree[2*st+1].c;
}
void update(int st,int s,int e,int l,int r)
{
	if(lazy[st]>0)
	{
		int a1,a2,a3,c1;
		a1=tree[st].a;a2=tree[st].b;a3=tree[st].c;
		if(lazy[st]==1)
		{
			tree[st].a=a3;tree[st].b=a1;tree[st].c=a2;
		}
		if(lazy[st]==2)
		{
			tree[st].a=a2;tree[st].b=a3;tree[st].c=a1;
		}
		if(s!=e)
		{
			lazy[2*st]=(lazy[2*st]+lazy[st])%3;lazy[2*st+1]=(lazy[2*st+1]+lazy[st])%3;
		}
		lazy[st]=0;
   }
	//cout<<"i"<<s<<" "<<e<<endl;
	if(s>e||s>r||e<l)
	return;
	if(s>=l&&e<=r)
	{
		//cout<<"here"<<endl;
		int ce=tree[st].c;
		tree[st].c=tree[st].b;
		tree[st].b=tree[st].a;
		tree[st].a=ce;
		if(s!=e)
		{
			lazy[2*st]=(lazy[2*st]+1)%3;
			lazy[2*st+1]=(lazy[2*st+1]+1)%3;
		}
		return;
	}
	update(2*st,s,(s+e)/2,l,r);
	update(2*st+1,(s+e)/2+1,e,l,r);
	tree[st].a=tree[2*st].a+tree[2*st+1].a;
	tree[st].b=tree[2*st].b+tree[2*st+1].b;
	tree[st].c=tree[2*st].c+tree[2*st+1].c;
}
node get(int st,int s,int e,int l,int r)
{
	if(lazy[st]!=0)
	{
		int a1,a2,a3,c1;
		a1=tree[st].a;a2=tree[st].b;a3=tree[st].c;
		if(lazy[st]==1)
		{
			tree[st].a=a3;tree[st].b=a1;tree[st].c=a2;
		}
		if(lazy[st]==2)
		{
			tree[st].a=a2;tree[st].b=a3;tree[st].c=a1;
		}
		if(s!=e)
		{
			lazy[2*st]=(lazy[2*st]+lazy[st])%3;lazy[2*st+1]=(lazy[2*st+1]+lazy[st])%3;
		}
		lazy[st]=0;
	}
	if(s>e||s>r||e<l)
	return tree[0];
	if(s>=l&&e<=r)
	return tree[st];
	node le=get(2*st,s,(s+e)/2,l,r);
	node ri=get(2*st+1,(s+e)/2+1,e,l,r);
	node temp;
	temp.a=le.a+ri.a;
	temp.b=le.b+ri.b;
	temp.c=le.c+ri.c;
	return temp;
}
int main()
{
	int n,q,k,l,r;
	scanf("%d%d",&n,&q);
	tree[0].a=0;tree[0].b=0;tree[0].c=0;
	build(1,0,n-1);
	while(q--)
	{
		scanf("%d%d%d",&k,&l,&r);
		if(k==0)
		{
		
		update(1,0,n-1,l,r);
		/*	for(int i=0;i<=10;i++)
			cout<<tree[i].a<<" "<<tree[i].b<<" "<<tree[i].c<<endl;
			cout<<endl;
				for(int j=0;j<=30;j++)
			cout<<lazy[j]<<endl;
			cout<<endl;*/
	}
		else
		{
		
			node ans=get(1,0,n-1,l,r);
			printf("%d\n",ans.a);
		}
	}
}
