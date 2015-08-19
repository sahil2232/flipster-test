#include <iostream>

#define NUM 1000000007

using namespace std;


long long int fast_expo(long long int a,long long int b)
{
	if(b==0)
		return 1;
	long long int x = fast_expo(a,b/2);
	x=(x*x)%NUM;
	if(b&1)
		x=(x*a)%NUM;
	return x;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		cout << (fast_expo(2,n)-1+NUM)%NUM << endl;
	}
}