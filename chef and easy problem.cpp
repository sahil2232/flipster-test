#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int i,n;
		cin >> n;
		long long int a[n],sum=0;
		for(i=0;i<n;i++)
			cin >> a[i];

		sort(a,a+n);
		for(i=n-1;i>=0;i=i-2)
			sum+=a[i];

		cout << sum << endl;
	}

}