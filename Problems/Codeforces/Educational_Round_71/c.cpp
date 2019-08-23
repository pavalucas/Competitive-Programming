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

const int MAXN = 200020;
const ll INF = 1e16;
ll dp[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        s += '0';
        WATCH(s);
        dp[0][0] = b;
        dp[0][1] = INF;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1' || s[i-1] == '1') dp[i][0] = INF;
            else dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2*a + b);

            dp[i][1] = min(dp[i-1][0] + 2*a + 2*b, dp[i-1][1] + a + 2*b);

            WATCH(i);
            WATCH(dp[i][0]);
            WATCH(dp[i][1]);
        }
        cout << dp[n][0] << endl;
    }
}