#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[2002];
	int i,j,k,l,l1,temp,co=1;
	while(1)
	{
		cin>>s;
		if(s[0]=='-')
		break;
		int total=0,c=0;
		int l=strlen(s);
		stack<char> s1;
		for(i=0;i<l;i++)
		{
			if(s1.empty()&&s[i]=='}')
			{
				c++;
				if(c%2==0)
				total=total+c/2;
				c=c%2;
			}
			else
			{
				if(s[i]=='{')
				s1.push('{');
				else if(s[i]=='}')
				s1.pop();
			}
		}
		while(c>0&&!s1.empty())
			{
				total=total+2;
				s1.pop();
				c--;
			}
			total=total+c/2;
			total=total+(s1.size())/2;
			cout<<co<<". "<<total<<endl;
		co++;
    }
}
