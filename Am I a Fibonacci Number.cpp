#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int findNum(long long int num,long long int fibo[],int mx)
{
	int i;
	for(i=0;i<mx;i++)
		if(fibo[i]==num)
			return 1;
	return 0;
}


int main()
{
	int i,mx=6000;
	long long int fibo[mx];
	string str;
	fibo[0]=0;fibo[1]=1;

	for(i=2;i<mx;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];

	int t;
	cin >> t;
	while(t--)
	{
		cin >> str;
		int len=str.length();
		long long int num=0;
		for(i=0;i<len;i++)
		{
			int p=str[i]-'0';
			num=num*10+p;
		}
		
		if(findNum(num,fibo,mx))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}