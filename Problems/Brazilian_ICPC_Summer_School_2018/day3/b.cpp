#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F
#define INFLL 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rp(i, n) for(int i=0; i < int(n); i++)

#define contOnes __builtin_popcountl
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define unico(x) x.erase(unique(all(x)), (x).end())

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const double inf = 1.0/0.0;
const double pi = 2 * acos(0.0);

#define TRACE(x...) x
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

#define MAXN 100010

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int f1, a, b, c, m, n;
	cin >> f1 >> a >> b >> c;
	cin >> m >> n;
	map<int, int> comp;
	vii team;
	rp(i,m) {
		rp(j,n) {
			int temp;
			cin >> temp;
			if(comp.find(temp) != comp.end()) comp[temp]++;
			else comp.insert(mp(temp, 1));
		}
	}
	for(auto& p : comp) {
		team.pb(mp(p.se, p.fi));
	}
	vii fi(team.size());
	fi[0] = mp(f1, 0);
	for(int i = 1; i < fi.size(); i++) fi[i] = mp((a*fi[i-1].fi + b) % c + 1, i);
	sort(all(fi));
	sort(all(team));
	vii resp(team.size());
	rp(i, team.size()) resp[i] = mp(fi[i].se, team[i].se);
	sort(all(resp));
	cout << resp.size() << endl;
	rp(i, resp.size()) cout << resp[i].se << " ";
	cout << endl;

	return 0;
}
