#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<long int> v[10];
	long int i,len=str.size();
	long int distance[len];
	bool visited[len];
	memset(visited,false,sizeof(visited));
	memset(distance,0,sizeof(distance));
	queue<long int> q;
	for(i=0;i<len;i++)
		v[str[i]-'0'].push_back(i);
/*
	for(i=0;i<10;i++)
	{
		cout << i << " ----> ";
		vector <long int> :: iterator it;
		for(it=v[i].begin();it!=v[i].end();it++)
			cout << (*it) << " " ;
		cout << endl;
	}
*/
	q.push(0);
	visited[0]=true;
	while(!q.empty())
	{
		long int idx = q.front();
		if(idx==len-1)
			break;
		q.pop();

		long int i,sz=v[str[idx]-'0'].size();

		for(i=0;i<sz;i++)
		{
			if(!visited[v[str[idx]-'0'][i]])
			{
				visited[v[str[idx]-'0'][i]]=true;
				distance[v[str[idx]-'0'][i]]=distance[idx]+1;
				q.push(v[str[idx]-'0'][i]);	
			}
		}

		if(idx-1>=0 && !visited[idx-1])
		{
			visited[idx-1]=true;
			distance[idx-1]=distance[idx]+1;
			q.push(idx-1);
		}
		if(idx+1<len && !visited[idx+1])
		{
			visited[idx+1]=true;
			distance[idx+1]=distance[idx]+1;
			q.push(idx+1);
		}
	}
	cout << distance[len-1] << endl;



}