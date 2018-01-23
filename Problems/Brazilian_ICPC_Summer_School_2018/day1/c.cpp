#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define rp(i, n) for(int i=0; i < int(n); i++)
#define forn(i, n) for(int i=0; i<= int(n); i++)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

int dp[101][101], n, m;
string str1, str2;

void lcs() {
    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> str1 >> str2;
	n = str1.size();
	m = str2.size();
    lcs();
	TRACE(
		forn(i,n) {
			forn(j,m) {
				cout << dp[i][j];
			}
			cout << endl;
		}
	)
    vi resp1, resp2;
    cout << dp[n][m] << endl;
    while(dp[n][m] != 0) {
        if(dp[n][m] != dp[n-1][m] && dp[n][m] != dp[n][m-1]) {
            WATCH(n);
			WATCH(m);
			resp1.pb(n);
            resp2.pb(m);
            n--; m--;
        } else if(dp[n][m] == dp[n][m-1]) m--;
		else n--;
    }
    for(int i = resp1.size() - 1; i >= 0; i--)
        cout << resp1[i] << " ";
    cout << endl;

    for(int i = resp2.size() - 1; i >= 0; i--)
        cout << resp2[i] << " ";
    cout << endl;

	return 0;
}
