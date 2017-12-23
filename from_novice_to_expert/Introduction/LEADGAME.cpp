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
	int n;
	cin >> n;
	int lead = 0, sc1 = 0, sc2 = 0;
	bool play1;
	rp(i,n){
		int a, b;
		cin >> a >> b;
		sc1 += a; sc2 += b;
		if(sc1 >= sc2) {
			if(lead < sc1-sc2) {
				lead = sc1-sc2;
				play1 = true;
			}
		} else {
			if(lead < sc2-sc1) {
				lead = sc2-sc1;
				play1 = false;
			}
		}
	}

	if(play1) {
		cout << "1 " << lead << endl;
	} else {
		cout << "2 " << lead << endl;
	}
	return 0;
}
