#include <iostream>

using namespace std;

int main()
{
	long int i,n;
	cin >> n;

	int a[n];
	for(i=0;i<n;i++)
		cin >> a[i];

	long int max=0,currentMax=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			currentMax++;
			if(currentMax>max)
				max=currentMax;
		}
		else
		{
			if(currentMax>max)
				max=currentMax;
			currentMax=0;
		}

	}

	cout << max << endl;


}