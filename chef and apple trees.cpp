#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int i,n,ans=0;
		cin >> n;
		long int a[n];
		for(i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);

		long int curr,prev=-1;
		for(i=0;i<n;i++)
		{
			curr=a[i];
			if(curr!=prev)
			{
				ans++;
				prev=curr;
			}
		}
		cout << ans << endl;
	}
}