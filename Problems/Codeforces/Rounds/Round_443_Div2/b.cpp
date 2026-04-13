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
const int N = 501;

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )
int arr[N];
int consecWin[N] = {0};
int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ull k;
	cin >> n >> k;
	rp(i,n) cin >> arr[i];
	rp(i,n) {
		int curPower = arr[i];
		if(curPower != n) {
			rp(j,n){
				if(i > j){
					if(curPower < arr[j]) break;
				}
				else if(i < j) {
					if(curPower > arr[j]) consecWin[i]++;
					else break;
				}
			}
		}
	}
	for(int i = 1; i < n; i++) if(consecWin[i] > 0) consecWin[i]++;
	int resp = n;
	rp(i,n) {
		if(arr[i] == n) break;
		if(k <= consecWin[i]) {
			resp = arr[i];
			break;
		}
	}
	cout << resp << endl;
	return 0;
}
