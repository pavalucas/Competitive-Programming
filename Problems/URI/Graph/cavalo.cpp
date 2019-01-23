#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep(i, x, n) for (int i = (x); i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int n, m, k;
vector<vpi> graph(20);
map<pii, int> mapGraph;
char tab[110][110];
int vis[110][110];

int dir[8][2] = {{2,1},{1,2},{-2,1}, {1,-2}, {2,-1}, {-1,2}, {-2,-1}, {-1,-2}};

bool checkCoord(int i, int j)
{
    return i < n && i >= 0 && j < m && j >= 0;
}

void buildGraph(int row, int col)
{
	queue<pair<pii, int>> q;
	pair<pii, int> ini = {{row, col}, 0};
	int vert = mapGraph[ini.fi];
	q.push(ini);
	vis[ini.fi.fi][ini.fi.se] = 1;
	while(!q.empty())
	{
		pii at = q.front().fi;
		int dist = q.front().se;
		q.pop();
		rp(i,8)
		{
			pii next = {at.fi + dir[i][0], at.se + dir[i][1]};
			if(checkCoord(next.fi, next.se) && tab[next.fi][next.se] != '#' &&
					vis[next.fi][next.se] == 0)
			{
				if(tab[next.fi][next.se] == 'P' || tab[next.fi][next.se] == 'C')
				{
					graph[vert].pb({mapGraph[next], dist+1});
				}
				vis[next.fi][next.se] = 1;
				q.push({next, dist+1});
			}
		}
	}
}

int tsp(int mask, int lastVert)
{
	if(mask == (1 << (k+1)) - 1)
	{
		TRACE(cout << "entrei" << endl;)
		for(auto& p : graph[lastVert]) if(p.fi == 0) return p.se;
	}
	WATCH(mask);
	WATCH(lastVert);
	int resp = numeric_limits<int>::max();
	for(auto& p : graph[lastVert])
	{
		if(!(mask & (1 << p.fi)))
		{
			resp = min(resp, p.se + tsp(mask | (1 << p.fi), p.fi));
		}
	}
	return resp;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	while(n + m + k != 0)
	{
		mapGraph.clear();
		int pawn = 1;
		rp(i,n) scanf("%s", tab[i]);
		rp(i,n) rp(j,m)
		{
			if(tab[i][j] == 'P') mapGraph.insert({{i,j}, pawn++});
			else if(tab[i][j] == 'C') mapGraph.insert({{i,j}, 0});
		}
		// clear graph
		rp(i,pawn) graph[i].clear();

		for(auto& p : mapGraph)
		{
			memset(vis, 0, sizeof(vis));
			WATCH(p.fi.fi);
			WATCH(p.fi.se);
			buildGraph(p.fi.fi, p.fi.se);
		}
		TRACE(
			rp(i,pawn)
			{
				cout << i << endl;
				for(auto& p : graph[i])
				{
					cout << p.fi << " dist: " << p.se << endl;
				}
			}
		)

		printf("%d\n", tsp(1, 0));
		scanf("%d%d%d", &n, &m, &k);
	}
    return 0;
}
