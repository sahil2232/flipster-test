#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k,n;
		cin >> n;
		cin >> k;
		if(k==1)
			cout << n << endl;
		else if(2*k<=n)
		{
			int i,two=2;
			for(i=1;i<=k;i++)
			{
				cout << two << " ";
				two=two+2;
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}