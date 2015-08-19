#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int i,j,n;
		cin >> n;
		long long int sum=(n*(n-1))/2;
		long long int count0=0,count1=0,count2=0;

		for(i=0;i<n;i++)
		{
			long long int t;
			cin >> t;
			if(t==0)
				count0++;
			if(t==1)
				count1++;
			if(t==2)
				count2++;
		}

		count0=(n-1)*count0 - (count0*(count0-1))/2;
		count1=(n-1)*count1 - (count1*(count1-1))/2;
		count2=(count2*(count2-1))/2;

		cout << sum-count0-count1-count2 << endl;;
	}

}