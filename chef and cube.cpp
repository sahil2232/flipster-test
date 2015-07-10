#include <iostream>
#include <string>

using namespace std;

int ans()
{
	int i,j,k;
	string a[6];
	for(i=0;i<=5;i++)
		cin >> a[i];

	for(i=0;i<=1;i++)
		for(j=2;j<=3;j++)
			for(k=4;k<=5;k++)
				if(a[i]==a[j] && a[j]==a[k])
					return 1;
	return 0;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
		if(ans()==1)
			cout << "YES\n";
		else
			cout << "NO\n";
}