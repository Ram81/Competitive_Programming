#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int v[100005]={0};

void dfs(int u)
{
	if(v[u])
		return;
	for(vector<int>::iterator it=v[u].begin();it!=v[u].end();it++)
		if(!v[*it])
			dfs(*it);
	
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(vector<int>::iterator it=v[u].begin();it!=v[u].end();it++)
			if(!v[*it])
	}
}

int main()
{

	return 0;
}
