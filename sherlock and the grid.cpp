#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int i,j,t;
	cin >> t;

	char arena[1001][1001];
	int ups[1001][1001],rights[1001][1001];
	while(t--)
	{
		int n;
		cin >> n;
		


		for(i=0;i<n;i++)
		{
			string str;
			cin >> str;
			for(j=0;j<n;j++)
				arena[i][j]=str[j];
		}

		
		for(i=n-1;i>=0;i--)
		{
			if(arena[n-1][i]=='#')
				ups[n-1][i]=0;
			else
				ups[n-1][i]=1;
		}	

		for(j=n-1;j>=0;j--)
		{
			if(arena[j][n-1]=='#')
				rights[j][n-1]=0;
			else
				rights[j][n-1]=1;
		}


		for(i=n-2;i>=0;i--)
		{
			for(j=n-1;j>=0;j--)
			{
				if(arena[i][j]=='.')
					ups[i][j]=ups[i+1][j];
				else
					ups[i][j]=0;
			}
		}


		for(i=n-1;i>=0;i--)
		{
			for(j=n-2;j>=0;j--)
			{
				if(arena[i][j]=='.')
					rights[i][j]=rights[i][j+1];
				else
					rights[i][j]=0;
			}
		}

		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout << ups[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout << rights[i][j] << " ";
			}
			cout << endl;
		}
		*/
		
		
		long long int sum=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(ups[i][j]==1 && rights[i][j]==1)
					sum++;

		
		cout << sum << endl;
	}
}