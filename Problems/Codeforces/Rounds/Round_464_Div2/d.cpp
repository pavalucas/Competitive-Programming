#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F
#define INFLL 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rp(i, n) for(int i=0; i < int(n); i++)

#define contOnes __builtin_popcountl
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define unico(x) x.erase(unique(all(x)), (x).end())

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

const double inf = 1.0/0.0;
const double pi = 2 * acos(0.0);

#define TRACE(x...) x
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

#define MAXN 100010

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

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

set<int> graf[27];
set<pair<int, int>> edges;

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int rest = 0;
    rp(i,n) {
        if(graf[s1[i] - 'a'].find(s2[i] - 'a') == graf[s1[i] - 'a'].end())
            graf[s1[i] - 'a'].insert(s2[i] - 'a');
        else {
            rest++;
        }
    }

    UnionFind uf = UnionFind(27);

    rp(i,27) {
        for(int p : graf[i]) {
            int x = uf.finds(i);
            int y = uf.finds(p);

            if(x == y) edges.insert(mp(i, p));

            uf.unions(x, y);
        }
    }

    cout << n - edges.size() - rest << endl;
    rp(i,27) {
        for(int p : graf[i]) {
            if(edges.find(mp(i,p)) == edges.end()) {
                cout << (char)(i + 'a') << " " << (char)(p + 'a') << endl;
            }
        }
    }


	return 0;
}
