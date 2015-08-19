#include <iostream>
#include <algorithm>
#include <climits>
#include <cfloat>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		double d,u,n,m,r,c;
		int ans=0,j=0;
		double minRate = DBL_MAX;
		cin >> d;
		cin >> u;
		cin >> n;
		double currentCost = d*u;
		for(j=1;j<=n;j++)
		{
			cin >> m;
			cin >> r;
			cin >> c;

			double totalCost = (c/m)+r*u;
			if(totalCost<currentCost && totalCost<minRate)
			{
				//cout << "less\n";
				ans=j;
				minRate = totalCost;
			}
			else if(totalCost<currentCost && totalCost==minRate)
			{
				//cout << "equal\n";
				ans=0;
			}
			else
			{
				//ans=0;
			}
		}
		cout << ans << endl;
	}

}