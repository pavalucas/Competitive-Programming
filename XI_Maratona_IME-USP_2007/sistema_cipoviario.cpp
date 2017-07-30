/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2127 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef unsigned long long ull;

struct UnionFind {
    int nsize;
    vi parent, rk;

    UnionFind(int n) : nsize(n) {
        rk.resize(n, 1);
        parent.resize(n);
        iota(all(parent), 0);
    }

    int unions(int u, int v) {
        int a = finds(u);
        int b = finds(v);
        if (a == b)
            return 0;
        if(rk[a] < rk[b]) parent[a] = b;
        else parent[b] = a;
        if(rk[a] == rk[b]) rk[a]++;
        return 1;
    }

    int finds(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = finds(parent[u]);
    }
};

// Vertices de 0 a n-1
ull kruskal(viii &edges, int n) {
    sort(edges.begin(), edges.end());

    UnionFind ds(n);

    ull cost = 0;
    for (int i = 0; i < sz(edges); i++)
    {
        cost += edges[i].fi * ds.unions(edges[i].se.fi, edges[i].se.se);
    }
    return cost;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t = 1;
    while(cin >> n >> m)
    {
        viii edges(m);
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges[i].fi = c;
            edges[i].se.fi = a-1;
            edges[i].se.se = b-1;
        }
        cout << "Instancia " << t << endl;
        cout << kruskal(edges, n) << endl << endl;
        t++;
    }
    return 0;
}