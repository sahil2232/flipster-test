#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


class Graph{
	public:
	vector<long int> *adj;
	long int *distance;
	long int V;
	Graph(long int V)
	{
		this->V=V;
		adj = new vector<long int>[V];
		distance = new long int[V];
	}

	void addEdge(long int v,long int w)
	{
		adj[v].push_back(w);
	}

	bool isEdge(long int v,long int w)
	{
		vector <long int > :: iterator it;
		it = find(adj[v].begin(),adj[v].end(),w);
		if(it!=adj[v].end())
			return true;
		return false;
	}

	void bfs()
	{
		bool visited[V];
		long int i;
		for(i=0;i<V;i++)
			visited[i]=false;
		queue<long int> q;
		distance[0]=0;
		visited[0]=true;
		q.push(0);
		while(!q.empty())
		{
			long int p = q.front();
			q.pop();
			vector<long int> :: iterator it;
			for(it=adj[p].begin();it!=adj[p].end();it++)
			{
				if(!visited[(*it)])
				{
					visited[(*it)]=true;
					distance[(*it)] = distance[p]+1;
					q.push((*it));
				}
			}
		}
	}

};

int main()
{
	string str;
	cin >> str;
	long int i,len=str.size();

	Graph g(len);

	for(i=1;i<len;i++)
	{
		g.addEdge(i,i-1);
		g.addEdge(i-1,i);
	}

	vector<long int> v[10];
	vector<long int> :: iterator it;
	for(i=0;i<len;i++)
	{
		v[str[i]-'0'].push_back(i);
	}

	for(i=0;i<10;i++)
	{
		if(v[i].size()>1)
		{
			vector<long int> :: iterator it2;
			
			for(it2=v[i].begin();it2!=v[i].end();it2++)
			{
				for(it=it2+1;it!=v[i].end();it++)
				{
					if(!g.isEdge((*it2),(*it)))
						g.addEdge((*it2),(*it));
					if(!g.isEdge((*it),(*it2)))
						g.addEdge((*it),(*it2));
				}
			}
		}
	}

	/*
	for(i=0;i<len;i++)
	{
		cout << i << " ----> ";
		vector<long int> :: iterator iter;
		for(iter=g.adj[i].begin();iter!=g.adj[i].end();iter++)
			cout << (*iter) << " ";
		cout << endl;
	}
	*/
	g.bfs();

	cout << g.distance[len-1] << endl;



}
