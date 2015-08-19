#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

#define MY_MAX 1000005

using namespace std;

int main()
{
	long long int i,t;
	cin >> t;
	while(t--)
	{
		string l1,l2;
		cin >> l1;
		cin >> l2;
		
		if(l1[0]=='#' && l2[0]=='#')
		{
			cout << "No" << endl;
			continue;
		}

		long long int a1[l1.size()],a2[l2.size()];
		for(i=0;i<l1.size();i++)
		{
			if(l1[i]=='.')
				a1[i]=0;
			else
				a1[i]=MY_MAX;
		}
		for(i=0;i<l2.size();i++)
		{
			if(l2[i]=='.')
				a2[i]=0;
			else
				a2[i]=MY_MAX;
		}


		for(i=1;i<l1.size();i++)
		{
			if(a1[i]!=MY_MAX)
				a1[i]=min(a1[i-1],a2[i-1]+1);
			if(a2[i]!=MY_MAX)
				a2[i]=min(a2[i-1],min(a1[i]+1,a1[i-1]+1));
			if(a1[i]==MY_MAX && a2[i]==MY_MAX)
			{
				a1[l1.size()-1]=MY_MAX;
				a2[l2.size()-1]=MY_MAX;
				break;				
			}
		}

		if(a1[l1.size()-1]==MY_MAX && a2[l2.size()-1]==MY_MAX)
			cout << "No" << endl;
		else
		{
			cout << "Yes" << endl;
			cout << min(a1[l1.size()-1],a2[l2.size()-1]) << endl;
		}
		
	}
}