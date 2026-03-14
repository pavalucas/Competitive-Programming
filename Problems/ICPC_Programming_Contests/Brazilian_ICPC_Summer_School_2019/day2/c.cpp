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

const int MAXN = 2010;
const ll INF = 0x3F3F3F3F3F3F3F3FLL;

ll dp[MAXN][MAXN];
pair <ll, ll> v[MAXN];

vector<ll> remainW(MAXN);
vector<ll> remainValue(MAXN);

int n;
ll solve (int x, int t) {
	if (x == n) return 0;
	if (t < 0) return INF;

	ll & p = dp[x][t];
	if (p + 1) return p;

	if (remainW[x] <= t) {
		return p = remainValue[x];
	}

	return p = min (v[x].second + solve (x + 1, t - v[x].first), solve (x + 1, t));
}

int main () {

	int T;

	cin >> n >> T;

	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		v[i] = {a, b};
	}

	sort (v, v + n);
	reverse (v, v + n);
	for (int i = n - 1; i >= 0; --i) {
		remainW[i] = remainW[i + 1] + v[i].first;
		remainValue[i] = remainValue[i + 1] + v[i].second;
	}

	WATCHC(remainW);
	WATCHC(remainValue);

	memset (dp, -1, sizeof dp);

	cout << solve (0, T) << endl;

	return 0;
}
