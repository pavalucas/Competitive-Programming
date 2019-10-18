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
    ifstream in("icecream.in");
    int t;
    in >> t;
    while( t-- ) {
        int n, k;
        in >> n >> k;
        vector< pair<int, int> > v(n);
        for(int i = 0; i < n; ++i) in >> v[i].first;
        for(int i = 0; i < n; ++i) in >> v[i].second;

        sort( all(v), [&] ( const pii& a, const pii& b ) {
            return a.first < b.first;
        });

        int tol = v[k - 1].first;
        vector< int > best;
        for(int i = 0; i < n; ++i)
        {
            if( v[i].first <= tol ) best.emplace_back( 1ll * v[i].second );
        }
        sort( all(best) );
        reverse( all(best) );
        ll ans = 0;
        for(int i = 0; i < k; ++i) ans += best[i];
        cout << tol << " " << ans << endl;
    }
    return 0;
}