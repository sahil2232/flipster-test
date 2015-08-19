#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long int i,n;
		cin >> n;

		long long int a[n],t,sum=0;
		for(i=0;i<n;i++)
		{
			cin >> a[i];
			sum+=a[i];
		}
		sort(a,a+n);
		t=a[0];
		cout << t*(sum-t) << endl;
	}
}