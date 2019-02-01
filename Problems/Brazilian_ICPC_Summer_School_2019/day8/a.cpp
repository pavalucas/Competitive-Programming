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

int main()
{
    constexpr long long limit = 1000LL * 1000LL * 1000LL + 13LL;
    vector<long long> x;
    ifstream in("aztec.in");
    ofstream out("aztec.out");
    x.emplace_back( 0LL );
    x.emplace_back( 1LL );
    x.emplace_back( 6LL );
    long long base = 5;
    long long aux = 8;
    while( x.back() < limit ) {
        long long prox = x.back() + ( aux + base );
        base = (aux + base);
        aux += 4;
        x.emplace_back( prox );
    }
    long long v;
    in >> v;
    WATCHC(x)
    auto it = upper_bound( x.begin(), x.end(), v );
    int resp = distance( x.begin(), it) - 1;
    out << resp << endl;
    return 0;
}