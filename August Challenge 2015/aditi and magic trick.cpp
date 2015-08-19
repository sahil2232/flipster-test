#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

unsigned long long int fibo[96];

int findIndex(unsigned long long int num,int low,int high)
{	
	int mid;
	while(low<high)
	{
		if(fibo[low]>num)
			return low-1;
		mid = (low+high)/2;
		if(fibo[mid]==num)
			return mid;
		else if(fibo[mid]>num)
			high=mid;
		else
			low=mid+1;
	}
	if(low==high)
	{
		if(fibo[low]==num)
			return low;
		else if(fibo[low]>num)
			return low-1;
		else
			return low;
	}
	return mid;
}


int main()
{
	unsigned long long int i,j,t,n;
	cin >> t;
	fibo[1]=1;
	fibo[2]=2;
	for(i=3;i<=95;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
	while(t--)
	{
		cin >> n;
		cout << findIndex(n,1,95) << endl;
	}

}