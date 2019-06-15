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

const int MAXN = 1010;
const ll MOD = 998244353;
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    map<ll, ll> mapFreq;
    cin >> n >> k;
    rp(i,n) {
        ll a;
        cin >> a;
        mapFreq[a]++;
    }
    vll num;
    num.pb(0);
    for(auto p : mapFreq) {
        num.pb(p.fi);
    }

    for(int i = 1; i < num.size(); i++) {
        dp[1][i] = (dp[1][i-1] + mapFreq[num[i]]) % MOD;
    }
    for(int i = 2; i <= k; i++) {
        for(int j = 1; j < num.size(); j++) {
            if(j >= i) {
                dp[i][j] = (dp[i][j-1] + (dp[i-1][j-1] * mapFreq[num[j]]) % MOD) % MOD;
            }

        }
    }

    TRACE(
        for(int i = 1; i < num.size(); i++)
            cout << num[i] << " ";
        cout << endl;
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < num.size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    )

    cout << dp[k][num.size() - 1] << endl;

    return 0;
}