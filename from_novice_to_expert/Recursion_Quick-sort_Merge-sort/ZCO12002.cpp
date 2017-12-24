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

#define TRACE(x...) x
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

vpi vec(N);
int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	vi ini(x);
	vi end(y);
	rp(i,n) {
		int a, b;
		cin >> a >> b;
		vec[i] = mp(a,b);
	}
	rp(i,x) cin >> ini[i];
	rp(i,y) cin >> end[i];
	
	sort(all(ini));
	sort(all(end));

	int resp = numeric_limits<int>::max();
	rp(i,n) {
		if(vec[i].se - vec[i].fi + 1 >= resp) continue;
		int startTime = -1, endTime = -1;
		auto it1 = ub(all(ini), vec[i].fi);
		if(it1 != ini.begin()) startTime = *(--it1);
		auto it2 = lb(all(end), vec[i].se);
		if(it2 != end.end()) endTime = *it2;
		if(startTime != -1 && endTime != -1) resp = min(resp, endTime - startTime + 1);
	}
	cout << resp << endl;


	return 0;
}
