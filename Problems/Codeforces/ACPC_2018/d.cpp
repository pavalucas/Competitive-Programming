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
    ifstream in("dull.in");
    int t;
    in >> t;
    while( t-- ) {
        set< ll > has_candy;
        ll r, c, k;
        in >> r >> c >> k;
        ll total_bad = 0;
        map< ll, vector<ll> > proc;
        ll prev_x = 0;

        for(int _ = 0; _ < k; ++_) {
            ll i, j; in >> i >> j;
            proc[j].push_back(i);
        }

        for( const auto& x : proc ) {
            ll delta = x.first - prev_x, top_y = r + 1;
            int current_parity = sz(has_candy) % 2;
            for( auto it = has_candy.rbegin(); it != has_candy.rend(); ++it) {
                if( (current_parity & 1) == 1 ) total_bad = total_bad + ( top_y - *it ) * delta;
                top_y = *it;
                current_parity ^= 1;
            }

            for( const auto& y : x.second ) {
                if( has_candy.find(y) != has_candy.end() ) has_candy.erase(y);
                else has_candy.insert(y);
            }

            prev_x = x.first;
        }
        // last part!
        ll delta = c + 1 - prev_x, top_y = r + 1;
        int current_parity = sz(has_candy) % 2;
        for( auto it = has_candy.rbegin(); it != has_candy.rend(); ++it) {
            if( (current_parity & 1) == 1 ) total_bad = total_bad + ( top_y - *it) * delta;
            top_y = *it;
            current_parity ^= 1;
        }

        cout << total_bad << " " << r * c - total_bad << endl;
    }
    return 0;
}