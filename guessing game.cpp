#include <iostream>
#include <algorithm>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	if(b>a)
		return gcd(b,a);
	return gcd(b,a%b);
}



int main()
{
	long int t;
	cin >> t;
	while(t--)	
	{
		long long int n,m;
		cin >> n;
		cin >> m;
		long long int even1,odd1,even2,odd2;

		long long int num = (n/2)*(m-m/2) + (n-n/2)*(m/2),den=n*m;
		while(num!=0)
		{
			long long int t=gcd(num,den);
			if(t==1)
				break;
			num/=t;
			den/=t;
		}
		cout << num << "/" << den << endl;
	}
}