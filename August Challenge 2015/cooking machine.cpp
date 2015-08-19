#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int findPower(long long int x)
{
	int power = log(x)/log(2);
	if(pow(2,power)==x)
		return power;
	return -1;
}


int main()
{
	int t;
	long long int a,b;

	cin >> t;
	while(t--)
	{
		cin >> a;
		cin >> b;

		int pow1=findPower(a),pow2=findPower(b);
		long int count=0;

		while(pow1==-1)
		{
			a/=2;
			pow1=findPower(a);
			count++;
		}
		count+=abs(pow2-pow1);
		cout << count << endl;
	}
}