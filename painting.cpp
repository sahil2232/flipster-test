#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	long long int i,n,m,h,sum=0;
	cin >> n;
	cin >> m;
	cin >> h;

	long long int a[100001]={-1},j,cost=0,rem=n*m,sum=0;
	for(i=0;i<h;i++)
	{
		cin >> j;
		sum+=j;
		cin >> a[j];
	}

	if(sum<n*m)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for(i=0;i<100001;i++)
	{
		if(a[i]==-1)
			continue;
		if(rem>i)
		{
			rem-=i;
			cost+=(a[i]*i);
		}
		else
		{
			cost+=(rem*i);
			break;
		}
	}


	cout << cost << endl;
}