#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=10,l1,l2;
	char s[105],s1[105];
	while(t--)
	{
		cin>>s;
		cin>>s1;
		l1=strlen(s);
		l2=strlen(s1);
		char s2[105];
		int k=104,carry=0,i;
		for(i=0;i<l1;i++)
		{
			int temp;
			if(l2-i-1<0)
			temp=s[l1-i-1]-'0';
			else
			 temp=s[l1-1-i]-'0'+s1[l2-i-1]-'0';
			s2[k--]=(temp+carry)%10+'0';
		     carry=(temp+carry)/10;
		}
		while(carry>0)
		{
			s2[k--]=carry%10+'0';
			carry=carry/10;
		}
	     char s3[105];
	    i=k+1;int k1=104;
	    int num=0;
	    while(i<105)
	    {
	    	
	    	if(s2[i]=='1'&&i!=k+1)
	    	{
	    		s3[k1--]='0';
	    	}
	    	if(s2[i]=='0')
	    	{
	    		s3[k1--]=num/2+'0';
	    		i++;
	    		continue;
	    	}
	    	while(s2[i]!=0&&num<2&&i<105)
	    	{
	    		num=num*10+s2[i]-'0';
	    		i++;
	    	}
	    	s3[k1--]=num/2+'0';
	    	num=num%2;
	    }
	    char s4[105];int k2=104;
	    num=0;int j=k1+1;
	    for(i=0;i<l1;i++)
	    {
	    	int temp;
	    	if(j>104)
	    	temp=s[l1-i-1]-'0';
	    	else if(s[l1-i-1]<s3[j])
	    	{
	    		temp=10+s[l1-i-1]-'0'-(s3[j]-'0');
	    	    int x=s[l1-i-2]-'0'-1;
	    	    s[l1-i-2]=x+'0';
	    	}
	    	else
	    	temp=s[l1-i-1]-'0'-(s3[j]-'0');
	    	j++;
	    	s4[k2--]=temp+'0';
	    }
	   for(i=104;i>k1;i--)
	    cout<<s3[i];
	    cout<<endl;
	    int count=0;
	    for(i=k2+1;i<105;i++)
	    {
	    	if(s4[i]!='0')
	    	count++;
	       if(s4[i]=='0'&&count>0)
	       cout<<s4[i];
	       else if(s4[i]!='0')
	       cout<<s4[i];
	       else if(s4[i]=='0'&&count==0&&i==104)
	       cout<<s4[i];
	    }
	    cout<<endl;
	}
}
