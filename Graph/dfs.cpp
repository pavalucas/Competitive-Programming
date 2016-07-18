#include <vector>
#include <iostream>

using namespace std;

/*
	DFS (Depth-first search)
	-------------------------------------------------------------------------------
	Given an undirected graph we transverse the graph, starting from a given vertex,
	checking if all vertices were visited.

	- Checks if exist a path from vertex A to B
	- Detects connected components

	Complexity: O(|V| + |E|)
	-------------------------------------------------------------------------------
*/

vector<vector<int> > adjList;
vector<int> visited;

void dfs(int v)
{
	if(visited[v])
		return;

	visited[v] = 1;

	for(auto& p : adjList[v])
	{
		if(visited[p] == 0)
			dfs(p);
	}

}

int main(void)
{
	int test = 0;
	int v, e;

	cin >> v >> e;

	visited.resize(v);
	adjList.resize(v);

	fill(visited.begin(), visited.end(), 0);


	for(int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;

		adjList[a - 1].push_back(b - 1);
		adjList[b - 1].push_back(a - 1);
	}

	dfs(0);

	bool connect = true;
	for(auto& p : visited)
	{
		if(p == 0)
			connect = false;

	}

	if(connect)
		cout << "Connected Graph" << endl;
	else
		cout << "Disconnected Graph" << endl;


	return 0;
}