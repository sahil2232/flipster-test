#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int i,j,n,h,a,b,max=0,sum=0;
		cin >> n;
		cin >> h;
		long long int arr[n];
		memset(arr,0,sizeof(arr));
		for(j=0;j<n;j++)
		{
			cin >> a;
			cin >> b;
			for(i=a;i<=b;i++)
				arr[i]++;	
		}
		
		for(i=0;i<h;i++)
			sum+=arr[i];
		for(i=1;i<=n-h;i++)
		{
			if(sum>max)
				max=sum;
			sum+=(arr[i+h-1]-arr[i-1]);
		}
		if(sum>max)
			max=sum;
		cout << (n*h-max) << endl;	
	}
}