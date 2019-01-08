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

const int MOD = 1e9 + 7;
char mat[1001][1001];
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int h, w;
    cin >> h >> w;
    rp(i,h) rp(j,w) cin >> mat[i][j];
    rp(j,w) {
    	if(mat[0][j] == '.') dp[0][j] = 1;
    	else break;
    }
    rp(i,h) {
    	if(mat[i][0] == '.') dp[i][0] = 1;
    	else break;
    }
    rep(i,1,h) {
    	rep(j,1,w) {
    		if(mat[i][j] == '.') {
    			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    		}
    	}
    }
    
    TRACE(
    	rp(i,h) {
   			rp(j,w) {
   				cout << dp[i][j];
   			}
   			cout << '\n';
   		}
    )
    
    cout << dp[h-1][w-1] << '\n';
    
   
    return 0;
}
