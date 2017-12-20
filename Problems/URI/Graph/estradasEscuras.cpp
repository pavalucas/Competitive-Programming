/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1152 */

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define rp(i, n) for(int i=0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

struct UnionFind {
    int nsize;
    vi parent, size;

    UnionFind(int n) : nsize(n) {
        size.resize(n, 1);
        parent.resize(n);
        iota(all(parent), 0);
    }

    int unions(int u, int v) {
        if (finds(u) == finds(v))
            return 0;
        size[parent[v]] += size[parent[u]];
        parent[parent[u]] = parent[v];
        nsize--;
        return 1;
    }

    int finds(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = finds(parent[u]);
    }
};

// Vertices de 0 a n-1
int kruskal(viii &edges, int n) {
    sort(edges.begin(), edges.end());

    UnionFind ds(n);

    int cost = 0;
    for (int i = 0; i < sz(edges); i++)
        cost += edges[i].fi * ds.unions(edges[i].se.fi, edges[i].se.se);

    return cost;
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int m, n;
	cin >> m >> n;
	while(n + m > 0) {
		viii edges;
		int tot = 0;
		rp(i,n) {
			int a, b, c;
			cin >> a >> b >> c;
			tot += c;
			edges.pb(mp(c, mp(a,b)));
		}
		int cost = kruskal(edges, m);
		cout << tot - cost << endl;
		cin >> m >> n;
	}
	return 0;
}
