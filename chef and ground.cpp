#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i,n,m;
		cin >> n;
		cin >> m;
		long int max=0,sum=0;
		for(i=0;i<n;i++)
		{
			int a;
			cin >> a;
			sum+=a;
			if(a>=max)
				max=a;
		}

		long int total = max*n-sum;
		if(total>m)
			cout << "No" << endl;
		else
		{
			m-=total;
			if(m%n==0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}