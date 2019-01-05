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
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll MOD = 998244353ll;

inline ll powm( ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

// returns answer for each component
ll addComponent(int v, vi& color, vvi& g) {
    queue<int> q;
    ll result = 0ll;
    color[v] = 0;
    int atColor[2] = {1, 0};
    q.push(v);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int u : g[front]) {
            if(color[u] == color[front]) return result;
            if(color[u] == -1) {
                color[u] = 1 - color[front];
                atColor[color[u]]++;
                q.push(u);
            }
        }
    }
    result = (powm(2ll, atColor[0]) + powm(2ll, atColor[1])) % MOD;
    return result;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll resp = 1ll;
        int n, m;
        cin >> n >> m;
        vi color(n, -1);
        vvi g(n);
        rp(i,m) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        rp(i,n) {
            if(color[i] == -1) {
                resp = (resp * addComponent(i, color, g)) % MOD;
            }
        }
        cout << resp << '\n';
    }
}