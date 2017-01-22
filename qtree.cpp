#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
#define root 0
#define N 10020
#define LOGN 14
ll par[14][N],base[N];
vector<ll> adj[N],costs[N],ind[N];
ll tree[6*N];ll position[N];
ll other[N];ll level[N];ll subsize[N];
ll chainno[N],chainhead[N];
int chain_num,ptr;
void build(ll node,ll s,ll e)
{
	if(s>e)
	return;
	if(s==e-1)
	{
		tree[node]=base[s];
		return;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
void update(ll node,ll s,ll e,ll x,ll val)
{
	if(s>e||s>x||e<x)
	return;
	if(s==e-1&&s==x)
	{
		tree[node]=val;
		return;
	}
	int mid=(s+e)/2;
	update(2*node,s,mid,x,val);
	update(2*node+1,mid+1,e,x,val);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
ll query_tree(ll node,ll s,ll e,ll l,ll r)
{
	if(s>e||l>e||r<s)
	return -1;
	if(s>=l&&e<=r)
	return tree[node];
	int mid=(s+e)/2;
	return (max(query_tree(2*node,s,mid,l,r),query_tree(2*node+1,mid+1,e,l,r)));
}
ll find_lca(ll u,ll v)
{
	int i,j;
	if(level[u]<level[v])
	{
		int temp=u;
		u=v;
		v=temp;
	}
	int diff=level[u]-level[v];
	while(diff>0)
	{
		int range=log2(diff);
		u=par[u][range];
		diff=diff-(1<<range);
	}
	if(u==v)
	return u;
	for(j=LOGN;j>=0;j--)
	{
		if(par[u][j]!=-1&&par[u][j]!=par[v][j])
		{
			u=par[u][j];
			v=par[v][j];
		}
	}
	return par[u][0];
}
void dfs(int curent,int lev,int prev)
{
	par[curent][0]=prev;
//	cout<<"here"<<endl;
	level[curent]=lev;
	subsize[curent]=1;
	for(int i=0;i<adj[curent].size();i++)
	{
		if(adj[curent][i]!=prev)
		{
		other[ind[curent][i]]=adj[curent][i];
		dfs(adj[curent][i],lev+1,curent);
		subsize[curent]+=subsize[adj[curent][i]];
	   }
	}
}
ll query_up(ll u,ll v)
{
	if(u==v)
	return 0;
	ll uchain,temp;ll vchain=chainno[v],ans=-1;
	while(1)
	{
		uchain=chainno[u];
		if(uchain==vchain)
		{
			if(u==v)
			break;
			temp=query_tree(1,0,ptr,position[v]+1,position[u]+1);
			ans=max(temp,ans);
			break;
		}
		temp=query_tree(1,0,ptr-1,position[chainhead[uchain]]+1,position[u]+1);
		ans=max(ans,temp);
		u=chainhead[uchain];
		u=par[u][0];
	}
	return ans;
}
ll query(ll u,ll v)
{
	int lc=find_lca(u,v);
	int ans=query_up(u,lc);
	int temp=query_up(v,lc);
	if(temp>ans)
	ans=temp;
	return ans;
}
ll change(ll i,ll val)
{
	ll y=other[i];
	update(1,0,ptr-1,position[y]+1,val);
}
void hld(int curn,int cost,int prev)
{
	if(chainhead[chain_num]==-1)
	chainhead[chain_num]=curn;
	chainno[curn]=chain_num;
	position[curn]=ptr;
	base[ptr++]=cost;
	int sc=-1,ncost;
	for(int i=0;i<adj[curn].size();i++)
	{
		if(adj[curn][i]!=prev)
		{
			if(sc==-1||subsize[sc]<subsize[adj[curn][i]])
			{
				sc=adj[curn][i];
				ncost=costs[curn][i];
			}
		}
	}
	if(sc!=-1)
	{
		hld(sc,ncost,curn);
	}
	for(int i=0;i<adj[curn].size();i++)
	{
		if(adj[curn][i]!=prev)
		{
			if(adj[curn][i]!=sc)
			{
				chain_num++;
				hld(adj[curn][i],costs[curn][i],curn);
			}
		}
	}
}
int main()
{
	ll t,i,j,u,v,w,n;
	sf(t);
	while(t--)
	{
		ptr=0;
		cout<<endl;
		sf(n);
		for(i=0;i<=n;i++)
		{
			adj[i].clear();
			costs[i].clear();
			ind[i].clear();
			chainhead[i]=-1;
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<14;j++)
			par[i][j]=-1;
		}
		for(i=1;i<n;i++)
		{
			sf(u);sf(v);sf(w);
			u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			costs[u].push_back(w);
			costs[v].push_back(w);
			ind[u].push_back(i-1);
			ind[v].push_back(i-1);
		}
		chain_num=0;
		dfs(0,0,-1);
		//cout<<"here1"<<endl;
		hld(0,-1,-1);
		build(1,0,ptr-1);
		for(j=1;j<14;j++)
		{
			for(i=0;i<n;i++)
			{
				if(par[i][j-1]!=-1)
				par[i][j]=par[par[i][j-1]][j-1];
			}
		}
		while(1)
		{
			char s[1000];
			cin>>s;
			ll a,b;
			if(s[0]=='D')
			break;
			cin>>a>>b;
			if(s[0]=='Q')
			{
			ll ans=query(a-1,b-1);
			cout<<ans<<endl;
		    }
			else
			change(a-1,b);
		}
	}
}

