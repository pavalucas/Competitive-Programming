#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define mt make_tuple
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
	int n, sumAllFirst = 0;
	cin >> n;
	vector<tuple<int, int, int, int>> exam(n);
	rp(i,n) {
		int a, b, c;
		cin >> a >> b >> c;
		int sum = b + c;
		exam[i] = mt(sum, a, b, c);
		sumAllFirst += a;
	}
	sort(all(exam));
	int resp = -1;
	rp(i,n) {
		int cur = sumAllFirst + get<2>(exam[i]) + get<3>(exam[i]);
		resp = max(resp, cur);
		sumAllFirst -= get<1>(exam[i]);
	}
	cout << resp << endl;
	return 0;
}