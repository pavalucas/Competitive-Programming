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
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct compare
{
    bool operator()(const pll &lhs, const pll &rhs)
    {
        if(lhs.first != rhs.first) return lhs.first > rhs.first;
        else return lhs.second > rhs.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, m;
    cin >> n >> m;
    multiset<pll, compare> numSet;
    rp(i,m) {
        ll a, b;
        cin >> a >> b;
        numSet.insert({b,a});
    }
    ll resp = 0;
    for(auto p : numSet) {
        ll take = min(p.se, n);
        resp += take * p.fi;
        n -= take;
        WATCH(resp);
        if(n <= 0) break;
    }
    cout << resp << '\n';
    return 0;
}