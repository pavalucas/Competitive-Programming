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
const int N = 1e5+5;

ll cache[N];
void fat() {
	cache[0] = 1;
	for(ll i = 1; i < N; ++i) cache[i] = (cache[i - 1] * i)%MOD;
}
int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	fat();
	while(t--) {
		int n;
		cin >> n;
		cout << cache[n] << "\n";
	}
	return 0;
}
