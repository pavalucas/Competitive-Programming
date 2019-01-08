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

const int MAXN = 100010;
ll dp[MAXN][3];
ll mat[MAXN][3]; 

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    rp(i,n) rp(j,3) cin >> mat[i][j];
    
    rp(j,3) dp[0][j] = mat[0][j];    
    rep(i,1,n) {
    	rp(j,3) {
    		dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + mat[i][j];
    	}
    }
    
    ll resp = 0;
    rp(j,3) resp = max(dp[n-1][j], resp);
    cout << resp << '\n';
      
    return 0;
}
