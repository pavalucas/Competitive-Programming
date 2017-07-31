#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

#define EDGEWEIGHT 1
#define INF 0x3F3F3F3F
#define MAXN 1010

using namespace std;

/*
	BFS (Breadth-first search)
	-------------------------------------------------------------------------------
	Given an undirected graph we transverse the graph, starting from a given vertex,
	checking if all vertices were visited.

	- Checks if exist a path from vertex A to B
	- Detects connected components

	Complexity: O(|V| + |E|)
	-------------------------------------------------------------------------------
*/

vector<vector<int> > adjList;
int distance[MAXN];

void BFS(int ini)
{
	int current;
	queue<int> Q;

	memset(distance, INF, sizeof(distance));

	dist[ini] = 0;
	visited[ini] = 1;

	Q.push(ini);

	while(!Q.empty())
	{
		current = Q.front();
		Q.pop();

		for(auto& p : adjList[current])
		{
			if(dist[p] == INF)
			{
				dist[p] = dist[cur] + EDGEWEIGHT;
				Q.push(p);
			}
		}
	}

}

int main(void)
{

}