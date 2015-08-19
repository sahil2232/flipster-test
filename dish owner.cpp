#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	long int i,t,n,q,query,x,y;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<long int> * chef;
		chef = new vector<long int>[n]; 

		long int dish2chef[n],score[n];

		for(i=0;i<n;i++)
		{
			dish2chef[i]=i;
			chef[i].push_back(i);
			cin >> score[i];
		}

		cin >> q;
		while(q--)
		{
			cin >> query;
			if(query==0)
			{
				cin >> x;
				cin >> y;
				long int chef1=dish2chef[x],chef2=dish2chef[y];
				long int len1=chef[chef1].size(),len2=chef[chef2].size();
				long int score1=score[chef[chef1][len1-1]],score2=score[chef[chef2][len2-1]];
				if(chef1==chef2)
					cout << "Invalid query!";
				else if(score1>score2)
				{
					chef[chef1].push_back(y);
					sort(chef[chef1].begin(),chef[chef1].end());
					dish2chef[y]=chef1;
					chef[chef2].erase(remove(chef[chef2].begin(),chef[chef2].end(),y),chef[chef2].end());
				}
				else
				{
					chef[chef2].push_back(x);
					sort(chef[chef2].begin(),chef[chef2].end());
					dish2chef[x]=chef2;
					chef[chef1].erase(remove(chef[chef1].begin(),chef[chef1].end(),x),chef[chef1].end());	
				}
			}
			else
			{
				cin >> x;
				cout << dish2chef[x]+1 << endl;
			}
		}
	}
}