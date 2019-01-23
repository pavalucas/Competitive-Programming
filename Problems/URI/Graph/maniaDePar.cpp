/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931 */

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define se second
#define fi first
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define MAXN 20010
#define INF 1000000

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;


vvpi g(MAXN);

vi dijkstra(int ini)
{
    set<pi> pq;
    vi vis(MAXN, 0);
    vi dist(MAXN, INF);
    pq.insert(mp(0, ini));
    dist[ini] = 0;

    while(!pq.empty())
    {
        int v = pq.begin()->se;
        pq.erase(pq.begin());
        vis[v] = 1;
        for(auto& p : g[v])
        {
            int u = p.fi;
            int w = p.se;
            if(!vis[u] and dist[u] > dist[v] + w)
            {
                pq.erase(mp(dist[u], u));
                dist[u] = dist[v] + w;
                pq.insert(mp(dist[u], u));
            }
        }
    }
    return dist;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    rp(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[2*a].pb(mp(2*b+1,c));
        g[2*a+1].pb(mp(2*b,c));

        g[2*b].pb(mp(2*a+1,c));
        g[2*b+1].pb(mp(2*a,c));
    }

    vi dist = dijkstra(2);
    if(dist[2*n] == INF)
        cout << -1 << endl;
    else
        cout << dist[2*n] << endl;
}