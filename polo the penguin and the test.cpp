#include <iostream>
#include <algorithm>

using namespace std;

int knapsack(int n,int W,int val[],int wt[])
{
	int k[n+1][W+1];
	int i,w;
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(wt[i-1]<=w)
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			else
				k[i][w]=k[i-1][w];
		}
	}
	return k[n][W];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i,n,W;
		cin >> n;
		cin >> W;

		int c[n],p[n],t[n];

		for(i=0;i<n;i++)
		{
			cin >> c[i];
			cin >> p[i];
			cin >> t[i];
			c[i]=c[i]*p[i];
		}

		cout << knapsack(n,W,c,t) << endl;

	}
}