#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
	int i,j,t,x,y,m;
	cin >> t;
	while(t--)
	{
		cin >> m;
		cin >> x;
		cin >> y;
		int a[101]={0},sum=0,p;
		for(i=0;i<m;i++)
		{
			cin >> p;
			for(j=p-x*y;j<=p+x*y;j++)
			{
				if(j<1 || j>100)
					continue;
				a[j]=1;
			}
		}
		
		for(i=1;i<=100;i++)
			if(a[i]==0)
				sum++;

		cout << sum << endl;
	}
}