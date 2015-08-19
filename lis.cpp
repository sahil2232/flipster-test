#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ceil(long long int a[],long long int l,long long int r,long long int val)
{
    long long int m;
    while(l<r)
    {
        m=(l+r)/2;
        if(val>=a[m])
            l=m+1;
        else
            r=m;
    }
    return l;
}


int main() {
    long long int n;
    cin >> n;
    long long int i,j,a[n];
    
    for(i=0;i<n;i++)
        cin >> a[i];
    
    long long int len=1,tailArray[n];
    for(i=0;i<n;i++)
        tailArray[i]=0;
    tailArray[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<tailArray[0])
            tailArray[0]=a[i];
        else if(a[i]>tailArray[len-1])
        {
            tailArray[len]=a[i];
            len++;
        }
        else
        {
            tailArray[ceil(a,0,len-1,a[i])]=a[i];
        }
    }
    
    cout << len << endl;
    return 0;
}