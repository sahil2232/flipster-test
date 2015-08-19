#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i,j,n;
		cin >> n;
		int a[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin >> a[i][j];

		long double ans[n][n];
		ans[0][0]=0;
		for(i=1;i<n;i++)
			ans[0][i]=ans[0][i-1]+a[0][i];
		for(j=1;j<n;j++)
			ans[j][0]=ans[j-1][0]+a[j][0];

		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				ans[i][j]=max(ans[i-1][j],ans[i][j-1])+a[i][j];
			}
		}

		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout << ans[i][j] << " "; 
				//ans[i][j]=max(ans[i-1][j],ans[i][j-1])+a[i][j];
			}
			cout << endl;
		}
		*/

		if(ans[n-1][n-1]<0)
			cout << "Bad Judges" << endl;
		else
		{
			cout.precision(15);
			cout << ans[n-1][n-1]/(long double)(2*n-3) << endl;
		}
	}
}