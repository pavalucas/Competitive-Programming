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
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll MOD = 1000000007;

ll power(ll b, ll e, ll mod = numeric_limits<ll>::max()) {
    ll ret = 1;
    b = b % mod;
    while (e > 0) {
        if (e & 1) ret = (ret * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    ll resp = 0;
    ll count = 0;
    for(char c : s) {
    	if(c == 'a') count++;
    	else {
    		resp = (resp + power(2,count,MOD) - 1) % MOD;
    	}
    }
    cout << resp << '\n';
    return 0;
}
