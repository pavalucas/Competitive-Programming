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

int box[N];

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, h;
	cin >> n >> h;
	rp(i,n) cin >> box[i];
	int a, pos = 0;
	bool haveBox = false;
	cin >> a;
	while(a != 0) {
		if(a == 1) pos = (pos == 0)? pos : pos - 1;
		if(a == 2) pos = (pos == n-1)? pos : pos + 1;
		if(a == 3) {
			if(!haveBox) {
				if(box[pos] > 0) {
					haveBox = true;
					box[pos]--;
				}
			}
		}
		if(a == 4) {
			if(haveBox) {
				if(box[pos] < h){
					haveBox = false;
					box[pos]++;
				}
			}
		}
		TRACE(rp(i,n) cout << box[i] << " ";
				cout << endl;)
		cin >> a;
	}
	rp(i,n) cout << box[i] << " ";
	cout << endl;
	return 0;
}
