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

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vi vec(2*n);
	rp(i,n) vec[i] = 0;
	for(int i = n; i < 2*n; i++) vec[i] = 1;
	int ok = true;
	do {
		int count = 0;
		int ok = true;
		rp(i,2*n) {
			if(!vec[i]) {
				count++;
			}
			else {
				count--;
			}
			if(count < 0) ok = false;
		}
		if(ok) {
			rp(i,2*n) {
				if(!vec[i]) cout << "(";
				else cout << ")";
			}
			cout << "\n";
		}
	} while(next_permutation(all(vec)) && ok);
	return 0;
}
