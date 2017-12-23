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
	set<int> allVoters;
	set<int> resp;
	int numVot[3];
	cin >> numVot[0] >> numVot[1] >> numVot[2];
	rp(i,3) {
		rp(j,numVot[i]) {
			int a;
			cin >> a;
			if(allVoters.find(a) != allVoters.end()) resp.insert(a);
			else allVoters.insert(a);
		}
	}
	cout << resp.size() << endl;
	for(auto& p : resp) cout << p << endl;
	return 0;
}
