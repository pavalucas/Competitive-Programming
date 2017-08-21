/* Link: https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/ */

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define rp(i, n) for(int i=0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 11;

vector<vi> g(N);
vi vis(N, 0);
stack<int> topArr;
int n, m;

void dfs(int v) {
	vis[v] = 1;
	for(auto p : g[v])
		if(!vis[p])
			dfs(p);
	topArr.push(v);
}

// Implementation of toplogical sort using dfs and
// iterating through last node to first because ordering
// must be the lexicographically smallest one
void topSortDfs() {
	for(int i = n-1; i >= 0; --i)
		if(!vis[i])
			dfs(i);
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d %d",&n,&m);
	rp(i, m) {
		int a,b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].pb(b);
	}

	rp(i,n)
		sort(g[i].rbegin(), g[i].rend());

	topSortDfs();
	while(!topArr.empty()) {
		int cur = topArr.top();
		topArr.pop();
		printf("%d ", cur+1);
	}
	printf("\n");
	return 0;
}
