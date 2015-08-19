#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	long int i,n=100000;
	int seive[n+1];
	int marked[n+1];
	memset(marked,1,sizeof(marked));
	memset(seive,0,sizeof(seive));
	for(i=2;i<=n;i++)
	{
		if(seive[i]==0)
		{
			long int j=1;
			while(i*j<=n)
			{
				seive[i*j]++;
				j++;
			}
		}
	}

	/*
	for(i=2;i<=50;i++)
		cout << seive[i] << " ";
	*/
	int t;
	cin >> t;
	while(t--)
	{
		long int i,a,b,k,sum=0;
		cin >> a;
		cin >> b;
		cin >> k;

		for(i=a;i<=b;i++)
			if(seive[i]==k)
				sum++;
		cout << sum << endl;
	}
}