#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int i,j,k,n;
	cin >> n;
	long int t[n][n];
	long int dist[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin >> t[i][j];
			dist[i][j]=t[i][j];
		}
	}


	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}

	int m,s,g,d;
	cin >> m;
	while(m--)
	{
		cin >> s;
		cin >> g;
		cin >> d;
		long int timeTaken = dist[s][g]+dist[g][d];
		long int timeOptimised = dist[s][d];
		cout << timeTaken << " " << timeTaken-timeOptimised << endl;

	}

}