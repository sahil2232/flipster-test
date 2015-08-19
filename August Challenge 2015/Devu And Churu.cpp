#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

long int makeMaxST(long int *arr,long int start,long int end,long int *st,long int current)
{
	if(start>end)
	{
		st[current]=0;
		return 0;
	}
	if(start==end)
	{
		st[current]=arr[start];
		return st[current];
	}
	long int mid=start+(end-start)/2;
	st[current] = max(makeMaxST(arr,start,mid,st,2*current+1),makeMaxST(arr,mid+1,end,st,2*current+2));
	return st[current];	
}

long int * constructST(long int *arr,long int n)
{
	long int size = ceil(log2(n));
	long int max_size = 2*pow(2,size)-1;
	long int *st = new long int[max_size];
	memset(st,0,max_size*sizeof(st));
	makeMaxST(arr,0,n-1,st,0);
	return st;
}

long int getMaxinterval(long int *st,long int start,long int end,long int interval_start,long int interval_end,long int current)
{
	if(interval_start<=start && interval_end>=end)
		return st[current];
	if(interval_end<start || interval_start>end)
		return 0;
	long int mid=start+(end-start)/2;
	return max(getMaxinterval(st,start,mid,interval_start,interval_end,2*current+1),getMaxinterval(st,mid+1,end,interval_start,interval_end,2*current+2));
}

long int getMax(long int *st,long int n,long int interval_start,long int interval_end)
{
	return getMaxinterval(st,0,n-1,interval_start,interval_end,0);
}

int main()
{
	long int i,j,num,n,m;
	scanf("%ld",&n);
	scanf("%ld",&m);
	long int arr[n];
	for(i=0;i<n;i++)
		scanf("%ld",&arr[i]);

	long int *st;
	st = constructST(arr,n);

	long long int total=(n*(n+1))/2,idx=0;
	long long int a[total];
	for(num=1;num<=n;num++)
	{
		for(i=0;i<n-num;i++)
		{
			for(j=i;j<n;j++)
			{
				a[idx]=getMax(st,n,i,j);
				idx++;
			}
		}
	}



	for(i=0;i<m;i++)
	{
		char first_turn,sign;
		long long int k;
		scanf("%c",&sign);
		scanf("%lld",&k);
		scanf("%c",&first_turn);



	}

	/*
	long int arr[]={1,2,3,4,5,6},n=6,i;
	long int *st = constructST(arr,n);
	
	for(i=0;i<=(long int)2*pow(2,ceil(log2(n)))-1;i++)
		cout << st[i] << " ";
	
	cout << getMax(st,n,2,5);
	*/
}