#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int t,n,m;
	cin >> t;
	while(t--)
	{
		int i,j,c,l;
		cin >> n;
		cin >> m;
		int soint[101]={0};
		int sofloat[101]={0};
		for(i=0;i<n;i++)
		{
			cin >> c;
			cin >> l;
			soint[l]+=c;
		}
		for(j=0;j<m;j++)
		{
			cin >> c;
			cin >> l;
			sofloat[l]+=c;
		}

		long int power=0;
		
		for(i=1;i<=100;i++)
			if(sofloat[i]>soint[i])
				power+=(sofloat[i]-soint[i]);

		cout << power << endl;
	}
}