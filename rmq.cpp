#include<iostream>
using namespace std;
long long int arr[10000000];
void construct(long long int node,long long int ll,long long int ul,long long int a[])
{
	if(ll==ul)
	{
		arr[node]=a[ll];
		return;
	}
	construct(2*node,ll,(ll+ul)/2,a);
	construct(2*node+1,1+(ll+ul)/2,ul,a);
}
long long int query(long long int node,long long int ll,long long int ul,long long int l,long long int r)
{
	if(ll>r||ul<l)
	return 100000000;
	if(ll>=l&&ul<=r)
	return arr[node];
	else
	return min(query(2*node,ll,(ll+ul)/2,l,r),query((2*node)+1,1+(ll+ul)/2,ul,l,r));
}
int main()
{
	long long int n,i;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	construct(1,0,n-1,a);
	long long int q;
	cin>>q;
	while(q--)
	{
	long long int l,r,ans;
	cin>>l>>r;
	ans=query(1,0,n-1,l,r);
	cout<<ans<<endl;
}
return 0;
}
