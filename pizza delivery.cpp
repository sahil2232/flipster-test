#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

int main()
{
	long int i,j,t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		long int h[n],k[n],maxim=0;
		for(i=0;i<n;i++)
		{
			cin >> h[i];
			if(h[i]>maxim)
				maxim=h[i];
		}
		for(i=0;i<n;i++)
			cin >> k[i];
		long int a[2*maxim+1][n+1];

		for(i=0;i<=2*maxim;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0)
					a[i][j]=0;
				else if(j==0)
					a[i][j]=LONG_MAX;
				else if(k[j-1]<=i)
					a[i][j]=min(1+a[i-k[j-1]][j],a[i][j-1]);
				else
					a[i][j]=a[i][j-1];
			}
		}
		long int sum=0;
		for(i=0;i<n;i++)
			sum+=a[2*h[i]][n];
		cout << sum << endl;
	}
}