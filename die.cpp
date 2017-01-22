#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
int main()
{
	ll t,h,a,i,j;
	sf(t);
	while(t--)
	{
		sf(h);sf(a);
		ll i=1;
        while(h>0&&a>0)
        {
        	if(i%2==1)
        	{
        		h=h+3;
        		a=a+2;
        	}
        	else if(i%2==0)
        	{
        	    ll temp,temp1;
        	    if(a-10<=0)
        	    {
        	    	h=h-20;
        	    	a=a+5;
        	    }
        	    else if(h-20<=0)
        	    {
        	    	h=h-5;
        	    	a=a-10;
        	    }
        	    else
        	    {
        	    	temp=h/20;
        	    	temp1=a/10;
        	    	if(temp>temp1)
        	    	{
        	    		h=h-20;
        	    		a=a+5;
        	    	}
        	    	else
        	    	{
        	    		h=h-5;
        	    		a=a-10;
        	    	}
        	    }
        	}
        	i++;
        }
        cout<<i-2<<endl;
	}
	
}
