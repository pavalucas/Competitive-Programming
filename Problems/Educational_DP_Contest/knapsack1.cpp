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

#define TRACE(x...) x
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

ll dp[100010][101];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll N, W;
    cin >> N >> W;
    vll v(N), w(N);
    rp(i,N) cin >> w[i] >> v[i];
    rp(i,N+1) dp[0][i] = 0;
    rep(i,1,W+1) {
    	rep(j,1,N+1) {
    		if(i >= w[j-1]) {
    			dp[i][j] = max(dp[i][j-1], dp[i-w[j-1]][j-1] + v[j-1]);
    		} else {
    			dp[i][j] = dp[i][j-1];
    		}
    	}
    }
    
    cout << dp[W][N] << '\n';
    
    return 0;
}
