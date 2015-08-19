#include <iostream>
#include <string>

using namespace std;

int main()
{
	long int i,t;
	cin >> t;
	while(t--)
	{
		string str1,str2;
		cin >> str1;
		cin >> str2;
		int alpha_small1[26]={0},alpha_small2[26]={0};
		int alpha_caps1[26]={0},alpha_caps2[26]={0};
		int digits1[10]={0},digits2[10]={0};

		for(i=0;i<str1.length();i++)
		{
			if(str1[i]>='a' && str1[i]<='z')
				alpha_small1[str1[i]-'a']++;
			else if(str1[i]>='A' && str1[i]<='Z')
				alpha_caps1[str1[i]-'A']++;
			else
				digits1[str1[i]-'0']++;
		}

		for(i=0;i<str2.length();i++)
		{
			if(str2[i]>='a' && str2[i]<='z')
				alpha_small2[str2[i]-'a']++;
			else if(str2[i]>='A' && str2[i]<='Z')
				alpha_caps2[str2[i]-'A']++;
			else
				digits2[str2[i]-'0']++;
		}

		long int sum=0;
		for(i=0;i<26;i++)
		{
			sum+=min(alpha_small1[i],alpha_small2[i]);
			sum+=min(alpha_caps1[i],alpha_caps2[i]);
		}
		for(i=0;i<10;i++)
			sum+=min(digits1[i],digits2[i]);

		cout << sum << endl;
	}
	
}