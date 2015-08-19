#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		long int i,count=0;
		int alpha[26]={0};
		for(i=0;i<str.size();i++)
		{
			alpha[str[i]-'a']++;
			if(alpha[str[i]-'a']==1)
				count++;
			if(count==26)
				break;
		}
		cout << count << endl;
	}
}