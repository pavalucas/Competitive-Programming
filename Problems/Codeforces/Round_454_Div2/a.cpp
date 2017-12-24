#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define rp(i, n) for(int i=0; i < int(n); i++)
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

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(2*c < d || 2*d < c || 2*d >= 2*b) {
		cout << -1 << endl;
	} else {
		cout << 2*a << endl;
		cout << 2*b << endl;
		cout << max(c,d) << endl;
	}
	return 0;
}
