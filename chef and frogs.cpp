#include <iostream>
#include <algorithm>

using namespace std;

long long int findIndex(long long int sorted[],long long int n,long long int val)
{
	long long int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(sorted[mid]==val)
			return mid;
		else if(sorted[mid]<val)
			low=mid+1;
		else
			high=mid-1;
	}
	return 0;
}



bool findDistance(long long int sorted[],long long int n,long long int a,long long int b,long long int k)
{
	//cout << "Original : " << a << " " << b << endl;
	a=findDistancendIndex(sorted,n,a);
	b=findIndex(sorted,n,b);
	//cout << "Sorted : " << sorted[a] << " " << sorted[b] << endl;
	if(b>a)
	{
		long long int t=b;
		b=a;
		a=t;
	}
	//cout << "Sorted Indexes : " << a << " " << b << endl;
	long long int i;
	for(i=b+1;i<=a;i++)
	{
		if(sorted[i]-sorted[i-1]>k)
			return false;
	}
	return true;
}

int main()
{
	long long int n,k,p;
	cin >> n;
	cin >> k;
	cin >> p;

	long long int i,frogs[n],sorted[n];
	for(i=0;i<n;i++)
	{
		cin >> frogs[i];
		sorted[i]=frogs[i];
	}

	sort(sorted,sorted+n);
	for(i=0;i<p;i++)
	{
		long long int a,b;
		cin >> a;
		cin >> b;

		if(a==b)
		{
			cout << "Yes" << endl;
			continue;
		}
		if(findDistance(sorted,n,frogs[a-1],frogs[b-1],k))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}