#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second 
#define INF 100000000
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
int n;
long long int value[1000000];
vector< pair<int,int> > item(1500);
long long int maxValue(int w){
	if(w==0){
		return 0;
	}
	if(value[w]!=-1){
		return value[w];
	}
	for(int i=0;i<n;i++) if(w-item[i].ff>=0)
	{
		long long int res=maxValue(w-item[i].ff);
			res+=item[i].ss;
		value[w]=max(value[w],res);	
	}
	//cout<<w<<" "<<value[w]<<"\n";
	return value[w];
}
int main(){
	int test;test=read();
	while(test--){
		memset(value,-1,sizeof value);
		int weight;weight=read();n=read();
		for(int i=0;i<n;i++){
			item[i].ff=read();
		}
		for(int i=0;i<n;i++){
		  item[i].ss=read();
		}
		long long ans=maxValue(weight);
		printf("%lld\n",ans);
	}
}
