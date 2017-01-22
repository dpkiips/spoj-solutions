#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll l;
	ll r;
	node()
	{
		this->l=-1;
		this->r=-1;
	}
};
node trie[10000000];
ll k=1;
void add(ll x)
{
	int ptr=0;
	for(int i=31;i>=0;i--)
	{
		bool y=x&(1<<i);
	//	cout<<y<<endl;
		if(y==1)
		{
			if(trie[ptr].r==-1)
			{
				trie[ptr].r=k;
				ptr=k;
				k++;
			}
			else
			ptr=trie[ptr].r;
		}
		else
		{
			if(trie[ptr].l==-1)
			{
				trie[ptr].l=k;
				ptr=k;
				k++;
			}
			else
			ptr=trie[ptr].l;
		}
	}
}
ll query(ll x)
{
	ll i,num=0,ptr=0;
	bool y;
	for(i=31;i>=0;i--)
	{
		y=x&(1<<i);
		if(y==1)
		{
			if(trie[ptr].r!=-1)
			ptr=trie[ptr].r;
			else
			{
			ptr=trie[ptr].l;
			num=num+pow(2,i);
		    }
		}
		else
		{
			if(trie[ptr].l!=-1)
			ptr=trie[ptr].l;
			else
			{
			ptr=trie[ptr].r;
			num=num+pow(2,i);
		     }
		}
	}
	return num;
}
int main()
{
	ll n,i;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll t1=0,t2,t3,t4=-1;
	add(t1);
	for(i=0;i<n;i++)
	{
		t2=t1^a[i];
		t3=query(t2);
		t4=max(t4,t3);
		add(t2);
		t1=t2;
	}
	cout<<t4<<endl;
}
