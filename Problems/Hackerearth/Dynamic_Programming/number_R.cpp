#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define rp(i, n) for(int i=0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int dp[N];
int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t; string s;
	cin >> t;
	while(t--) {
		cin >> s;
		if(s.size() == 1) { 
			if(s[0] == 'K') cout << 1 << "\n";
			else cout << 0 << "\n";
			continue;
		}
		dp[0] = (s[0] == 'R')?0:1;
		int resp = -1;
		int qnt = (s[0]=='R')?1:0;
		for(int i = 1; i < s.size(); ++i) {
			dp[i] = max(0,dp[i-1]+(s[i]=='R'?-1:1));
			resp = max(resp, dp[i]);
			if(s[i] == 'R') qnt++;
		}
		if(resp != 0) cout << resp + qnt << "\n";
		else cout << qnt - 1 << "\n";
	}
	return 0;
}
