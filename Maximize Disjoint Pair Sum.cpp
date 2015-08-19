#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long long int i,t,n,d;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> d;
		long long int a[n],sum=0;
		for(i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		for(i=n-1;i>0;i--)
		{
			if(a[i]-a[i-1]<d)
			{
				sum+=(a[i]+a[i-1]);
				i--;;
			}
		}
		cout << sum << endl;
	}


}