#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep(i, x, n) for (int i = (x); i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MAXN = 200010;
const int INF = 1e9;
vvi g(MAXN);

bool isPrime(int p) {
    if(p == 1) return false;
    for(int i = 2; i*i <= p; i++) {
        if(p % i == 0) return false;
    }
    return true;
}


void bfs(int v, vi& dist) {
    dist[v] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto p : g[u]) {
            if(dist[p] == INF) {
                dist[p] = dist[u] + 1;
                q.push(p);
            }
        }
    }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vi dist(2*n+10, INF);

    rp(i,m) {
        int a, b;
        cin >> a >> b;
        g[2*a].pb(2*b+1);
        g[2*a+1].pb(2*b);

        g[2*b].pb(2*a+1);
        g[2*b+1].pb(2*a);
    }


    bfs(2*s, dist);
    WATCHC(dist);
    if(dist[2*t] == 2) cout << 2 << '\n';
    else if(dist[2*t+1] != INF) {
        int ans = dist[2*t+1];
        while(!isPrime(ans)) ans += 2;
        cout << ans << '\n';
    } else cout << -1 << '\n';
    return 0;
}