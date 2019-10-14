#include <bits/stdc++.h>
using namespace std;
#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& x : x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;
using pll = pair<ll, ll>;

void buff() { ios::sync_with_stdio( false ); cin.tie( nullptr ); }

constexpr ll MOD = 1e9 + 7;
constexpr ll linf = MOD * 1000LL;

inline ll pow_mod( ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

int main()
{
    buff();
    int n, m;
    cin >> n >> m;
    vector< vector< pair<int, ll> > > g(n);
    vector< tuple< int, int, ll> > edges;
    for(int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].emplace_back( b, c );
        g[b].emplace_back( a, c );
        edges.emplace_back( a, b, c );
    }
    vector< vector< ll > > dist(2, vector<ll>(n, linf) );
    auto dijkstra = [&] ( int root, int idx ) {
        dist[idx][root] = 0;
        set< pair<ll, int> > Q;
        Q.emplace(0ll, root);
        while( !Q.empty() ) {
            auto top = *(Q.begin() );
            Q.erase(Q.begin() );
            for( const auto& viz : g[top.second] ) {
                ll d_v = top.first + viz.second;
                if( dist[idx][viz.first] > d_v ) {
                    if( dist[idx][viz.first] != linf ) {
                        Q.erase( make_pair(dist[idx][viz.first], viz.first) );
                    }
                    dist[idx][viz.first] = d_v;
                    Q.emplace( d_v, viz.first );
                }
            }
        }
    };
    dijkstra(0, 0);
    dijkstra(n-1, 1);
    long long ans = 0LL;
    for( const auto& e : edges ) {
        int u, v;
        ll D;
        tie(u, v, D) = e;
        bool used = false;
        if( dist[0][u] + D + dist[1][v] == dist[0][n - 1] ) used = true;
        if( dist[0][v] + D + dist[1][u] == dist[0][n - 1] ) used = true;
        if( used ) ans += ( 2LL * D );
    }

    cout << ans << '\n';


    return 0;
}