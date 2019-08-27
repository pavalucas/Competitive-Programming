#include <bits/stdc++.h>
using namespace std;
#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )
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
 
struct UF {
    vi pai, smallest;
    vector< pii > go;
    int N;
    UF( int n ) {
        N = n;
        pai = vi(n);
        iota( all(pai), 0 );
        smallest = vi(n);
        go.resize(n);
    }
    
    pair<int, int> rep(int x) {
        if( go[x].second != x ) {
            rep( go[x].second );
            go[x] = go[ go[x].second ]; 
        }
        if( pai[ go[x].second ] != go[x].second )
        {
            rep( pai[ go[x].second ] );
            if( go[ pai[ go[x].second ] ].first < go[x].first )
            {
                go[x] = go[ pai[ go[x].second ] ];
            }
        }
        return go[x];
    }
    
    int acha_pai( int x ) {
        if( x != pai[x] ) pai[x] = acha_pai( pai[x] );
        return pai[x];
    }
    
    void unio(int a, int b) {
        if( go[a].first < go[b].first )
        {
            go[b] = go[a];
        }
        pai[b] = a; 
    }
    
    void set_smallest( const vector<int>& S ) 
    {
        for(int i = 0; i < N; ++i) 
        {
            smallest[i] = S[i];
            go[i] = make_pair( S[i], i);
        }
    }
};
int main()
{
    buff();
    int n, m;
    cin >> n >> m;
    UF famb(n);
    vector< int > S(n);
    for(int& x : S) cin >> x;
    famb.set_smallest( S );
 
    for(int i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        if( c == '?' )
        {
            int a;
            cin >> a;
            --a;
            auto V = famb.rep(a);
            cout << V.first << '\n';
        }
        else
        {
            int a, b;
            cin >> a >> b;
            --a; --b;
            famb.unio( a, b );
        }
    }
    return 0;
}
