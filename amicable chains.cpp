#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;


void fillAdjList(long long int num,vector<long long int> adj[])
{
	long long int i;
	long long int sum=1;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		{
			if(num/i!=i)
			{
				sum+=i;
				sum+=num/i;
			}
			else
				sum+=i;
		}
	}
	adj[num].push_back(sum);
}

void findLength(long long int start,long long int current,long long int num,vector<long long int>adj[],bool visited[],long long len,long long int * cycleLength)
{
	if(current>num)
	{
		*cycleLength=-1;
		return;
	}
	len++;
	visited[current]=true;
	vector<long long int> :: iterator it;
	for(it=adj[current].begin();it!=adj[current].end();it++)
	{
		if((*it)==current)
		{
			*cycleLength=len;
			return ;
		}
		if(!visited[(*it)])
		{
			findLength(start,(*it),num,adj,visited,len+1,cycleLength);
			if(*cycleLength==-1)
				return ;
		}
	}
}



int main()
{
	long int i,num;
	cin >> num;
	vector<long long int> *adj;
	adj=new vector<long long int>[num+1];
	for(i=2;i<=num;i++)
		fillAdjList(i,adj);

	/*
	for(i=1;i<=num;i++)
	{
		vector<long long int> :: iterator it;
		cout << i << " ---> ";
		for(it=adj[i].begin();it!=adj[i].end();it++)
			cout << (*it) << " ";
		cout << endl;
	}
	*/

	long long int maxChain=0,smallestNum=num;
	for(i=2;i<=num;i++)
	{
		bool visited[num];
		memset(visited,false,sizeof(visited));
		long long int cycleLength;
		findLength(i,i,num,adj,visited,0,&cycleLength);
		if(cycleLength!=-1)
		{
			if(cycleLength>=maxChain && i<=smallestNum)
			{
				maxChain=cycleLength;
				smallestNum=i;
			}
		}
	}

	cout << smallestNum << endl;




}