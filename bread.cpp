#include <iostream>

using namespace std;

int main()
{
	long long int t,n,k,a;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> k;
		
		long long int packages=1,rem_k=k,i=0,a[n];
		for(i=0;i<n;i++)
			cin >> a[i];
		i=0;
		while(1)
		{
			if(i==n)
			{
				break;
			}
			//cout << "Rem_k : " << rem_k << "   a[" << i << "]: " << a[i] << "   Packages : " << packages << endl;
			if(rem_k>=a[i])
			{
				rem_k-=(a[i]+1);
				i++;
				if(rem_k<=0 && i!=n)
				{	
					rem_k=k;
					packages++;
				}
			}
			else
			{
				if(rem_k==k)
				{
					if(a[i]%k==0){
						packages+=a[i]/k-1;
						rem_k=0;
						}
					else{
						packages+=a[i]/k;		
						rem_k=rem_k-(a[i]%rem_k)-1;
						}
					i++;
					if(rem_k<=0 && i!=n)
					{
						rem_k=k;
						packages++;
					}
				}
				else
				{
					a[i]-=rem_k;
					rem_k=k;	
					if(a[i]>0)
						packages++;
				}
			}
		}
		if(packages==0)
			packages++;
		cout << packages << endl;
	}
}