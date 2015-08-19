#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isOverLucky(long long int num)
{
	while(num)
	{
		int dig = num%10;
		if(dig==4 || dig==7)
			return true;
		num/=10;
	}
	return false;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int i,n,count=0;
		cin >> n;
		for(i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{	
				if(isOverLucky(i))
					count++;
				if((n/i)!=i && isOverLucky(n/i))
					count++;
			}
		}
		cout << count << endl;
	}
}