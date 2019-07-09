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

const ll INF = numeric_limits<ll>::max();

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll> > c(n, vector<ll>(2));
    vector<vector<string> > allStrings(n, vector<string>(2));
    rp(i,n) {
        cin >> c[i][1];
        c[i][0] = 0;
    }
    rp(i,n) {
        string s;
        cin >> s;
        allStrings[i][0] = s;
        reverse(all(s));
        allStrings[i][1] = s;
    }

    vector<vector<ll> > dp(n, vector<ll>(2));
    dp[0][0] = c[0][0];
    dp[0][1] = c[0][1];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            ll firstVal;
            if(allStrings[i-1][j] <= allStrings[i][j] && dp[i-1][j] != INF) {
                firstVal = dp[i-1][j] + c[i][j];
            } else {
                firstVal = INF;
            }

            ll secVal;
            if(allStrings[i-1][j^1] <= allStrings[i][j] && dp[i-1][j^1] != INF) {
                secVal = dp[i-1][j^1] + c[i][j];
            } else {
                secVal = INF;
            }
            dp[i][j] = min(firstVal, secVal);
            WATCH(dp[i][j]);
        }
    }

    ll ans = min(dp[n-1][0], dp[n-1][1]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}