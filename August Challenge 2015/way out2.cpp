#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

long int makeSegmentTree(long int *arr,long int start,long int end,long int*st,long int index)
{
	if(start==end)
	{
		st[index]=arr[start];
		return st[index];
	}
	long int mid=start+(end-start)/2;
	st[index] = makeSegmentTree(arr,start,mid,st,2*index+1) + makeSegmentTree(arr,mid+1,end,st,2*index+2);
	return st[index];
}

long int* constructST(long int* arr,long int n)
{
	long int height = ceil(log2(n));
	long int max_size = 2*pow(2,height)-1;
	long int* st = new long int[max_size];
	makeSegmentTree(arr,0,n-1,st,0);
	return st;
}

long int getIntervalSum(long int *st,long int start,long int end,long int interval_start,long int interval_end,long int currentIndex)
{
	if(start>=interval_start && end<=interval_end)
		return st[currentIndex];
	if(start>interval_end || end<interval_start)
		return 0;
	long int mid = start+(end-start)/2;
	st[currentIndex] = getIntervalSum(st,start,mid,interval_start,interval_end,2*currentIndex+1) + getIntervalSum(st,mid+1,end,interval_start,interval_end,2*currentIndex+2);
	return st[currentIndex];
}

long int getSum(long int *st,long int n,long int interval_start,long int interval_end)
{
	return getIntervalSum(st,0,n-1,interval_start,interval_end,0);
}

void makeIntervalUpdate(long int *st,long int start,long int end,long int interval_start,long int interval_end,long int currentIndex,long int val)
{

	long int update,mid=start+(end-start)/2;
	if(start>interval_end || end<interval_start)
		return;
	else if(start<=interval_start && end>=interval_end)
		update=val*(interval_end-interval_start+1);
	else if(start<=interval_start && end<=interval_end)
		update=val*(end-interval_start+1);
	else if(start>=interval_start && end>=interval_end)
		update=val*(interval_end-start+1);
	else
		update=val*(end-start+1);
	st[currentIndex]+=update;

	if(start!=end)
	{
		makeIntervalUpdate(st,start,mid,interval_start,interval_end,2*currentIndex+1,val);
		makeIntervalUpdate(st,mid+1,end,interval_start,interval_end,2*currentIndex+2,val);
	}
}

void makeUpdate(long int* st, long int n,long int interval_start,long int interval_end,long int val)
{
	makeIntervalUpdate(st,0,n-1,interval_start,interval_end,0,val);
}


int main()
{

	int t;
	cin >> t;
	while(t--)
	{
		long long int i,n,h;
		cin >> n;
		cin >> h;
		long int* st;
		long int arr[n];
		for(i=0;i<n;i++)
			arr[i]=0;
		st = constructST(arr,n);
		for(i=0;i<n;i++)
		{
			long long int a,b;
			cin >> a;
			cin >> b;
			makeUpdate(st,n,a,b,1);
		}
		long long int max=0;
		for(i=0;i<=n-h;i++)
		{
			long long int currentSum=getSum(st,n,i,i+h-1);
			if(currentSum>max)
				max=currentSum;
		}
		cout << (n*h-max) << endl;
	}
	/*
	long int *st;
	long int arr[] = {0,0,0,0,0,0};
	st = constructST(arr,6);
	makeUpdate(st,6,1,3,1);
	//cout << getSum(st,6,2,5) << endl;
	makeUpdate(st,6,2,5,1);
	cout << getSum(st,6,0,1);
	//cout << getSum(st,6,1,5) << endl;
	cout << getSum(st,6,1,4) << endl;
	*/
}