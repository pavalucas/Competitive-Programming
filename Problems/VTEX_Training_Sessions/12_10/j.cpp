#include <bits/stdc++.h>
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
using namespace std;

using ll = long long;

ll powmod(ll a, ll b, ll mod)
{
    a %= mod;assert(b >= 0);
    ll res = 1;
    for(;b;b>>=1)
    {
        if(b&1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}


constexpr ll p0 = 1000000007;
constexpr int ms = 2010; // used for calcuating table of powers
constexpr int base = 13; // should be a little bit larger than the alphabet..

long long ppow[ms];

// It is very important to precalculate the powers
struct Hash {
    int len = 0; // does not always matter, depends on the problem
    long long H = 0LL;

    // check if len should be using in this operator.. depends on the problem
    Hash( long long h = 0 ) { H = h; }

    inline void addBack(char c) {
        int val = 0;
        if( c == 'o' ) val = 1;
        else val = 2;
        H = (H + (val) * ppow[len]) % p0;
        ++len;
    }

    inline void removeFront(char c)
    {
        int val = 0;
        val = ( c == 'o' ? 1 : 2 );
        H = (H - val + p0) % p0;
        ll invMod = powmod( base * 1ll, p0 - 2, p0);
        H = (H * invMod) % p0;

        --len;
    }

};

void init() {
    ppow[0] = 1;
    for(int i = 1; i < ms; ++i)
    {
        ppow[i] = (ppow[i - 1] * base ) % p0;
    }
}

int z_function(const vector<ll>& s, int target) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int res = 0;
    for( const int& x : z ) if( x == target ) ++res;
    return res;
}

int main()
{
    ios::sync_with_stdio( false ); cin.tie( nullptr );
    init();
    int n_p, m_p, n, m;
    cin >> n_p >> m_p >> n >> m;
    vector< string > ptt(n_p);
    vector< string > mat(n);
    for(auto& x : ptt) cin >> x;
    for(auto& x : mat) cin >> x;
    // get_hash_value for each col of the pattern
    vector< long long > hash_cols(m_p, 0);

    for(int col = 0; col < m_p; ++col)
    {
        Hash cur = Hash();
        for(int lin = 0; lin < n_p; ++lin) cur.addBack( ptt[lin][col] );
        hash_cols[col] = cur.H;
    }

    vector< vector<long long> > reduced_mat(n - n_p + 1, vector<ll>(m, 0LL) );

    for(int col = 0; col < m; ++col) {
        Hash cur = Hash();
        for(int lin = 0; lin < n; ++lin) {
            if( lin >= n_p ) cur.removeFront( mat[lin - n_p][col]);
            cur.addBack( mat[lin][col] );
            if( lin >= n_p - 1 ) reduced_mat[lin - n_p + 1][col] = cur.H;
        }
    }

    int resp = 0;
    for(int lin = 0; lin < n - n_p + 1; lin++) {
        vector<ll> curVec = hash_cols;
        curVec.push_back(numeric_limits<ll>::min());
        curVec.insert( curVec.end(), reduced_mat[lin].begin(), reduced_mat[lin].end() );
        resp += z_function(curVec, m_p);
    }

    cout << resp << '\n';


    return 0;
}