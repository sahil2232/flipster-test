#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	long long int n,k;
	while(t--)
	{
		cin >> n;
		cin >> k;

		long long int i,a[n],b[n],maxVal=0;
		for(i=0;i<n;i++)
			cin >> a[i];
		for(i=0;i<n;i++)
			cin >> b[i];

		for(i=0;i<n;i++)
		{
			if((k/a[i])*b[i]>=maxVal)
				maxVal=(k/a[i])*b[i];
		}
		cout << maxVal << endl;
	}
}