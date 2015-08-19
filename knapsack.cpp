#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n=4,W=5;
	int wt[]={2,3,4,5};
	int val[]={3,7,2,9};

	int i,w;
	int k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(w==0 || i==0)
				k[i][w]=0;
			if(wt[i-1]<=w)
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			else
				k[i][w]=k[i-1][w];
		}
	}

	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			cout << k[i][w] << " ";
		}
		cout << endl;
	}

}