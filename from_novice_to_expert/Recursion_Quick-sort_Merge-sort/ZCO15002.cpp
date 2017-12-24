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
const int N = 65010;

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi vec(n);
	rp(i,n) {
		cin >> vec[i];
	}
	sort(all(vec));
	int resp = 0;
	rp(i,n) {
		WATCH(vec[i]);
		resp += vec.end() - lower_bound(all(vec), vec[i] + k);
		WATCH(resp);
	}

	cout << resp << endl;
	return 0;
}
